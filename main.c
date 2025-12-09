#include <stdio.h>
#include "pico/stdlib.h"
#include "tflm_wrapper.h"
#include "wine_dataset.h"
#include "wine_normalization.h"

#define NUM_CLASSES 3

const char* class_names[NUM_CLASSES] = {"Classe_0", "Classe_1", "Classe_2"};

int main() {
    stdio_init_all();
    sleep_ms(3000);
    
    printf("\n========================================\n");
    printf("   TINYML - CLASSIFICACAO DE VINHOS\n");
    printf("========================================\n");
    printf("Amostras: %d\n", NUM_SAMPLES);
    printf("========================================\n\n");

    if (!tflm_init_model()) {
        printf("ERRO: Nao consegui carregar o modelo!\n");
        return -1;
    }

    printf("\nIniciando testes...\n\n");

    int confusion_matrix[NUM_CLASSES][NUM_CLASSES] = {0};
    int acertos = 0;

    for (int i = 0; i < NUM_SAMPLES; i++) {
        float input_norm[NUM_FEATURES];
        float output[NUM_CLASSES];

        for (int j = 0; j < NUM_FEATURES; j++) {
            input_norm[j] = (wine_features[i][j] - wine_means[j]) / wine_stds[j];
        }

        tflm_infer(input_norm, output);

        int predicted = 0;
        float max_prob = output[0];
        for (int k = 1; k < NUM_CLASSES; k++) {
            if (output[k] > max_prob) {
                max_prob = output[k];
                predicted = k;
            }
        }

        int real = wine_labels[i];
        confusion_matrix[real][predicted]++;

        if (predicted == real) acertos++;

        printf("Amostra %2d: Real=%s, Predito=%s [%.2f] %s\n",
               i, class_names[real], class_names[predicted], max_prob,
               (predicted == real) ? "OK" : "ERRO");
        
        sleep_ms(100);
    }

    printf("\n========================================\n");
    printf("   RESULTADOS\n");
    printf("========================================\n\n");

    printf("MATRIZ DE CONFUSAO:\n");
    printf("        Pred0  Pred1  Pred2\n");
    for (int i = 0; i < NUM_CLASSES; i++) {
        printf("Real%d |", i);
        for (int j = 0; j < NUM_CLASSES; j++) {
            printf("  %2d  ", confusion_matrix[i][j]);
        }
        printf("\n");
    }

    float acuracia = ((float)acertos / NUM_SAMPLES) * 100.0f;
    printf("\nACURACIA: %d/%d = %.1f%%\n", acertos, NUM_SAMPLES, acuracia);
    printf("\n========================================\n");

    while (1) {
        tight_loop_contents();
    }
}