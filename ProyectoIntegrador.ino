 // Pines del puente H
const int IN1 = 16;   // GPIO 16
const int IN2 = 4;    // GPIO 4
const int IN3 = 12;   // GPIO 12
const int IN4 = 15;   // GPIO 15
const int ENA = 5;    // GPIO 5
const int ENB = 2;    // GPIO 2

void setup() {
  // Configuración de pines
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Inicializar la comunicación serial con el HC-06
  Serial.begin(9600);   // Asegúrate de que el HC-06 esté configurado a 9600 baudios
}

void detener() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);  // Detener PWM en ENA
  analogWrite(ENB, 0);  // Detener PWM en ENB
}

void avanzar(int velocidad) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, velocidad);  // Controla la velocidad del motor izquierdo
  analogWrite(ENB, velocidad);  // Controla la velocidad del motor derecho
}

void retroceder(int velocidad) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, velocidad);
  analogWrite(ENB, velocidad);
}

void girarIzquierda(int velocidad) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, velocidad);
  analogWrite(ENB, velocidad);
}

void girarDerecha(int velocidad) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, velocidad);
  analogWrite(ENB, velocidad);
}

void loop() {
  
  if (Serial.available()) {  // Si hay datos del Bluetooth
    char comando = Serial.read();  // Lee el comando
Serial.println(comando);
    // Procesar el comando y mover los motores
    switch (comando) {
      case 'F':  // Avanzar
        avanzar(200);
        break;
      case 'B':  // Retroceder
        retroceder(200);
        break;
      case 'L':  // Girar a la izquierda
        girarIzquierda(150);
        break;
      case 'R':  // Girar a la derecha
        girarDerecha(150);
        break;
      case 'S':  // Detener
        detener();
        break;
      default:
        detener();  // Si el comando no es válido, detener el motor
        break;
    }
  }
}
