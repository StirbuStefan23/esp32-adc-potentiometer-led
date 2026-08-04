#define POT_PIN 34
#define LED_PIN 2

//Timer pentru citire ADC
hw_timer_t *timer = NULL;
//DutyCycle PWM
volatile int duty;
//Flag pentru afisare
volatile bool printFlag = false;

void IRAM_ATTR intTimerADC()
{
  //Citim valoarea (0 - 4095)
  duty = analogRead(POT_PIN);
  ledcWrite(LED_PIN, duty);
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
  //frec 5000 Hz, res 12 bits (0 - 4095)
  ledcAttach(LED_PIN, 5000, 12);

}

void loop() {

  if(printFlag)
  {
    Serial.print("DutyCycle: ");
    Serial.println(duty);

    printFlag = false;
  }

}
