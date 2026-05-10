# Percobaan 1 : Komunikasi Task

---

### 1. Apakah kedua task berjalan secara bersamaan atau bergantian? Jelaskan mekanismenya!

Kedua task pada percobaan queue juga berjalan secara bergantian, bukan benar-benar bersamaan. Hal ini disebabkan karena Arduino Uno hanya memiliki satu CPU sehingga scheduler FreeRTOS akan membagi waktu eksekusi antar task.

Task yang digunakan yaitu:

- `read_data` → mengirim data ke queue
- `display` → menerima dan menampilkan data dari queue

Mekanisme kerjanya:

1. Task `read_data` membuat data sensor.
2. Data dikirim ke queue menggunakan `xQueueSend()`.
3. Task `display` mengambil data dari queue menggunakan `xQueueReceive()`.
4. Jika queue kosong, task `display` akan menunggu sampai data tersedia.

Queue digunakan sebagai media komunikasi yang aman antar task sehingga data dapat dikirim tanpa bentrok.

---

### 2. Apakah program ini berpotensi mengalami race condition? Jelaskan!

Program ini tidak terlalu berpotensi mengalami race condition karena komunikasi antar task menggunakan queue FreeRTOS.

Race condition biasanya terjadi ketika dua task mengakses data yang sama secara bersamaan tanpa sinkronisasi. Pada program ini:

- Data tidak diakses langsung secara bersamaan.
- Data dikirim melalui queue.
- Queue memiliki mekanisme sinkronisasi internal dari FreeRTOS.

Karena itu:

- Pengiriman data menjadi lebih aman.
- Data tidak saling tertimpa.
- Sinkronisasi task lebih teratur.

Namun, jika kedua task menggunakan variabel global yang sama tanpa proteksi mutex atau queue, maka race condition dapat terjadi.

---

### 3. Modifikasi Program Menggunakan Sensor DHT

##### Program

```cpp
#include <Arduino_FreeRTOS.h>
#include <queue.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

struct readings {
  float temp;
  float hum;
};

QueueHandle_t my_queue;

void read_data(void *pvParameters);
void display(void *pvParameters);

void setup() {
  Serial.begin(9600);

  dht.begin();

  my_queue = xQueueCreate(5, sizeof(struct readings));

  xTaskCreate(read_data, "read", 128, NULL, 1, NULL);
  xTaskCreate(display, "display", 128, NULL, 1, NULL);
}

void loop() {
}

void read_data(void *pvParameters) {
  struct readings data;

  while(1) {
    data.temp = dht.readTemperature();
    data.hum = dht.readHumidity();

    xQueueSend(my_queue, &data, portMAX_DELAY);

    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void display(void *pvParameters) {
  struct readings data;

  while(1) {
    if(xQueueReceive(my_queue, &data, portMAX_DELAY) == pdPASS) {

      Serial.print("Temperature: ");
      Serial.println(data.temp);

      Serial.print("Humidity: ");
      Serial.println(data.hum);
    }
  }
}
```

---

#### Hasil dan Analisis

Pada modifikasi ini, sensor DHT11 digunakan untuk membaca suhu dan kelembapan secara nyata.

Hasil pengujian menunjukkan:

- Nilai suhu dan kelembapan berubah secara dinamis sesuai kondisi lingkungan.
- Task `read_data` membaca sensor setiap 1 detik.
- Data dikirim melalui queue menuju task `display`.
- Task `display` menampilkan data pada Serial Monitor.

Dengan menggunakan queue, komunikasi antar task menjadi lebih stabil dan aman. Program juga tetap responsif karena setiap task memiliki fungsi masing-masing.

---
