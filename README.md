# Proyecto Final – Inteligencia Artificial  
**Universidad del Norte – 2025**

Este repositorio contiene el desarrollo completo del Proyecto Final de la asignatura **Inteligencia Artificial**, incluyendo:

- Análisis exploratorio y modelado en **Python**
- Implementación de algoritmos supervisados y no supervisados
- Reducción de dimensionalidad (PCA)
- Clustering (K-means)
- Modelos de clasificación (Regresión Logística y Random Forest)
- Implementación de un algoritmo supervisado desde cero en **lenguaje C**
- Evaluación y comparación de resultados

---

#  Estructura del repositorio


---

#  Dataset utilizado

Se utilizó el dataset de criptomonedas disponible en Kaggle:

**Cryptocurrency Historical Market Data**  
Fuente: https://www.kaggle.com/datasets/sudalairajkumar/cryptocurrencypricehistory

La descarga del dataset se realiza directamente en el notebook usando `kagglehub`.

---

#  Modelos implementados en Python

En el notebook se desarrollan:

### ✔ Análisis Exploratorio (EDA)
- Limpieza
- Outliers
- Estadísticas descriptivas

### ✔ Preprocesamiento
- One hot encoding
- Normalización (StandardScaler)
- División Train/Test

### ✔ Reducción de dimensionalidad
- PCA (2 componentes)

### ✔ Aprendizaje No Supervisado
- K-Means (incluye método del codo)
- Visualización en PCA
- Matriz cluster vs. target

### ✔ Aprendizaje Supervisado
- Regresión Logística
- Random Forest
- Métricas: accuracy, recall, precision, F1-score
- Validación cruzada (Cross-validation)
- GridSearch para hiperparámetros
- Importancia de características
- Matrices de confusión graficadas

---

#  Implementación en C — Algoritmo Supervisado (KNN)

Para cumplir con los requisitos del proyecto, se implementó desde cero el algoritmo **K-Nearest Neighbors (KNN)** usando únicamente el estándar del lenguaje C.

### Archivos:
- `knn.h`: definición del struct `Sample`, constantes y prototipos
- `knn.c`: funciones `distance_euclidean()` y `knn_predict()`
- `main.c`: generación de dataset, evaluación con leave-one-out, cálculo de accuracy

### Funcionalidades:
- Clasificación binaria (sube / baja)
- Cálculo de distancia euclidiana
- Ordenamiento de vecinos
- Selección de K vecinos más cercanos
- Exactitud (%) con leave-one-out

---

#  Cómo compilar y ejecutar el programa en C

Desde la carpeta `src-c/`:

```bash
gcc main.c knn.c -o knn -lm
