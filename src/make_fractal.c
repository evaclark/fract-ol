
#include "fractol.h"

void    draw_fractal(t_data *var)
{
	int             x;
        int             y;
        double  cr;
        double  ci;

        y = -1;
        while (++y < 1000)
        {
                x = -1;
                while (++x < 1000)
                {
                        cr = var->min_r + (double)x * (var->max_r - var->min_r) / WIDTH;
                        ci = var->min_i + (double)y * (var->max_i - var->min_i) / HEIGHT;
                        mandelbrot(var, x, y, cr, ci);
                }
        }
}
