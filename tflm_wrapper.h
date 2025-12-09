#ifndef TFLM_WRAPPER_H
#define TFLM_WRAPPER_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

bool tflm_init_model(void);
void tflm_infer(float* input, float* output);

#ifdef __cplusplus
}
#endif

#endif
