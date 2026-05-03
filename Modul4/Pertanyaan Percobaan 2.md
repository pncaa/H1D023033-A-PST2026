# Percobaan 1 : Analog to Digital Converter (ADC)

---

### 1. Jelaskan mengapa LED dapat diatur kecerahannya menggunakan fungsi `analogWrite()`!

LED dapat diatur kecerahannya menggunakan fungsi `analogWrite()` karena Arduino menghasilkan sinyal PWM (Pulse Width Modulation), yaitu sinyal digital yang dinyalakan dan dimatikan dengan sangat cepat.

Kecerahan LED ditentukan oleh duty cycle:
- Duty cycle kecil → LED redup  
- Duty cycle besar → LED terang  

PWM membuat LED seolah-olah menerima tegangan analog.

---

### 2. Apa hubungan antara nilai ADC (0–1023) dan nilai PWM (0–255)?

- ADC: 0–1023 (10-bit)
- PWM: 0–255 (8-bit)

Nilai ADC dikonversi ke PWM menggunakan map():

Contoh:
- ADC = 0 → PWM = 0  
- ADC = 1023 → PWM = 255  

Sederhananya:
PWM ≈ ADC / 4

---

### 3. Modifikasi program agar LED hanya menyala pada rentang PWM 50–200

```cpp
pwm = map(nilaiADC, 0, 1023, 0, 255);

if (pwm >= 50 && pwm <= 200) {
  analogWrite(ledPin, pwm);
} else {
  analogWrite(ledPin, 0);
}
```
Penjelasan
- Jika nilai PWM berada di antara 50–200, LED akan menyala sesuai tingkat kecerahan
- Jika di bawah 50 → LED terlalu redup → dimatikan
- Jika di atas 200 → LED terlalu terang → dimatikan
- Hal ini membuat LED hanya bekerja pada rentang kecerahan sedang
---



