#include "tflm_wrapper.h"
#include "wine_model_tinyml.h"
#include "tensorflow/lite/micro/micro_mutable_op_resolver.h"
#include "tensorflow/lite/micro/micro_interpreter.h"
#include "tensorflow/lite/micro/system_setup.h"
#include "tensorflow/lite/schema/schema_generated.h"
#include <cstdio>

namespace {
    const tflite::Model* model = nullptr;
    tflite::MicroInterpreter* interpreter = nullptr;
    TfLiteTensor* input_tensor = nullptr;
    TfLiteTensor* output_tensor = nullptr;
    constexpr int kTensorArenaSize = 20 * 1024;
    alignas(16) uint8_t tensor_arena[kTensorArenaSize];
}

extern "C" bool tflm_init_model(void) {
    model = tflite::GetModel(wine_mlp_float_tflite);
    if (model->version() != TFLITE_SCHEMA_VERSION) {
        printf("Erro: versao incompativel!\n");
        return false;
    }

    static tflite::MicroMutableOpResolver<3> resolver;
    resolver.AddFullyConnected();
    resolver.AddRelu();
    resolver.AddSoftmax();

    static tflite::MicroInterpreter static_interpreter(
        model, resolver, tensor_arena, kTensorArenaSize
    );
    interpreter = &static_interpreter;

    if (interpreter->AllocateTensors() != kTfLiteOk) {
        printf("Erro ao alocar tensores!\n");
        return false;
    }

    input_tensor = interpreter->input(0);
    output_tensor = interpreter->output(0);

    printf("Modelo carregado com sucesso!\n");
    return true;
}

extern "C" void tflm_infer(float* input, float* output) {
    for (int i = 0; i < 13; i++) {
        input_tensor->data.f[i] = input[i];
    }
    
    interpreter->Invoke();
    
    for (int i = 0; i < 3; i++) {
        output[i] = output_tensor->data.f[i];
    }
}
