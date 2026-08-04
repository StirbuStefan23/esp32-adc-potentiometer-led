#define POT_PIN 34

int potValue = 0;

void setup() {
  Serial.begin(115200);

  pinMode(POT_PIN, INPUT);
}

void loop() {
  //Citim valoarea (0 - 4095)
  potValue = analogRead(POT_PIN);
  //Calculam tensiunea (0 - 3.3V)
  float voltage = (potValue * 3.3) / 4095.0; 

  Serial.print("Raw value ADC: ");
  Serial.println(potValue);

  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");

  delay(200);
}
