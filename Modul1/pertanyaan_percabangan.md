#  Percabangan (Arduino)

## Tujuan Percobaan
- Memahami konsep percabangan `if-else`
- Mengontrol LED berdasarkan kondisi tertentu
- Menghubungkan logika program dengan output fisik (LED)

---

## Rangkaian
- LED terhubung ke pin **6** Arduino
- Resistor 220Ω sebagai pembatas arus
- Kaki negatif LED terhubung ke **GND**

---

## Source Code
```cpp
const int ledPin = 6;   // Pin LED
int timeDelay = 1000;   // Delay awal (lambat)

void setup() {
  pinMode(ledPin, OUTPUT); // Set pin sebagai output
}

void loop() {
  digitalWrite(ledPin, HIGH); // LED menyala
  delay(timeDelay);           // Tunggu

  digitalWrite(ledPin, LOW);  // LED mati
  delay(timeDelay);           // Tunggu

  // Percabangan kondisi
  if (timeDelay <= 100) {
    delay(3000);      // Jeda sebelum reset
    timeDelay = 1000; // Reset ke lambat
  } else {
    timeDelay -= 100; // Mempercepat LED
  }
}
```

---

## Penjelasan Kode
- `ledPin` → menentukan pin yang digunakan LED
- `timeDelay` → mengatur kecepatan kedip LED
- `pinMode()` → mengatur pin sebagai output
- `digitalWrite(HIGH)` → LED menyala
- `digitalWrite(LOW)` → LED mati
- `delay()` → memberikan jeda waktu

### Percabangan
- Jika `timeDelay <= 100` → LED reset ke lambat
- Jika tidak → LED semakin cepat

---

## Analisis Hasil
- LED awalnya berkedip lambat
- Semakin lama semakin cepat
- Setelah mencapai batas tertentu → kembali lambat
- Pola: **mati → lambat → cepat → reset**

---

## Jawaban Pertanyaan

### 1. Kapan masuk blok `if`?
Saat `timeDelay <= 100`

### 2. Kapan masuk blok `else`?
Saat `timeDelay > 100`

### 3. Fungsi `delay(timeDelay)`?
Mengatur lama jeda LED menyala/mati sehingga menentukan kecepatan kedip

### 4. Modifikasi Program (Cepat → Sedang → Mati)
```cpp
const int ledPin = 6;
int timeDelay = 1000;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(timeDelay);

  digitalWrite(ledPin, LOW);
  delay(timeDelay);

  if (timeDelay == 1000) {
    timeDelay = 300;   // sedang
  } else if (timeDelay == 300) {
    timeDelay = 100;   // cepat
  } else if (timeDelay == 100) {
    timeDelay = 0;     // mati
  } else {
    while(true);       // berhenti
  }
}
```

---

## Kesimpulan
- Percabangan `if-else` digunakan untuk mengatur perubahan kondisi LED
- Program dapat mengontrol kecepatan LED secara dinamis
- Logika sederhana dapat menghasilkan perilaku sistem yang kompleks


