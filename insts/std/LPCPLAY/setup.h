// setup.h -- decls for Minc utilities

#ifndef _LPCPLAY_SETUP_H_
#define _LPCPLAY_SETUP_H_

#ifdef __cplusplus
extern "C" {
#endif

int profile();
double dataset(float *p, int n_args, double *pp);
double lpcstuff(float *p, int n_args);
double freset(float *p, int n_args);
double setdev(float *p, int n_args);
double setdevfactor(float *p, int n_args);
double set_thresh(float *p, int n_args);
double set_hnfactor(float *p, int n_args);
double use_autocorrect(float *p, int n_args);

#ifdef __cplusplus
}
#endif

#endif	//	 _SETUP_H_
