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
        printf(" 3. Ejecutar Simulacion Fisica Hail Mary\n");
        printf(" 4. Mostrar Reporte Final de Telemetria\n");
        printf(" 0. Salir de Control de Lanzamiento\n");

        printf("\n Ingrese una opcion: ");
        opcion = leerOpcion();

        switch (opcion) {
            case 1:
                mostrarBriefing();
                printf("\n[Presione Enter para continuar...]");
                leerOpcion(); 
                break;
case 2:
                ingresarParametros(&misionSLS);
                misionSLS.completada = 0;
                printf("\n  Parametros cargados en el sistema.\n");
                printf("\n[Presione Enter para continuar...]");
                leerOpcion(); 
                break;
            case 3:
                calcularMision(&misionSLS);
                printf("\n[Presione Enter para continuar...]");
                leerOpcion(); 
                break;
            case 4:
                mostrarReporte(misionSLS);
                printf("\n[Presione Enter para continuar...]");
                leerOpcion(); 
                break;
            case 0:
                printf("\n Cerrando enlace con HAIL MARY. ¡Hasta la proxima mision, comandante!\n");
                break;
            default:
                printf("\n Opcion no reconocida. Ingrese un numero entre 0 y 4.\n");
                printf("\n[Presione Enter para continuar...]");
                leerOpcion(); 
        }
    } while (opcion != 0);

    return 0;
}
