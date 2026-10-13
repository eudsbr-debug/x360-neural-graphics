#include <stdint.h>
#include <stdio.h>

void xng_upscale_bilinear(
    const uint8_t *, int, int, uint8_t *, int, int
);

int main(void) {
    /* Uma imagem 2x2 uniforme deve continuar uniforme. */
    uint8_t src[16] = {
        80,100,120,255, 80,100,120,255,
        80,100,120,255, 80,100,120,255
    };
    uint8_t dst[64] = {0};

    xng_upscale_bilinear(src, 2, 2, dst, 4, 4);

    for (int i = 0; i < 16; ++i) {
        if (dst[i*4] != 80 ||
            dst[i*4+1] != 100 ||
            dst[i*4+2] != 120 ||
            dst[i*4+3] != 255) {
            fprintf(stderr, "FAIL: pixel %d\n", i);
            return 1;
        }
    }

    puts("PASS: bilinear upscale");
    return 0;
}
