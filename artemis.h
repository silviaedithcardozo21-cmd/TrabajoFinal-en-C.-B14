#ifndef ARTEMIS_H
#define ARTEMIS_H

/**
 * @file artemis.h
 * @brief Módulo de Lógica de Negocio y Simulación Física Artemis.
 * Definición de constantes, estructuras de datos y prototipos de funciones.
 */

#define MAX_ETAPAS 3


typedef struct {
    double velocidadInicial; // v0 (m/s)
    double alturaInicial;    // y0 (m)
    double aceleracion1;     // a1 (m/s^2) - Fase 1 (Motores + SRB)
    double tiempo1;          // t1 (s)     - Tiempo desacople SRB
    double aceleracion2;     // a2 (m/s^2) - Fase 2 (Núcleo Principal)
    double alturaApagado;    // h (m)      - Altitud de corte de motores
    double gravedad;         // g (m/s^2)  - Aceleración de la gravedad
} Parametros;


typedef struct {
    double v1;           // Rapidez al desacople SRB (m/s)
    double y1;           // Altitud alcanzada al desacople SRB (m)
    double v2;           // Rapidez máxima al apagar motores (m/s)
    double hmax;         // Altitud máxima alcanzada en caída libre (m)
    double aceleracionG; // Carga de aceleración máxima en múltiplos de g
} Resultados;

// Estructura de historial por etapa de vuelo
typedef struct {
    char nombre[40];
    double velocidad;
    double altura;
} Etapa;

// Estructura contenedora del estado global de la Misión
typedef struct {
    Parametros datos;
    Resultados resultados;
    Etapa historial[MAX_ETAPAS];
    int completada;
} Mision;

// Prototipos de funciones públicas de simulación
void mostrarPresentacion(void);
void mostrarBriefing(void);
void ingresarParametros(Mision *m);
int validarParametros(Parametros p);
void calcularMision(Mision *m);
void mostrarReporte(Mision m);

#endif // ARTEMIS_H
