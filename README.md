# 🛸 PROJECT HAIL MARY / ARTEMIS SLS
## Consola Eridiana de Telemetría 🚀
### Telemetría de propulsión y trayectoria – Centro de Control de Misión

**Universidad:** Universidad Tecnológica Nacional – Facultad Regional Resistencia  
**Cátedra:** Algoritmos y Estructuras de Datos  
**Proyecto:** Trabajo Práctico Integrador Final – Simulador de Misiones Artemis / Consola Eridiana  
**Grupo:** B14
**Comision** k1.2**
**Esenario 1**

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

# Video de Youtube
Link: https://youtu.be/oNGVit2uueE
