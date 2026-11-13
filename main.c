#include <stdio.h>
#include "artemis.h"
#include "validaciones.h"

int main(void) {
    Mision misionSLS = {0};
    int opcion;

    do {
        mostrarPresentacion();
        printf("\n 1. Consultar Briefing de Mision\n");
        printf(" 2. Ingresar Parametros de Propulsion (v0, y0, a1, t1, a2, h, g)\n");
        printf(" 3. Ejecutar Simulacion Fisica SLS/Orion\n");
        printf(" 4. Mostrar Reporte Final de Telemetria\n");
        printf(" 0. Salir de Control de Lanzamiento\n");

        printf("\n Ingrese una opcion: ");
        opcion = leerOpcion();

        switch (opcion) {
            case 1:
                mostrarBriefing();
                printf("\n[Presione Enter para continuar...]");
                leerOpcion(); // Pausa para leer
                break;
