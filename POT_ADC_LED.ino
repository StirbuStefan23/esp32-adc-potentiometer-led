#define POT_PIN 34

//Timer pentru citire ADC
hw_timer_t *timer = NULL;
//Valoare citita pe ADC
int potValue = 0;
//Flag pentru afisare
volatile bool printFlag = false;

void IRAM_ATTR intTimerADC()
{
  //Citim valoarea (0 - 4095)
  potValue = analogRead(POT_PIN);
  printFlag = true;
}

void setup() {
  Serial.begin(115200);

  pinMode(POT_PIN, INPUT);
  //Setam frecventa de 1MHz
  timer = timerBegin(1000000);
  //Setam declansarea la fiecare 10 ms
  timerAlarm(timer, 10000, true, 0);
  timerAttachInterrupt(timer, &intTimerADC);

}

void loop() {

  if(printFlag)
  {
    //Calculam tensiunea (0 - 3.3V)
    float voltage = (potValue * 3.3) / 4095.0; 

    Serial.print("Raw value ADC: ");
    Serial.println(potValue);

    Serial.print("Voltage: ");
    Serial.print(voltage);
    Serial.println(" V");

    printFlag = false;
  }

}
