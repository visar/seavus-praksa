#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	int brojac = 0;
	double broj;
	double * p = (int *)malloc(sizeof(double));
	int size = 1;
	printf("Vnesi broj, za kraj vnesi bilo sto razlicno od broj: ");
	while (scanf("%lf", &broj))
	{
		if (size <= brojac) {
			size *= 2;
			p = (double *)realloc(p, size * sizeof(double));
		}
		p[brojac++] = broj;
		printf("Vnesi broj, za kraj vnesi bilo sto razlicno od broj: ");
	}
	int j = 0;
	double avrg = 0.0;
	for (j = 0; j < brojac; j++)
	{
		avrg += p[j];
	}
	avrg /= brojac;
	printf("Prosek: %.2lf\n", avrg);
	free(p);
	return 0;
}
