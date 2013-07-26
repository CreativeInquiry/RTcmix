#ifndef _MOVE_SETUP_H_
#define _MOVE_SETUP_H_

#ifdef __cplusplus
extern "C" {
#endif

int get_setup_params(double [], double [12][12], float *, float *, int *,
                                                         double *, double *);

double space(float p[], int n_args);
double mikes(float p[], int n_args);
double mikes_off(float p[], int n_args);
double oldmatrix(float p[], int n_args);
double matrix(float p[], int n_args);

#ifdef __cplusplus
}
#endif

#endif
