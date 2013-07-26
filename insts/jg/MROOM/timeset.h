#ifndef _TIMESET_H_
#define _TIMESET_H_

#ifdef __cplusplus
extern "C" {
#endif

#define TIME_ARRAY_SIZE  100
#define POS_ARRAY_SIZE   512

int get_timeset(float [], float [], float []);

double timeset(float p[], int n_args);

#ifdef __cplusplus
}
#endif

#endif
