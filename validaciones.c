#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"

int leerOpcion(void) {
    char linea[100];
    char *fin;
    long valor;

    // Leer línea completa de la consola de forma segura
    if (fgets(linea, sizeof(linea), stdin) == NULL) {
        return -1;
    }

    // Remover el salto de línea al final si existe
    size_t len = strlen(linea);
    if (len > 0 && linea[len - 1] == '\n') {
        linea[len - 1] = '\0';
    }

    // Si el usuario solo presiona Enter, retornar -1 para evitar lecturas vacías
    if (linea[0] == '\0') {
        return -1;
    }

    // Conversión segura a entero con strtol
    valor = strtol(linea, &fin, 10);

    // Verificar que toda la cadena ingresada sea un número válido
    if (*fin != '\0') {
        return -1;
    }

    return (int)valor;
}

double leerDouble(const char *mensaje) {
    double valor;
    int resultado;

    while (1) {
        printf("%s", mensaje);
        resultado = scanf("%lf", &valor);

        // Limpieza completa del búfer de entrada para evitar saltos de línea pendientes
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}

        if (resultado == 1) {
            return valor;
        } else {
            printf(" [!] Error de Telemetria: Entrada invalida. Ingrese un valor numerico real.\n");
        }
    }
}
