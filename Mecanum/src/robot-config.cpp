#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor leftMotorA = motor(PORT1, ratio36_1, false);
motor leftMotorB = motor(PORT2, ratio36_1, false);
motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB);
motor rightMotorA = motor(PORT3, ratio36_1, true);
motor rightMotorB = motor(PORT4, ratio36_1, true);
motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 40, mm, 1);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

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

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}