# 🛸 PROJECT HAIL MARY / ARTEMIS SLS
## Consola Eridiana de Telemetría 🚀
### Telemetría de propulsión y trayectoria – Centro de Control de Misión

**Universidad:** Universidad Tecnológica Nacional – Facultad Regional Resistencia  
**Cátedra:** Algoritmos y Estructuras de Datos  
**Proyecto:** Trabajo Práctico Integrador Final – Simulador de Misiones Artemis / Consola Eridiana  
**Grupo:** B14

### 👨‍🚀 Tripulación de la misión

- **Cardozo Silvia Edith 46515526**
- **Ferreira Florencia Milagros 47932733**
- **Inglant Facundo Agustín 47620067**

---

## 🛰️ 1. Descripción de la interfaz y escenario

Bienvenidos a la **Consola Eridiana de Control**, un sistema de simulación inspirado en el universo de *Project Hail Mary*.

En esta misión, la tripulación deberá supervisar los parámetros de vuelo de un cohete **Space Launch System (SLS)**, analizar sus fases de propulsión y calcular su trayectoria mediante herramientas de telemetría.

Al igual que en una misión espacial de supervivencia, cada cálculo es importante: los datos deben ser ingresados correctamente y los resultados deben analizarse antes de continuar con la siguiente etapa.

El programa simula el ascenso del cohete utilizando las ecuaciones del **Movimiento Rectilíneo Uniformemente Variado (MRUV)** y el movimiento vertical bajo la acción de la gravedad.

### 🚀 2. Etapas de la misión

**Nivel 1 – Plataforma LC-39B: Preparación inicial**

La nave se encuentra en la plataforma de lanzamiento. Se establecen las condiciones iniciales de velocidad y altura:

- Velocidad inicial: (v_0 = 0.0 {m/s})
- Altura inicial: (y_0 = 0.0{m})

**Nivel 2 – Despegue e impulso SRB**

Comienza el ascenso del cohete mediante la primera fase de propulsión. Se utiliza una aceleración inicial de referencia de (a_1 = 20.0{m/s}^2).

**Nivel 3 – Desacople de los tanques SRB**

Al cumplirse el tiempo de referencia (t_1 = 120.0{s}), se registra la velocidad (v_1) y la altura (y_1) alcanzadas por el cohete.

**Nivel 4 – Ascenso principal Core Stage**

La nave continúa su trayectoria mediante la segunda fase de propulsión, con una aceleración de referencia (a_2 = 12.5 {m/s}^2), hasta alcanzar la altitud de referencia de MECO:

[
h = 160.000 {m}
]

**Nivel 5 – Apagado de motores MECO y ascenso por inercia**

Se simula el apagado de los motores. A partir de ese momento, el cohete continúa ascendiendo por inercia, bajo la acción de la gravedad terrestre, cuyo valor de referencia es:

[
g = 9.80 {m/s}^2
]

**Nivel 6 – Apogeo y análisis de aceleración**

La consola determina la altura máxima alcanzada por el cohete antes de comenzar su descenso y expresa la aceleración de la primera fase como múltiplo de la gravedad terrestre.

> Los valores indicados son parámetros de referencia para la simulación. Cuando corresponda, el usuario podrá ingresar distintos valores para analizar diferentes escenarios. La ambientación de *Project Hail Mary* es narrativa; los cálculos responden al escenario físico SLS/Orion planteado en la consigna.

---

## 🧮 3. Objetivos de análisis y cálculo

La Consola Eridiana debe permitir responder las siguientes preguntas a partir de los valores ingresados por el usuario:

1. ¿Qué velocidad y altura alcanza el cohete al momento de la separación de los SRB?
2. ¿Cuál es la velocidad máxima alcanzada al momento del apagado de motores MECO?
3. Si los motores se apagan a la altitud establecida, ¿qué altura máxima alcanza el cohete por inercia antes de comenzar a descender?
4. ¿Cuántas veces mayor es la aceleración de la primera fase respecto de la gravedad terrestre?

Los resultados se presentan mediante un informe de telemetría que permite comparar los distintos escenarios de lanzamiento.

---

## 📡 4. Sistema de telemetría

Al finalizar la simulación, el sistema podrá mostrar:

- Velocidad alcanzada durante la separación de los SRB.
- Altitud registrada al finalizar la primera fase.
- Velocidad al momento del apagado de motores MECO.
- Altura máxima o apogeo de la trayectoria.
- Aceleración de la primera fase expresada en múltiplos de \(g\).
- Registro de los datos de cada misión simulada.

---

## 🧠 5. Contenidos de Algoritmos y Estructuras de Datos

El desarrollo integra los principales contenidos trabajados durante la cursada:

- Variables y constantes.
- Tipos de datos y operadores.
- Estructuras condicionales.
- Estructuras repetitivas.
- Funciones y modularización.
- Arreglos y registros (`struct`).
- Punteros.
- Validación de datos ingresados por el usuario.
- Resolución de problemas mediante algoritmos.
- Prueba de escritorio y verificación de resultados.

---

## 🧩 6. Organización modular del programa

| Archivo | Responsabilidad |
|---|---|
| `main.c` | Menú principal y coordinación del programa. |
| `artemis.h` | Declaraciones de estructuras y funciones. |
| `artemis.c` | Simulación de las etapas y cálculos físicos. |
| `validaciones.h` | Declaraciones de funciones de validación. |
| `validaciones.c` | Control y validación de entradas. |
| `Makefile` | Automatización de la compilación. |

---

## 💻 7. Tecnologías utilizadas

- Lenguaje C.
- Compilador GCC.
- Make.
- Git y GitHub.

---

### 💻 ¿Cómo compilar y ejecutar el programa?

Si tenés instalado Make, simplemente abrís la terminal en la carpeta del proyecto y escribís:

```bash
make
```

También podés compilarlo directamente con GCC usando este comando:

```bash
gcc main.c artemis.c validaciones.c -o artemis -lm
```

Una vez compilado, solo queda ejecutar el programa:

- **En Linux o macOS:** escribí `./artemis` en la terminal.
- **En Windows:** ejecutá `./artemis.exe`.

¡Y listo! Ya podés ingresar a la Consola Eridiana y comenzar la misión 🚀

---

## 🤖 10. Uso de herramientas de Inteligencia Artificial

Se utilizaron herramientas de inteligencia artificial como apoyo para comprender conceptos, analizar fórmulas físicas y organizar la estructura del proyecto.

Durante el desarrollo del proyecto utilizamos herramientas de inteligencia artificial como apoyo en distintas etapas del trabajo. Para comprender conceptos, analizar fórmulas físicas y organizar la estructura del proyecto.

En primer lugar, utilizamos ChatGPT principalmente para la revisión y comprobación del código en C. Una vez que teníamos el código completo, recurrimos a esta herramienta para detectar posibles errores de programación, revisar su comportamiento durante la ejecución y comprobar que las distintas funciones trabajaran correctamente.

Posteriormente, utilizamos Gemini para explorar alternativas de mejora del proyecto. Le solicitamos propuestas para optimizar algunas funciones del código y también orientación para desarrollar una interfaz gráfica que acompañara al simulador.

Estas herramientas fueron utilizadas como apoyo para la revisión, optimización y presentación del proyecto. Las sugerencias obtenidas fueron evaluadas por el equipo y utilizadas como referencia durante el proceso de desarrollo.

---

### 🪐 MENSAJE FINAL DE MISIÓN

**Una misión. Un objetivo. Una última esperanza.**

La humanidad depende de cada cálculo, cada decisión y cada dato de telemetría.

**Centro de Control Eridiano: esperando confirmación de lanzamiento...**
