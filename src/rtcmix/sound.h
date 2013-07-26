#ifndef _SOUND_H_
#define _SOUND_H_

#ifdef __cplusplus
extern "C" {
#endif

double m_open(float *p, short n_args, double *pp);
double peak_off(float p[], int n_args);
double punch_on(float p[], int n_args);
double m_clean(float p[], int n_args);

#ifdef __cplusplus
}
#endif

#endif
