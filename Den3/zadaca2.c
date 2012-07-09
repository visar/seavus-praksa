#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

int main()
{
	unsigned obidi = 5;
	srand(time(NULL));
	unsigned broj = (unsigned)((double)rand() / RAND_MAX * 32) + 1;
	unsigned guess;
	printf("Obidete se da pogodite broj pomegju 1 i 32\n");
	while (obidi--)
	{
		scanf("%d", &guess);
		if (broj == guess)
		{
			printf("BRAVO!\n");
			break;
		}
		else
		{
			printf("Vneseniot broj e %s od vistinskiot. Preostanati obidi: %d\n", (guess < broj ? "pomal": "pogolem"), obidi);
		}
	}
	return 0;
}
