#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "knn.h"

/**
 * Genera un dataset sintético muy simple:
 *  - 4 características en el rango [0, 10)
 *  - etiqueta 0 o 1
 */
void generate_dataset(Sample *dataset, int n_samples) {
    for (int i = 0; i < n_samples; i++) {
        for (int j = 0; j < FEATURES; j++) {
            dataset[i].x[j] = (float)(rand() % 1000) / 100.0f; // 0.00 - 9.99
        }
        dataset[i].label = rand() % 2; // 0 o 1
    }
}

int main() {
    // Semilla para números aleatorios
    srand((unsigned int)time(NULL));

    Sample dataset[MAX_SAMPLES];
    int n_samples = MAX_SAMPLES;

    // 1. Generar un subconjunto reducido
    generate_dataset(dataset, n_samples);

    // 2. Evaluar el modelo usando leave-one-out
    int correct = 0;

    for (int i = 0; i < n_samples; i++) {
        Sample query = dataset[i];

        // Construimos un dataset sin el elemento i
        Sample reduced[MAX_SAMPLES];
        int idx = 0;
        for (int j = 0; j < n_samples; j++) {
            if (j == i) continue;
            reduced[idx++] = dataset[j];
        }

        int pred = knn_predict(reduced, n_samples - 1, query, K);

        if (pred == query.label) {
            correct++;
        }
    }

    float accuracy = (correct * 100.0f) / n_samples;

    printf("============================================\n");
    printf("  Modelo K-NN implementado en C\n");
    printf("  Nº muestras: %d | FEATURES: %d | K = %d\n", n_samples, FEATURES, K);
    printf("  Exactitud (leave-one-out): %.2f%%\n", accuracy);
    printf("============================================\n");

    // 3. Ejemplo de predicción individual
    Sample example = {{7.5f, 8.2f, 6.1f, 9.0f}, 0};
    int example_pred = knn_predict(dataset, n_samples, example, K);
    printf("Predicción para la muestra de ejemplo: %d\n", example_pred);

    return 0;
}
