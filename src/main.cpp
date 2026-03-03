#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME ""
#define BLYNK_AUTH_TOKEN ""

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

#define GAS_SENSOR 34
#define LED_warning 26
#define LED_exhaust 27
#define BUZZER 4

int gasThreshold = 500;
bool alertSent = false;

BlynkTimer timer;

void checkGas() {
  int gasValue = analogRead(GAS_SENSOR);
  Serial.println(gasValue);
  Blynk.virtualWrite(V0, gasValue);

  if (gasValue > gasThreshold) {
    digitalWrite(LED_warning, HIGH);
    digitalWrite(BUZZER, HIGH);
    if (!alertSent) {
      Blynk.logEvent("gas_alert", "⚠ Gas Leakage Detected!");
      alertSent = true;
    }
  } else {
    digitalWrite(LED_warning, LOW);
    digitalWrite(BUZZER, LOW);
    alertSent = false;
  }
}

// V1 controls LED_exhaust (exhaust fan switch)
BLYNK_WRITE(V1) {
  int switchState = param.asInt();
  digitalWrite(LED_exhaust, switchState);
}

void setup() {
  Serial.begin(115200);

  pinMode(LED_warning, OUTPUT);
  pinMode(LED_exhaust, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  timer.setInterval(2000L, checkGas);
}

void loop() {
  Blynk.run();
  timer.run();
}