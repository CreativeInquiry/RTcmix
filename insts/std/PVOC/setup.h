// setup.h

#ifndef _PV_SETUP_H_
#define _PV_SETUP_H_
#ifdef __cplusplus
#include "PVFilter.h"

int profile();
double set_filter(float *, int, double *);
double init_filter(float *, int, double *);

int RegisterFilter(FilterCreateFunction fn);
int GetFilter(PVFilter **ppFilter);
#endif
#endif	/* _PV_SETUP_H_ */
