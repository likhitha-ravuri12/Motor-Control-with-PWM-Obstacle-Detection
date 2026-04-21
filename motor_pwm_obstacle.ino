#define TRIG_PIN 9
#define ECHO_PIN 10
#define MOTOR_PIN 5   // PWM pin

long duration;
int distance;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(MOTOR_PIN, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  // Send ultrasonic pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo
  duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate distance (cm)
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  // Motor control logic
  if (distance < 20) {
    analogWrite(MOTOR_PIN, 0);   // Stop motor
    Serial.println("Motor STOPPED");
  } 
  else if (distance < 50) {
    analogWrite(MOTOR_PIN, 150); // Medium speed
    Serial.println("Medium speed");
  } 
  else {
    analogWrite(MOTOR_PIN, 255); // Full speed
    Serial.println("Fast speed");
  }

  delay(500);
}