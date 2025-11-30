#ifndef KNN_H
#define KNN_H

#define FEATURES 4       // Número de características por muestra
#define MAX_SAMPLES 100  // Tamaño máximo del subconjunto
#define K 3              // Número de vecinos

// Estructura que representa una muestra del dataset
typedef struct {
    float x[FEATURES];   // Vector de características
    int label;           // Etiqueta: 0 = baja, 1 = sube
} Sample;

/**
 * Calcula la distancia euclidiana entre dos vectores de características.
 */
float distance_euclidean(const float a[], const float b[]);

/**
 * Clasifica una muestra query usando el algoritmo K-NN.
 *  - dataset: arreglo de muestras etiquetadas
 *  - n_samples: número de muestras en el dataset
 *  - query: muestra a clasificar
 *  - k: número de vecinos a considerar
 *
 * Retorna: etiqueta predicha (0 o 1)
 */
int knn_predict(const Sample *dataset, int n_samples, Sample query, int k);

#endif
