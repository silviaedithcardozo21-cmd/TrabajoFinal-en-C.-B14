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
