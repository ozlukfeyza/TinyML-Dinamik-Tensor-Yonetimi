# TinyML-Dinamik-Tensor-Yonetimi
# TinyML Dinamik Tensör ve Quantization Projesi

Bu proje, kaynak kısıtlı (RAM/CPU) mikrodenetleyiciler (ESP32, Arduino, STM32) için optimize edilmiş, çalışma zamanında veri tipi değiştirebilen dinamik bir **Tensör** kütüphanesi ve **Quantization (Nicemleme)** demosu içermektedir.

 Proje Amacı
Derin öğrenme modelleri genellikle `float32` veri tipiyle eğitilir. Ancak bu verileri bir mikrodenetleyiciye yüklemek belleği hızla tüketir. Bu kütüphane:
- `float32`, `float16` ve `int8` (Quantized) verileri tek bir yapıda saklar.
- Bellek yönetimini `union` kullanarak optimize eder.
- Float verileri Quantization yöntemiyle küçülterek bellek tasarrufu sağlar.

Teknik Bileşenler
- **C Union Yapısı:** Aynı bellek adresini farklı veri tipleri gibi yorumlamayı sağlar.
- **Dinamik Tensör:** Bellek kısıtına göre hassasiyeti (precision) dinamik olarak ayarlar.
- **Quantization:** Veriyi `scale` ve `zero-point` kullanarak 8-bit tamsayıya sıkıştırır.

Kod Yapısı
- `tensor.h`: Dinamik tensör veri yapısının (`struct` & `union`) ve fonksiyon prototiplerinin bulunduğu başlık dosyası.
- `tensor.c`: Tip dönüşüm ve quantization algoritmalarının implementasyonu.
- `main.c`: Tensör oluşturma, matris yönetimi ve debugger üzerinden izleme demosu.

Örnek Kullanım
```c
DynamicTensor t;
// Tensörü 8-bit quantized modunda başlat
create_tensor(&t, 10, 10, TENSOR_INT8);

// Float veriyi Quantize et (Hassasiyet kaybı minimaldir)
int8_t q_val = quantize(0.75f, 0.01f, 0);
