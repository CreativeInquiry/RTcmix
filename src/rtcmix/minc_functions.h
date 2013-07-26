#ifndef _MINC_FUNCTIONS_H_
#define _MINC_FUNCTIONS_H_

#include <rtcmix_types.h>

#ifdef __cplusplus
extern "C" {
#endif

double m_boost(float p[]);

double m_pchmidi(float p[]);
double m_cpsmidi(float p[]);
double m_octmidi(float p[]);
double m_midipch(float p[]);
double m_cpspch(float p[]);
double m_pchoct(float p[]);
double m_octpch(float p[]);
double m_pchcps(float p[]);
double m_cpsoct(float p[]);
double m_octcps(float p[]);
double m_octlet(float p[], int nargs, double pp[]);
double m_cpslet(float p[], int nargs, double pp[]);
double m_pchlet(float p[], int nargs, double pp[]);
double m_pchadd(float p[], int nargs, double pp[]);

double m_rand();
double m_random();
double m_srand(float p[], int n_args);

double m_time_beat(float p[]);
double m_beat_time(float p[]);

double m_trunc(float p[], int nargs, double pp[]);

double m_ampdb(float p[]);
double m_dbamp(float p[]);

double m_stringify(float p, int n_args, double pp[]);
double m_translen(float p[], int n_args, double pp[]);

double m_log(float p[], int n_args);
double m_ln(float p[], int n_args);
double m_pow(float p[], int n_args, double pp[]);
double m_round(float p[], int n_args);
double m_wrap(float p[], int n_args);

double m_print(float p[], int n_args, double pp[]);

double m_abs(float p[], int n_args);
double m_mod(float p[], int n_args);
double m_max(float p[], int n_args);
double m_min(float p[], int n_args);

double m_exit(float p[], int n_args, double pp[]);

double m_load_array(float p[], int n_args, double pp[]);
double m_get_array(float p[], int n_args);
double m_put_array(float p[], int n_args);

double m_get_sum(float p[], int n_args);
double m_get_size(float p[], int n_args);
double m_getpch(float p[], int n_args, double pp[]);
double m_getamp(float p[], int n_args, double pp[]);

double str_num(float p[], int n_args, double pp[]);

double m_print_is_on(float p[], int n_args);
double m_print_is_off(float p[], int n_args);

double m_get_spray(float p[], int n_args);
double m_spray_init(float p[], int n_args);

double m_setline_size(float p[], int n_args);
double m_setline(float p[], int n_args);
double m_setexp(float p[], int n_args);

double m_reset(float p[], int n_args);
double m_irand(float p[], int n_args, double pp[]);
double m_trand(float p[], int n_args, double pp[]);

//double m_pickrand(const Arg args[], const int nargs);
//double m_pickwrand(const Arg args[], const int nargs);
//double get_time(); // returns number of seconds that have elapsed

#ifdef __cplusplus
}
#endif

#endif
