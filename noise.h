#ifndef NOISE_H
#define NOISE_H


struct noise {
    int p[256];
    float gx[256];
	float gy[256];
	float gz[256];
};

extern float noise_xyz(struct noise n, float sample_x, float sample_y, float sample_z);
extern struct noise noise_init();

struct fractal_noise {
    struct noise n;
	int octaves;
	float lacunarity;
	float persistence;
	float base_freq;
    float base_amp;
};

extern float fractal_noise_xyz (struct fractal_noise frac, float sample_x, float sample_y, float sample_z);
extern struct fractal_noise fractal_noise_init();

#endif