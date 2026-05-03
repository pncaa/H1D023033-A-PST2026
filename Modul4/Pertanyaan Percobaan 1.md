# Percobaan 1 : Analog to Digital Converter (ADC)

---

### 1. Apa fungsi perintah analogRead() pada rangkaian praktikum ini?
Perintah analogRead() digunakan untuk membaca nilai tegangan analog dari potensiometer yang terhubung ke pin analog Arduino. Nilai yang dibaca akan dikonversi oleh ADC (Analog to Digital Converter) menjadi data digital dalam rentang 0 hingga 1023, yang merepresentasikan tegangan dari 0V hingga 5V.

Dalam praktikum ini, nilai tersebut digunakan sebagai input untuk mengontrol posisi sudut servo motor.

---

### 2. Mengapa diperlukan fungsi map() dalam program tersebut?
Fungsi map() digunakan untuk mengubah (mengonversi) rentang nilai dari satu skala ke skala lain.

Pada kasus ini:
- Nilai dari analogRead() berada pada rentang 0–1023
- Sedangkan servo hanya dapat bergerak pada rentang sudut 0–180 derajat
Karena itu, map() diperlukan untuk menyesuaikan nilai ADC agar sesuai dengan rentang sudut servo, sehingga pergerakan servo menjadi proporsional terhadap putaran potensiometer.

Contoh:
```cpp
pos = map(val, 0, 1023, 0, 150);
```
---

### 3. Modifikasi program berikut agar servo hanya bergerak dalam rentang 30° hingga 150°, meskipun potensiometer tetap memiliki rentang ADC 0–1023.

Untuk membatasi pergerakan servo, cukup mengubah parameter output pada fungsi map().
Perubahan kode:
```cpp
pos = map(val, 0, 1023, 30, 150);
```
Penjelasan
- Nilai minimum ADC (0) akan menghasilkan sudut servo 30°
- Nilai maksimum ADC (1023) akan menghasilkan sudut servo 150°
- Dengan demikian, meskipun potensiometer diputar penuh, servo tidak akan bergerak di bawah 30° atau di atas 150°

Hal ini berguna untuk:

- Menghindari gerakan ekstrem servo
- Menyesuaikan kebutuhan mekanik tertentu
- Mengurangi risiko kerusakan pada sistem
---



