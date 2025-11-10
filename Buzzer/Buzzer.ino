#define buzzerPin 14  

// Task function untuk buzzer
void buzzerTask(void *parameter) {
  for (;;) {
    tone(buzzerPin, 1000); // Nada 1 kHz
    vTaskDelay(500 / portTICK_PERIOD_MS);
    noTone(buzzerPin);
    vTaskDelay(300 / portTICK_PERIOD_MS);

    tone(buzzerPin, 1500); // Nada 1.5 kHz
    vTaskDelay(500 / portTICK_PERIOD_MS);
    noTone(buzzerPin);
    vTaskDelay(800 / portTICK_PERIOD_MS);
  }
}

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(115200);

  // Buat task buzzer dan jalankan di core 0
  xTaskCreatePinnedToCore(
    buzzerTask,        
    "Buzzer Task",     
    2048,              
    NULL,              
    1,                 
    NULL,              
    1                 
  );

  Serial.println("Buzzer task running on Core 0");
}

void loop() {
}