#ifndef _TUNING_H_
#define _TUNING_H_

#ifdef __cplusplus
extern "C" {
#endif

double m_eqtemp(float p[], int n_args, double pp[]);
double m_create_scale(float p[], int n_args, double pp[]);
double m_myscale(float p[], int n_args, double pp[]);
double m_diapason(float p[], int n_args, double pp[]);
double m_partch(float p[], int n_args, double pp[]);
double m_young(float p[], int n_args, double pp[]);
double m_just(float p[], int n_args, double pp[]);
double m_pythag(float p[], int n_args, double pp[]);
double m_mean(float p[], int n_args, double pp[]);

#ifdef __cplusplus
}
#endif

#endif	// _TUNING_H_

