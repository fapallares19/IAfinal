#include <math.h>
#include "knn.h"

/**
 * Calcula la distancia euclidiana entre dos vectores de características.
 */
float distance_euclidean(const float a[], const float b[]) {
    float sum = 0.0f;
    for (int i = 0; i < FEATURES; i++) {
        float diff = a[i] - b[i];
        sum += diff * diff;
    }
    return sqrtf(sum);
}

/**
 * Implementación básica de K-NN.
 * Se usan arreglos auxiliares para almacenar distancias y etiquetas
 * y un bubble sort sencillo para ordenar las distancias.
 */
int knn_predict(const Sample *dataset, int n_samples, Sample query, int k) {
    float dist[MAX_SAMPLES];
    int labels[MAX_SAMPLES];

    // 1. Calcular distancias entre query y cada muestra del dataset
    for (int i = 0; i < n_samples; i++) {
        dist[i] = distance_euclidean(query.x, dataset[i].x);
        labels[i] = dataset[i].label;
    }

    // 2. Ordenar por distancia (bubble sort simple)
    for (int i = 0; i < n_samples - 1; i++) {
        for (int j = 0; j < n_samples - i - 1; j++) {
            if (dist[j] > dist[j + 1]) {
                // intercambiar distancias
                float tmpD = dist[j];
                dist[j] = dist[j + 1];
                dist[j + 1] = tmpD;

                // intercambiar etiquetas para mantener correspondencia
                int tmpL = labels[j];
                labels[j] = labels[j + 1];
                labels[j + 1] = tmpL;
            }
        }
    }

    // 3. Votación entre los K vecinos más cercanos
    int count0 = 0;
    int count1 = 0;
    for (int i = 0; i < k; i++) {
        if (labels[i] == 0) count0++;
        else count1++;
    }

    // 4. Devolver clase mayoritaria
    return (count1 > count0) ? 1 : 0;
}
