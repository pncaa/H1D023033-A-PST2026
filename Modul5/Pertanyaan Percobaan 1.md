# Percobaan 1 : Multitasking

---

### 1. Apakah ketiga task berjalan secara bersamaan atau bergantian? Jelaskan mekanismenya!
Ketiga task pada program FreeRTOS tidak benar-benar berjalan secara bersamaan karena Arduino Uno hanya memiliki satu inti prosesor. Namun, task berjalan secara **concurrent** atau bergantian dengan sangat cepat sehingga terlihat seperti berjalan bersamaan.

Mekanisme yang digunakan adalah **scheduler** pada FreeRTOS. Scheduler bertugas mengatur kapan setiap task dijalankan oleh CPU. Ketika sebuah task menjalankan fungsi `vTaskDelay()`, task tersebut akan masuk ke kondisi blocked sementara waktu tertentu. Selama task tersebut menunggu, scheduler akan memberikan kesempatan kepada task lain untuk berjalan.

Pada program:

- `TaskBlink1` mengontrol LED pertama dengan delay 200 ms.
- `TaskBlink2` mengontrol LED kedua dengan delay 300 ms.
- `Taskprint` mencetak counter setiap 500 ms.

Karena semua task memiliki prioritas yang sama (`priority = 1`), maka scheduler menjalankannya secara bergantian menggunakan metode time slicing.

Dengan demikian:

- Task tidak berjalan paralel secara nyata.
- Task berjalan secara bergantian dengan cepat.
- Scheduler memastikan semua task tetap mendapatkan waktu eksekusi.

---

### 2. Bagaimana cara menambahkan task keempat? Jelaskan langkahnya!
Untuk menambahkan task keempat pada FreeRTOS, langkah-langkahnya adalah sebagai berikut:

#### Langkah 1 — Membuat deklarasi fungsi task

Tambahkan deklarasi fungsi di bagian atas program.

```cpp
void TaskBlink3(void *pvParameters);
```

---

#### Langkah 2 — Membuat task menggunakan `xTaskCreate()`

Tambahkan kode berikut di dalam fungsi `setup()`.

```cpp
xTaskCreate(
  TaskBlink3,
  "task4",
  128,
  NULL,
  1,
  NULL
);
```

Penjelasan parameter:

- `TaskBlink3` → nama fungsi task
- `"task4"` → nama task
- `128` → ukuran stack
- `NULL` → parameter task
- `1` → prioritas task
- `NULL` → handle task

---

#### Langkah 3 — Membuat isi task

Buat fungsi task baru seperti berikut:

```cpp
void TaskBlink3(void *pvParameters) {
  pinMode(6, OUTPUT);

  while(1) {
    Serial.println("Task4");

    digitalWrite(6, HIGH);
    vTaskDelay(400 / portTICK_PERIOD_MS);

    digitalWrite(6, LOW);
    vTaskDelay(400 / portTICK_PERIOD_MS);
  }
}
```

Task tersebut akan mengontrol LED tambahan pada pin 6.

---

### 3. Modifikasi Program Menggunakan Potensiometer
#### Program

```cpp
#include <Arduino_FreeRTOS.h>

const int potPin = A0;
int delayValue = 200;

void TaskBlink1(void *pvParameters);
void TaskReadPot(void *pvParameters);

void setup() {
  Serial.begin(9600);

  xTaskCreate(TaskBlink1, "Blink", 128, NULL, 1, NULL);
  xTaskCreate(TaskReadPot, "Pot", 128, NULL, 1, NULL);

  vTaskStartScheduler();
}

void loop() {
}

void TaskBlink1(void *pvParameters) {
  pinMode(8, OUTPUT);

  while(1) {
    digitalWrite(8, HIGH);
    vTaskDelay(delayValue / portTICK_PERIOD_MS);

    digitalWrite(8, LOW);
    vTaskDelay(delayValue / portTICK_PERIOD_MS);
  }
}

void TaskReadPot(void *pvParameters) {
  while(1) {
    int potValue = analogRead(potPin);

    delayValue = map(potValue, 0, 1023, 100, 1000);

    Serial.print("Delay: ");
    Serial.println(delayValue);

    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}
```

---

#### Hasil dan Analisis

Pada program modifikasi ini, potensiometer digunakan untuk mengatur kecepatan kedipan LED.

Cara kerjanya:

- Nilai analog dari potensiometer dibaca menggunakan `analogRead()`.
- Nilai tersebut dipetakan menjadi delay antara 100 ms hingga 1000 ms menggunakan fungsi `map()`.
- Semakin besar nilai potensiometer, maka delay semakin besar sehingga LED berkedip lebih lambat.
- Semakin kecil nilai potensiometer, maka LED berkedip lebih cepat.

Hasil pengujian menunjukkan bahwa perubahan posisi potensiometer berhasil mempengaruhi kecepatan LED secara realtime tanpa mengganggu task lainnya. Hal ini menunjukkan bahwa multitasking pada FreeRTOS berjalan dengan baik.

---


