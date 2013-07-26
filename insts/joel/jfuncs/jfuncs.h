#ifndef _JFUNCS_H_
#define _JFUNCS_H_

#ifdef __cplusplus
extern "C" {
#endif

double m_sin(float p[], int n_args, double pp[]);
double m_cos(float p[], int n_args, double pp[]);
double m_lowrand();
double m_highrand();
double m_trirand();
double m_constrain(float p[], int n_args, double pp[]);
double m_map(float p[], int n_args, double pp[]);
double m_gaussrand (float p[], int n_args, double pp[]);
double m_prob (float p[], int n_args, double pp[]);

#ifdef __cplusplus
}
#endif

#endif	// _JFUNCS_H_

