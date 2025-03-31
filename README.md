# Sistema Mecanum Drive para VEX Robotics

## Descripción del Sistema Mecanum Drive
El **Sistema Mecanum Drive** es un tipo avanzado de tracción omnidireccional que permite que un robot se mueva en cualquier dirección sin la necesidad de girar físicamente. Utiliza cuatro ruedas especiales, conocidas como **ruedas Mecanum**, dispuestas en un ángulo de 45 grados, lo que permite que el robot se desplace hacia adelante, atrás, lateralmente o en diagonal. Este sistema es altamente eficiente en competiciones como **VEX Robotics**, ya que ofrece una maniobrabilidad precisa y rápida en espacios reducidos.

## Características del Sistema Mecanum Drive
1. **Movimiento Omnidireccional**: Permite al robot moverse en cualquier dirección sin necesidad de rotar.
2. **Ruedas Mecanum**: Equipadas con rodillos a 45 grados, generando fuerzas multidireccionales para un control preciso.
3. **Control Independiente de Ruedas**: Cada rueda es controlada de manera independiente para ofrecer mayor flexibilidad en los movimientos.
4. **Sin Necesidad de Giro**: No requiere girar sobre su eje para cambiar de dirección.
5. **Alta Maniobrabilidad**: Ideal para maniobrar en espacios pequeños y realizar movimientos precisos.
6. **Complejidad de Control**: Requiere cálculos matemáticos y ajustes finos para controlar las velocidades de los motores de forma precisa.
7. **Versatilidad en Movimiento**: Permite movimientos complejos como giros, desplazamientos laterales y diagonales.

## Ventajas del Sistema Mecanum Drive
- **Alta Maniobrabilidad**: Permite moverse en cualquier dirección, ideal para maniobras rápidas y precisas en espacios reducidos.
- **Adaptabilidad en Espacios Reducidos**: No requiere espacio para giros, lo que es perfecto para competir en campos pequeños y con obstáculos.
- **Movimientos Complejos**: Facilita desplazamientos diagonales y tácticos, mejorando la capacidad para esquivar y posicionarse estratégicamente.

## Desventajas
- **Complejidad de Programación**: Requiere cálculos precisos para controlar las velocidades de las ruedas, lo que puede aumentar la dificultad del código.
- **Desgaste Rápido**: En superficies irregulares, las ruedas pueden desgastarse más rápidamente, afectando el rendimiento.

## Aplicaciones en Competencias VEX Robotics
El sistema Mecanum Drive es ampliamente utilizado en competiciones de **VEX Robotics** debido a su alta maniobrabilidad y capacidad para realizar tareas complejas. Algunas de sus aplicaciones incluyen:
- **Control Preciso en Manipulación**: Se utiliza para mover objetos de un lugar a otro, una tarea común en competiciones que requieren manipulación de bloques o elementos.
- **Estrategias de Evasión**: Su capacidad para moverse en cualquier dirección permite al robot evitar obstáculos rápidamente, brindándole ventaja sobre otros equipos.
- **Movimientos Tácticos**: En competiciones donde el tiempo es limitado y la precisión es clave, el sistema Mecanum permite realizar movimientos rápidos y eficientes para ganar puntos estratégicos.

## Consejos para Implementación en Competencias VEX
- **Optimización del Código**: Asegúrate de que el código de control de las ruedas Mecanum esté bien optimizado para lograr una respuesta rápida y precisa en los movimientos del robot.
- **Pruebas Continuas**: Realiza pruebas constantes durante las prácticas para ajustar el sistema de tracción y asegurar que el robot pueda realizar todas las maniobras necesarias durante la competencia.
- **Balance del Robot**: Dado que el sistema Mecanum permite movimientos omnidireccionales, es crucial que el robot esté bien equilibrado para evitar problemas de estabilidad durante movimientos rápidos o al enfrentar obstáculos.

## Fórmula para Movimiento Lateral con Ruedas Mecanum
El movimiento lateral se consigue ajustando las velocidades de cada rueda según la siguiente fórmula:
### Cálculo de velocidad para cada rueda:
- Rueda Delantera Izquierda = Avance + Giro + Lateral
- Rueda Delantera Derecha = Avance - Giro - Lateral
- Rueda Trasera Izquierda = Avance + Giro - Lateral
- Rueda Trasera Derecha = Avance - Giro + Lateral

## Controles del Joystick
En VEX Robotics, los controles del joystick tienen diferentes ejes (Axis) que representan el movimiento en distintas direcciones:
- Axis1 (Joystick derecho, X) → Controla el movimiento lateral (izquierda/derecha).
- Axis2 (Joystick derecho, Y) → Controla el movimiento hacia adelante y atrás.
- Axis3 (Joystick izquierdo, Y) → También se usa para avance y retroceso.
- Axis4 (Joystick izquierdo, X) → Controla el giro del robot sobre su propio eje (rotación).
  
## Código Completo para Control de Mecanum Drive
El siguiente código es parte del archivo robot-config.cpp, el cual permite controlar el movimiento de un robot con tracción Mecanum utilizando un joystick en VEX Robotics:

  ```cpp
  int rc_auto_loop_function_Controller1() {
    while(true) {
        if(RemoteControlCodeEnabled) {
            // Leer los joysticks
            int forwardBackward = Controller1.Axis3.position();  // Avance/Retroceso
            int lateral = Controller1.Axis1.position();          // Movimiento Lateral
            int turn = Controller1.Axis4.position();             // Giros Izquierda/Derecha
    
            // Calcular velocidades para mecanum (fórmula ajustada)
            int RuedaDelanteraIzquierda  = forwardBackward + turn + lateral;
            int RuedaDelanteraDerecha = forwardBackward - turn - lateral;
            int RuedaTraseraIzquierda   = forwardBackward + turn - lateral;
            int RuedaTraseraDerecha  = forwardBackward - turn + lateral;
    
            // Aplicar velocidades a los motores
            leftMotorA.spin(forward, RuedaDelanteraIzquierda, percent);
            rightMotorA.spin(forward, RuedaDelanteraDerecha, percent);
            leftMotorB.spin(forward, RuedaTraseraIzquierda, percent);
            rightMotorB.spin(forward, RuedaTraseraDerecha, percent);
        }
        wait(20, msec);
    }
    return 0;
  }
