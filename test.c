#include <stdio.h>

int	mandelbrot(float c1, float c2)
{
	float	z1;
	float	z1_new;
	float	z2;
	int	n;

	z1 = 0;
	z1_new = 0;
	z2 = 0;
	n = 0;
	while (n < 50)
	{
		z1_new = (z1 * z1) - (z2 * z2) + c1;
		z2 = (2 * z1 * z2) + c2;
		z1 = z1_new;
		if (z1 * z1 + z2 * z2 >= 4)
			return (0);
		n++;
	}
	return (n);
}

int main()
{
	if (mandelbrot(-0.998,1) == 50)
		printf("red\n");
}
