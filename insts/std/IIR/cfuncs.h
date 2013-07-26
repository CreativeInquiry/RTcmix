#define MAXFILTER 64

#ifdef __cplusplus
extern "C" {
#endif

int get_iir_filter_specs(float cf[MAXFILTER], float bw[MAXFILTER],
                                                        float amp[MAXFILTER]);

														
double IIR_setup(float p[], int n_args);

#ifdef __cplusplus
} /* extern "C" */
#endif

