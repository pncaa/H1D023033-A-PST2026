# Pertanyaan Praktikum

---

### 1. Jelaskan perbedaan antara `loop()` pada Arduino biasa dengan sistem yang menggunakan RTOS!

Pada Arduino biasa, fungsi `loop()` digunakan sebagai pusat seluruh program dan dieksekusi terus menerus secara sequential.

Sedangkan pada sistem RTOS:

- Program dibagi menjadi beberapa task.
- Scheduler FreeRTOS mengatur eksekusi task.
- Fungsi `loop()` biasanya tidak digunakan.

Perbedaannya adalah RTOS memungkinkan multitasking sehingga beberapa proses dapat berjalan secara concurrent.

---

### 2. Mengapa fungsi `loop()` dibiarkan kosong?

Fungsi `loop()` dibiarkan kosong karena seluruh pekerjaan program sudah dijalankan oleh task FreeRTOS.

Setelah `vTaskStartScheduler()` dipanggil, scheduler akan mengambil alih kontrol CPU dan menjalankan semua task yang telah dibuat. Oleh karena itu, kode di dalam `loop()` tidak lagi diperlukan.

---

### 3. Apa insight utama yang Anda pelajari dari praktikum ini?

Insight utama yang diperoleh dari praktikum ini adalah:

- FreeRTOS memungkinkan Arduino menjalankan beberapa task secara concurrent.
- Scheduler berfungsi mengatur pembagian waktu CPU antar task.
- Queue dapat digunakan sebagai media komunikasi antar task dengan aman.
- RTOS membuat sistem embedded lebih terstruktur dan responsif dibandingkan pemrograman biasa.

Praktikum ini juga memberikan pemahaman mengenai konsep multitasking, sinkronisasi task, dan komunikasi data pada sistem embedded berbasis RTOS.
