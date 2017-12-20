#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "noise.h"

int main (int argc, char *argv[]) {
    srand ((unsigned)time(NULL));

    struct fractal_noise n = fractal_noise_init();
    n.base_freq = 0.01;

    int x, y = rand() % 512;
    float noise = fractal_noise_xyz(n, x, y, 0.1);

    // clamp to 0.0 - 1.0
    float clamp = noise;
    clamp += 1.0f;
    clamp *= 0.5f;

    unsigned short color = clamp * 255;

    printf("noise\n raw %f\n clamp %f\n color %u", noise, clamp, color);
}