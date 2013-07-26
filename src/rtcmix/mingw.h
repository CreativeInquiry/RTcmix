// POSIX compatibility for MinGW on Windows, largely from
// http://www.ualberta.ca/dept/aict/uts/software/openbsd/ports/4.6/i386/obj/git-1.7.0/git-1.7.0/compat/mingw.h
// http://www.ualberta.ca/dept/aict/uts/software/openbsd/ports/4.6/i386/obj/git-1.7.0/git-1.7.0/compat/mingw.c
#ifndef _MINGW_H_
#define _MINGW_H_

#ifdef MINGW

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#include <sys/time.h>
#include <errno.h>
//#include <sys/timeb.h>

#define S_IFLNK    0120000 /* Symbolic link */
#define S_ISLNK(x) (((x) & S_IFMT) == S_IFLNK)
	
#define SIGHUP 1
#define SIGQUIT 3
#define SIGKILL 9
#define SIGPIPE 13
#define SIGALRM 14
#define SIGCHLD 17

struct itimerval {
	struct timeval it_value, it_interval;
};

#define ITIMER_REAL 0

typedef void (__cdecl *sig_handler_t)(int);

static inline int is_timeval_eq(const struct timeval *i1, const struct timeval *i2);

int getitimer(int type, struct itimerval *cur);
int setitimer(int type, struct itimerval *in, struct itimerval *out);

int mkstemp(char *temp);

// sys/times.h replacement

/* Structure describing CPU time used by a process and its children.  */
struct tms
  {
    clock_t tms_utime;          /* User CPU time.  */
    clock_t tms_stime;          /* System CPU time.  */

    clock_t tms_cutime;         /* User CPU time of dead children.  */
    clock_t tms_cstime;         /* System CPU time of dead children.  */
  };

/* Store the CPU time used by this process and all its
   dead children (and their dead children) in BUFFER.
   Return the elapsed real time, or (clock_t) -1 for errors.
   All times are in CLK_TCKths of a second.  */
clock_t times (struct tms *__buffer);

// from http://tech.groups.yahoo.com/group/mingw32/message/1345
int fsync(int fd);

#endif

#endif // _MINGW_H_