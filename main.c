#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    int tip; 
    int satir, sutun; 

    union {
        float* f32_ptr;
        int8_t* i8_ptr;
    } veri; 
} Tensor;


int8_t quantize(float deger) {
    float scale = 127.0f; 
    return (int8_t)(deger * scale);
}

int main() {
    printf("--- TinyML Dinamik Tensor Projesi Baslatildi ---\n");

    int r = 2, c = 2; 
    int toplam_eleman = r * c;

    Tensor t_high;
    t_high.tip = 0;
    t_high.satir = r; t_high.sutun = c;
    t_high.veri.f32_ptr = (float*)malloc(toplam_eleman * sizeof(float));
    t_high.veri.f32_ptr[0] = 0.5f; 

    Tensor t_low;
    t_low.tip = 1;
    t_low.veri.i8_ptr = (int8_t*)malloc(toplam_eleman * sizeof(int8_t));

    t_low.veri.i8_ptr[0] = quantize(t_high.veri.f32_ptr[0]);

    printf("Float Deger: %.2f (Boyut: %lu byte)\n", t_high.veri.f32_ptr[0], sizeof(float));
    printf("Quantized Deger: %d (Boyut: %lu byte)\n", t_low.veri.i8_ptr[0], sizeof(int8_t));
    
    free(t_high.veri.f32_ptr);
    free(t_low.veri.i8_ptr);

    return 0;
}