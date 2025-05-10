#include <Servo.h>

#define POT1 A0  // Potenciómetro para Servo 1
#define POT2 A1  // Potenciómetro para Servo 2
#define POT3 A2  // Potenciómetro para Servo 3

Servo servo1;
Servo servo2;
Servo servo3;

// Función para redondear al múltiplo más cercano
float redondear(float valor, float paso) {
  return round(valor / paso) * paso;
}

void setup() {
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
}

void loop() {
  // Leer potenciómetros
  int val1 = analogRead(POT1);
  int val2 = analogRead(POT2);
  int val3 = analogRead(POT3);

  // Mapear a ángulo 0-180
  float ang1 = map(val1, 0, 1023, 0, 180);
  float ang2 = map(val2, 0, 1023, 0, 180);
  float ang3 = map(val3, 0, 1023, 0, 180);

  // Aplicar precisión requerida
  ang1 = redondear(ang1, 12.0);
  ang2 = redondear(ang2, 5.0);
  ang3 = redondear(ang3, 0.5);

  // Limitar valores entre 0 y 180
  ang1 = constrain(ang1, 0, 180);
  ang2 = constrain(ang2, 0, 180);
  ang3 = constrain(ang3, 0, 180);

  // Enviar ángulos a los servos
  servo1.write((int)ang1);
  servo2.write((int)ang2);
  servo3.write((int)ang3);

  delay(15);
}
