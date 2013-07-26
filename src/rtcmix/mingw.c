#include "mingw.h"

#ifdef MINGW

#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <assert.h>
#include <process.h>    /* _beginthread, _endthread */

static HANDLE timer_event;
static HANDLE timer_thread;
static int timer_interval;
static int one_shot;
static sig_handler_t timer_fn = SIG_DFL;

/* The timer works like this:
 * The thread, ticktack(), is a trivial routine that most of the time
 * only waits to receive the signal to terminate. The main thread tells
 * the thread to terminate by setting the timer_event to the signalled
 * state.
 * But ticktack() interrupts the wait state after the timer's interval
 * length to call the signal handler.
 */

static unsigned __stdcall ticktack(void *dummy) {
	while (WaitForSingleObject(timer_event, timer_interval) == WAIT_TIMEOUT) {
		if (timer_fn == SIG_DFL)
			assert(0); // maybe not the best idea?
		if (timer_fn != SIG_IGN)
			timer_fn(SIGALRM);
		if (one_shot)
			break;
	}
	return 0;
}

static int start_timer_thread(void) {
	timer_event = CreateEvent(NULL, FALSE, FALSE, NULL);
	if (timer_event) {
		timer_thread = (HANDLE) _beginthreadex(NULL, 0, ticktack, NULL, 0, NULL);
		if (!timer_thread )
			return errno = ENOMEM;
	} else
		return errno = ENOMEM;
	return 0;
}

static void stop_timer_thread(void) {
	if (timer_event)
		SetEvent(timer_event);	/* tell thread to terminate */
	if (timer_thread) {
		int rc = WaitForSingleObject(timer_thread, 1000);
		CloseHandle(timer_thread);
	}
	if (timer_event)
		CloseHandle(timer_event);
	timer_event = NULL;
	timer_thread = NULL;
}

static inline int is_timeval_eq(const struct timeval *i1, const struct timeval *i2) {
	return i1->tv_sec == i2->tv_sec && i1->tv_usec == i2->tv_usec;
}

// type is ignored
int getitimer(int type, struct itimerval *cur) {
	// not implemented yet...
	//cur->it_internal = 
	//cur->it_value =
	return 0;
}

// type is ignored
int setitimer(int type, struct itimerval *in, struct itimerval *out) {
	static const struct timeval zero;
	static int atexit_done;

	if (out != NULL)
		return errno = EINVAL;
	if (!is_timeval_eq(&in->it_interval, &zero) &&
	    !is_timeval_eq(&in->it_interval, &in->it_value))
		return errno = EINVAL;

	if (timer_thread)
		stop_timer_thread();

	if (is_timeval_eq(&in->it_value, &zero) &&
	    is_timeval_eq(&in->it_interval, &zero))
		return 0;

	timer_interval = in->it_value.tv_sec * 1000 + in->it_value.tv_usec / 1000;
	one_shot = is_timeval_eq(&in->it_interval, &zero);
	if (!atexit_done) {
		atexit(stop_timer_thread);
		atexit_done = 1;
	}
	return start_timer_thread();
}

int mkstemp(char *temp) {
	char *filename = mktemp(temp);
	if (filename == NULL)
		return -1;
	return open(filename, O_RDWR | O_CREAT, 0600);
}

static FILETIME times_ft[6];

// implemented following http://linux.die.net/man/2/times
clock_t times(struct tms *__buffer) {
	
	// http://msdn.microsoft.com/en-us/library/windows/desktop/ms683223(v=vs.85).aspx
	ULARGE_INTEGER ft[4];
	GetProcessTimes(GetCurrentProcess(),
		(LPFILETIME) &ft[0], // process creation time
		(LPFILETIME) &ft[1], // process exit time
		(LPFILETIME) &ft[2], // process time in kernel mode (100 nanosecond units)
		(LPFILETIME) &ft[3]); // process time in user mode (100 nanosecond units)
	
	// convert 100 ns units to # clock ticks using
	// 10,000,000 ns units in 1 sec % CLOCKS_PER_SEC
	__buffer->tms_utime = (ft[2].QuadPart * CLOCKS_PER_SEC) / 10000000; // User CPU time
	__buffer->tms_stime = (ft[3].QuadPart * CLOCKS_PER_SEC) / 10000000;  // System CPU time
	
	// should probably set these with something?
	__buffer->tms_cutime = 0; // User CPU time of dead children
	__buffer->tms_cstime = 0; // System CPU time of dead children

	// http://www.decompile.com/cpp/faq/windows_timer_api.htm
	// get elapsed time since system start
	PLARGE_INTEGER ticks;
	if(QueryPerformanceCounter(ticks) != 0) {
		return 0;
	}
	return ticks->QuadPart;
}

int fsync(int fd) {
  return (FlushFileBuffers ((HANDLE) _get_osfhandle (fd))) ? 0 : -1;
}

#endif // MINGW
