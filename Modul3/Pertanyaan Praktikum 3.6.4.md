# Percobaan 3.6.4 : I2C

---

### 1. Cara kerja komunikasi I2C
Arduino sebagai master mengirim sinyal clock (SCL) dan data (SDA) ke LCD sebagai slave. Setiap perangkat memiliki alamat unik. Arduino mengirim data ke alamat LCD sehingga hanya LCD tersebut yang merespon.

---

### 2. Posisi pin potensiometer
Tidak harus tetap, namun:
- Jika kiri dan kanan tertukar, arah pembacaan akan terbalik
- Nilai maksimum dan minimum tetap sama, hanya arah putaran berbeda

---

### 3. Modifikasi Program (UART + I2C)

```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int potPin = A0;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  int adc = analogRead(potPin);
  float volt = adc * (5.0 / 1023.0);
  int persen = map(adc, 0, 1023, 0, 100);

  Serial.print("ADC: "); Serial.print(adc);
  Serial.print(" Volt: "); Serial.print(volt);
  Serial.print(" V Persen: "); Serial.print(persen);
  Serial.println("%");

  lcd.setCursor(0, 0);
  lcd.print("ADC: "); lcd.print(adc);

  lcd.setCursor(0, 1);
  int bar = map(adc, 0, 1023, 0, 16);
  for (int i = 0; i < bar; i++) {
    lcd.print("|");
  }

  delay(500);
}
```

---

### 4. Tabel Pengamatan

| ADC | Volt (V) | Persen (%) |
|-----|----------|-----------|
| 1   | 0.00     | 0%        |
| 21  | 0.10     | 2%        |
| 49  | 0.24     | 5%        |
| 74  | 0.36     | 7%        |
| 96  | 0.47     | 9%        |

---

## 🔹 Pertanyaan Umum

### 1. Keuntungan & Kerugian UART dan I2C

**UART**
- ✔ Sederhana
- ✔ Tidak butuh clock
- ❌ Hanya point-to-point

**I2C**
- ✔ Bisa banyak device
- ✔ Hemat pin
- ❌ Lebih kompleks

---

### 2. Peran alamat I2C
Alamat seperti 0x27 atau 0x20 digunakan untuk membedakan perangkat. Jika alamat salah, LCD tidak akan merespon.

---

### 3. Alur kerja UART + I2C
Input dari Serial Monitor → diproses Arduino → output ke LCD via I2C dan ke Serial Monitor via UART.

Arduino mengelola keduanya dengan library berbeda (Serial & Wire), sehingga bisa berjalan bersamaan.


