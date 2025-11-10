void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32-S3!");
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(10); // this speeds up th#define button1Pin  14   
#define button2Pin  13
#define led1Pin     12
#define led2Pin     11

void buttonTask(void *parameter) {
  for (;;) {
    int tombol1 = digitalRead(button1Pin);
    int tombol2 = digitalRead(button2Pin);

    // Tombol 1 mengontrol LED 1
    if (tombol1 == LOW) {              
      digitalWrite(led1Pin, HIGH);
    } else {
      digitalWrite(led1Pin, LOW);
    }

    // Tombol 2 mengontrol LED 2
    if (tombol2 == LOW) {              
      digitalWrite(led2Pin, HIGH);
    } else {
      digitalWrite(led2Pin, LOW);
    }

    vTaskDelay(100 / portTICK_PERIOD_MS); 
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(button1Pin, INPUT_PULLUP);  
  pinMode(button2Pin, INPUT_PULLUP);  
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);

  // Buat task untuk membaca tombol dan jalankan di core 1
  xTaskCreatePinnedToCore(
    buttonTask,         
    "Button Task",      
    2048,               
    NULL,               
    1,                  
    NULL,               
    0                   
  );

  Serial.println("Button task running on Core 0");
}

void loop() {
}e simulation
}
