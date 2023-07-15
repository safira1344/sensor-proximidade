const int trigPin = 2;
const int echoPin = 3;
const int redLedPin = 4;
const int greenLedPin = 5;

// Define as constantes para cálculo de distância
const float soundSpeed = 343.0; // velocidade do som em metros por segundo
const float distanceThreshold = 0.5; // distância em metros (50 cm)

void setup() {
 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
 
  digitalWrite(redLedPin, LOW);
  digitalWrite(greenLedPin, LOW);
 
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  long duration = pulseIn(echoPin, HIGH);
 
  float distance = duration * soundSpeed / 20000.0;

  Serial.print("Distância: ");
  Serial.print(distance);
  Serial.println(" metros");
 
  if (distance < distanceThreshold) {
   
    digitalWrite(redLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);

  } else {
   
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
  }
  delay(100);
}
