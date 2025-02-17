// Inclui a Biblioteca AccelStepper
#include <AccelStepper.h>

// Define os pinos de conexão
const int DIR = 2;
const int STEP = 3;

// Defina o tipo de interface do motor
#define InterfaceMotor 1

// Cria uma instância
AccelStepper Stepper(InterfaceMotor, STEP, DIR);

void setup() {
  // Define a velocidade máxima e o fator de aceleração
  Stepper.setMaxSpeed(1000);   // Velocidade máxima
  // Stepper.setAcceleration(50); // Aceleração
  Stepper.setSpeed(500); // Velocidade regular

}

void loop() {
  // Liga o motor na velocidade definida
  // Stepper.setSpeed(1000); // Velocidade regular
  Stepper.runSpeed();
}