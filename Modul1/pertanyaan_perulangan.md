# 📘 README Percobaan 2A - Perulangan (Arduino)

## 👤 Identitas
- Nama: Panca Aziz Saputra
- NIM: H1D023033
- Mata Kuliah: Sistem Tertanam dan Mikrokontroler
- Modul: Modul I - Percabangan dan Perulangan

---

## 🎯 Tujuan Percobaan
- Memahami konsep perulangan `for`
- Mengontrol LED secara berurutan
- Membuat efek LED running (berjalan)

---

## 🔌 Rangkaian
Konfigurasi LED:
- LED 1 → Pin 2
- LED 2 → Pin 3
- LED 3 → Pin 4
- LED 4 → Pin 5
- LED 5 → Pin 6
- LED 6 → Pin 7
- Semua LED → resistor → GND

---

## 💻 Source Code
```cpp
int timer = 100; // delay

void setup() {
  for (int ledPin = 2; ledPin < 8; ledPin++) {
    pinMode(ledPin, OUTPUT); // set pin sebagai output
  }
}

void loop() {
  // kiri ke kanan
  for (int ledPin = 2; ledPin < 8; ledPin++) {
    digitalWrite(ledPin, HIGH);
    delay(timer);
    digitalWrite(ledPin, LOW);
  }

  // kanan ke kiri
  for (int ledPin = 7; ledPin >= 2; ledPin--) {
    digitalWrite(ledPin, HIGH);
    delay(timer);
    digitalWrite(ledPin, LOW);
  }
}
```

---

## 🧠 Penjelasan Kode
- `timer` → mengatur kecepatan LED
- `for` pertama → menghidupkan LED dari kiri ke kanan
- `for` kedua → menghidupkan LED dari kanan ke kiri
- `pinMode()` → mengatur pin sebagai output
- `digitalWrite()` → mengontrol LED

---

## 🔍 Analisis Hasil
- LED menyala berurutan dari kiri ke kanan
- Setelah LED terakhir → arah berubah ke kanan ke kiri
- Pola berjalan terus menerus
- Tidak ada LED yang mati di luar urutan

---

## ❓ Jawaban Pertanyaan

### 1. Gambaran Rangkaian
LED disusun berurutan pada breadboard, masing-masing terhubung ke pin digital Arduino (2–7) dan ke GND melalui resistor.

### 2. LED kiri ke kanan
Menggunakan loop:
```cpp
for (int ledPin = 2; ledPin < 8; ledPin++)
```
Pin bertambah sehingga LED menyala berurutan dari kiri ke kanan.

### 3. LED kanan ke kiri
Menggunakan loop:
```cpp
for (int ledPin = 7; ledPin >= 2; ledPin--)
```
Pin berkurang sehingga LED menyala dari kanan ke kiri.

### 4. Program Modifikasi (3 LED kiri & kanan bergantian)
```cpp
int timer = 200;

void setup() {
  for (int pin = 2; pin <= 7; pin++) {
    pinMode(pin, OUTPUT);
  }
}

void loop() {
  // kiri
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  delay(timer);

  // kanan
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  delay(timer);
}
```

---

## 📌 Kesimpulan
- Perulangan `for` mempermudah pengendalian banyak LED
- Program menjadi lebih efisien dan rapi
- Efek LED running dapat dibuat dengan logika sederhana

---

## 🚀 Repository
Upload ke GitHub dengan format:
```
Modul1 - Percobaan2A - Panca - H1D023033
```

