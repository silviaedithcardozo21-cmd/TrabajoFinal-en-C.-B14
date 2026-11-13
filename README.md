# 🛸 PROJECT HAIL MARY / ARTEMIS SLS - CONSOLA ERIDIANA DE TELEMETRÍA
#       elemetría de Propulsión por Astrófago en Consola Eridiana 🚀


Universidad: Universidad Tecnológica Nacional – Facultad Regional Resistencia 

Cátedra: Algoritmos y Estructuras de Datos

Proyecto: Trabajo Práctico Integrador Final - Simulador de Misiones Artemis / Consola Eridiana

CAPITANES DE LA NAVE: Cardozo Silvia Edith. 46515526
                      Ferreira Florencia Milagros 47932733
                      Inglant Facundo Agustín 47620067
Grupo: B14

# 🛰️ 2. Descripción de la Interfaz y Escenario
El programa simula las fases de ascenso y propulsión del cohete Space Launch System (SLS) en la Consola Eridiana de Control (Ryland Grace & Rocky - Telemetría de Propulsión por Astrófago), resolviendo las ecuaciones de Movimiento Rectilíneo Uniformemente Variado (MRUV):

Nivel 1 (Plataforma LC-39B): Preparación inicial en reposo (v_0 = 0.0{ m/s}, y_0 = 0.0{ m}).

Nivel 2 (Despegue e Impulso SRB): Aceleración inicial $a_1 = 20.0\text{ m/s}^2 impulsada por motores RS-25 y tanques sólidos SRB.

Nivel 3 (Desacople Tanques SRB): Separación a los $t_1 = 120.0{ s}, registrando velocidad V_1$ y altitud $y_1$.

Nivel 4 (Ascenso Principal Core Stage): Propulsión secundaria con aceleración a_2 = 12.5{ m/s}^2 hasta la altitud MECO h = 160.000,0{ m}.

Nivel 5 (Apagado de Motores MECO & Caída Libre): Apagado de reactores y ascenso por inercia bajo gravedad g = 9.80{ m/s}^2.

Nivel 6 (Apogeo & Carga G): Determinación del apogeo máximo H_{{máx}} y la aceleración en múltiplos de g soportada por la tripulación.
