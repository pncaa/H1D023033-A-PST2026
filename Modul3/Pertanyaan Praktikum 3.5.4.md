# 📘 Percobaan 3.5.4: UART

---

### 1. Proses dari input keyboard hingga LED menyala/mati
Ketika user mengetik perintah pada Serial Monitor, data dikirim dari komputer ke Arduino melalui komunikasi serial (UART). Arduino kemudian membaca data tersebut menggunakan fungsi `Serial.read()`. Setelah data diterima, program akan melakukan pengecekan kondisi (if/else). Jika input sesuai (misalnya '1' untuk ON dan '0' untuk OFF), maka Arduino akan mengirim sinyal HIGH atau LOW ke pin LED sehingga LED menyala atau mati.

---

### 2. Fungsi Serial.available()
Fungsi `Serial.available()` digunakan untuk mengecek apakah ada data yang tersedia di buffer serial sebelum dibaca.

Jika baris ini dihilangkan:
- Arduino bisa mencoba membaca data yang belum ada
- Nilai yang dibaca bisa tidak valid (noise)
- Program bisa berjalan tidak stabil

---

### 3. Modifikasi Program (LED Blink saat input '2')

```cpp
const int ledPin = 8;
char data;
bool blinking = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    data = Serial.read();

    if (data == '1') {
      digitalWrite(ledPin, HIGH);
      blinking = false;
    }
    else if (data == '0') {
      digitalWrite(ledPin, LOW);
      blinking = false;
    }
    else if (data == '2') {
      blinking = true;
    }
  }

  if (blinking) {
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  }
}
```

**Penjelasan:**
- `blinking` digunakan sebagai flag untuk mode berkedip
- Jika input '2', LED akan terus berkedip
- Delay digunakan untuk mengatur kecepatan kedip

---

### 4. delay() vs millis()
- `delay()` menghentikan seluruh program sementara
- `millis()` memungkinkan program berjalan tanpa blocking

Pengaruh:
- delay() → sistem tidak responsif
- millis() → sistem lebih optimal dan multitasking




