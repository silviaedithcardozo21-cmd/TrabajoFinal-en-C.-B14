#include <stdio.h>
#include <string.h>
#include <math.h>
#include "artemis.h"
#include "validaciones.h"

void mostrarPresentacion(void) {
    printf("\n");
    printf("=============================================================\n");
    printf("      PROJECT HAIL MARY - CONTROL ERIDIANO    \n");
    printf("   Ryland Grace & Rocky • Telemetria Astrofago         \n");
    printf("=============================================================\n");
}

void mostrarBriefing(void) {
    printf("\n==================== BRIEFING DE MISION ====================\n");
    printf(" • Nivel 1: Plataforma LC-39B (Partida v0=0 m/s, y0=0 m).\n");
    printf(" • Nivel 2: Impulso inicial con motores RS-25 y SRBs (a1).\n");
    printf(" • Nivel 3: Desacople limpio de cohetes SRB a t = t1.\n");
    printf(" • Nivel 4: Ascenso secundario solo con nucleo principal (a2).\n");
    printf(" • Nivel 5: Apagado de motores a altitud h y fase de caida libre.\n");
    printf(" • Nivel 6: Evaluacion de carga G soportada por la tripulacion.\n");
    printf("============================================================\n");
}

int validarParametros(Parametros p) {
    // Comprobación de valores infinitos o indefiniciones numéricas (NaN)
    if (!isfinite(p.velocidadInicial) || !isfinite(p.alturaInicial) ||
        !isfinite(p.aceleracion1) || !isfinite(p.tiempo1) ||
        !isfinite(p.aceleracion2) || !isfinite(p.alturaApagado) ||
        !isfinite(p.gravedad)) {
        return 0;
    }
  
 // Comprobaciones de rango físico admisibles
    if (p.velocidadInicial < 0 || p.aceleracion1 <= 0 || p.tiempo1 <= 0 ||
        p.aceleracion2 <= 0 || p.gravedad <= 0 || p.alturaApagado < p.alturaInicial) {
        return 0;
    }

    return 1;
}

void ingresarParametros(Mision *m) {
    Parametros *p = &m->datos;

    printf("\n==== INGRESO DE PARAMETROS DE VUELO ARTEMIS ====\n");
    p->velocidadInicial = leerDouble(" Velocidad inicial v0 (m/s): ");
    p->alturaInicial    = leerDouble(" Altura inicial y0 (m): ");
    p->aceleracion1     = leerDouble(" Aceleracion Fase 1 a1 (m/s^2): ");
    p->tiempo1          = leerDouble("  Tiempo hasta desacople t1 (s): ");
    p->aceleracion2     = leerDouble(" Aceleracion Fase 2 a2 (m/s^2): ");
    p->alturaApagado    = leerDouble(" Altitud de apagado h (m): ");
    p->gravedad         = leerDouble(" Gravedad terrestre g (m/s^2): ");
}

void calcularMision(Mision *m) {
    Parametros p = m->datos;
    Resultados *r = &m->resultados;
    double distanciaFase2;

    if (!validarParametros(p)) {
        printf("\n  ERROR DE SIMULACION: Parametros fisicamente incoherentes o fuera de rango.\n");
        return;
    }

    // a. Rapidez (v1) y altitud (y1) al desacople SRB (Fase 1: MRUV)
    r->v1 = p.velocidadInicial + p.aceleracion1 * p.tiempo1;
    r->y1 = p.alturaInicial + (p.velocidadInicial * p.tiempo1) +
            (0.5 * p.aceleracion1 * p.tiempo1 * p.tiempo1);

    // Validacion de viabilidad para la Fase 2
    if (p.alturaApagado < r->y1) {
        printf("\n  ERROR TACTICO: La altitud de apagado (%.2f m) es menor a la alcanzada en desacople (%.2f m).\n",
               p.alturaApagado, r->y1);
        return;
    }

    // b. Rapidez maxima (v2) al apagar motores a altitud h (Fase 2: MRUV sin tiempo explicito)
    distanciaFase2 = p.alturaApagado - r->y1;
    r->v2 = sqrt((r->v1 * r->v1) + (2.0 * p.aceleracion2 * distanciaFase2));

    // c. Altura maxima alcanzada (hmax) en caida libre (Fase 3: MRUV con a = -g hasta v=0)
    r->hmax = p.alturaApagado + ((r->v2 * r->v2) / (2.0 * p.gravedad));

    // d. Aceleracion maxima experimentada expresada en multiplos de g
    r->aceleracionG = p.aceleracion1 / p.gravedad;

    // Guardado en bitacora por etapas
    strcpy(m->historial[0].nombre, "Desacople SRB (T+120s)");
    m->historial[0].velocidad = r->v1;
    m->historial[0].altura = r->y1;

    strcpy(m->historial[1].nombre, "Apagado Core Stage (h)");
    m->historial[1].velocidad = r->v2;
    m->historial[1].altura = p.alturaApagado;

    strcpy(m->historial[2].nombre, "Apogeo en Caída Libre");
    m->historial[2].velocidad = 0.0;
    m->historial[2].altura = r->hmax;

    m->completada = 1;

    printf("\n ¡CALCULOS DE SIMULACION FINALIZADOS EXITOSAMENTE!\n");
}
