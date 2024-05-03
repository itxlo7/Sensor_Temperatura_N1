// Definición de pines para los LEDs y el Buzzer
const int ledRojo = 8;
const int ledVerde = 10;
const int pinBuzzer = 7;
const int pinSensorTemp = A0;

void setup() {
  // Inicializar los pines como salidas
  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

void loop() {
  // Leer la temperatura desde el sensor LM35
  int sensorValue = analogRead(pinSensorTemp);
  
  // Convertir el valor leído a temperatura en grados Celsius
  float voltage = sensorValue * (5.0 / 1023.0); // Convertir valor a voltaje (0-5V)
  float temperaturaC = (voltage - 0.5) * 100.0; // Calibración y conversión a °C

  // Comprobar si la temperatura es mayor o igual a 30 grados Celsius
  if (temperaturaC >= 40.0) {
    // Encender los LEDs rojos y activar el buzzer
    digitalWrite(ledRojo, HIGH);
    digitalWrite(ledVerde, LOW);
    tone(pinBuzzer, 500); // Activar el buzzer a 500Hz
  } else {
    // Apagar los LEDs rojos y mantener los LEDs verdes encendidos
    digitalWrite(ledRojo, LOW);
    digitalWrite(ledVerde, HIGH);
    noTone(pinBuzzer); // Apagar el buzzer
  }

  // Esperar un breve tiempo antes de volver a leer la temperatura
  delay(1000); // Esperar 1 segundo
}