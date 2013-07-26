#ifndef _MOVE_PATH_H_
#define _MOVE_PATH_H_

#ifdef __cplusplus
extern "C" {
#endif

int get_path_params(double *rhos, double *thetas, int *cartesian, double *mdiff);

double path (float p[], int n_args);
double cpath (float p[], int n_args);
double param (float p[], int n_args);
double cparam (float p[], int n_args);
double threshold(float p[], int n_args);

#ifdef __cplusplus
}
#endif

#endif
