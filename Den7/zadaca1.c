#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

typedef struct
{
	unsigned char broj : 4;
	unsigned char boja : 2;
} karta;

char tmp[52] = {0};

void meshaj(karta *);
void print(karta *);
karta deli(karta *);
void hand(karta *, karta *);
int par(karta *);
int dvaPara(karta *);
int triling(karta *);
int cetiri(karta *);
int boja(karta *);
int kenta(karta *);

int compare (const void *, const void *);

int main(int argc, char * argv[])
{
	karta karti[52];

	meshaj(karti);
	/* print(karti); */

	int brojac = 52;
	while (brojac--)
	{
		tmp[brojac] = 0;
	}

	putchar('\n');
	karta card = deli(karti);
	printf("%d %d\n", card.broj, card.boja);

	brojac = 52;
	while (brojac--)
	{
		tmp[brojac] = 0;
	}

	karta raka[5];
	hand(karti, raka);
	brojac = 5;
	while (brojac--)
	{
		printf("%d %d\n", raka[brojac].broj, raka[brojac].boja);
	}

	printf("%d\n", par(raka));
	printf("%d\n", dvaPara(raka));
	printf("%d\n", triling(raka));
	printf("%d\n", cetiri(raka));
	printf("%d\n", boja(raka));
	printf("%d\n", kenta(raka));

	raka[4].broj = 7;
	raka[3].broj = 6;
	raka[2].broj = 6;
	raka[1].broj = 4;
	raka[0].broj = 4;

	brojac = 5;
	while (brojac--)
	{
		printf("%d %d\n", raka[brojac].broj, raka[brojac].boja);
	}

	printf("%d\n", par(raka));
	printf("%d\n", dvaPara(raka));
	printf("%d\n", triling(raka));
	printf("%d\n", cetiri(raka));
	printf("%d\n", boja(raka));
	printf("%d\n", kenta(raka));

	raka[4].broj = 8;
	raka[3].broj = 7;
	raka[2].broj = 6;
	raka[1].broj = 6;
	raka[0].broj = 6;

	brojac = 5;
	while (brojac--)
	{
		printf("%d %d\n", raka[brojac].broj, raka[brojac].boja);
	}

	printf("%d\n", par(raka));
	printf("%d\n", dvaPara(raka));
	printf("%d\n", triling(raka));
	printf("%d\n", cetiri(raka));
	printf("%d\n", boja(raka));
	printf("%d\n", kenta(raka));

	raka[4].broj = 7;
	raka[3].broj = 6;
	raka[2].broj = 6;
	raka[1].broj = 6;
	raka[0].broj = 6;

	brojac = 5;
	while (brojac--)
	{
		printf("%d %d\n", raka[brojac].broj, raka[brojac].boja);
	}

	printf("%d\n", par(raka));
	printf("%d\n", dvaPara(raka));
	printf("%d\n", triling(raka));
	printf("%d\n", cetiri(raka));
	printf("%d\n", boja(raka));
	printf("%d\n", kenta(raka));

	raka[4].boja = 1;
	raka[3].boja = 1;
	raka[2].boja = 1;
	raka[1].boja = 1;
	raka[0].boja = 1;

	raka[4].broj = 7;
	raka[3].broj = 6;
	raka[2].broj = 5;
	raka[1].broj = 3;
	raka[0].broj = 1;

	brojac = 5;
	while (brojac--)
	{
		printf("%d %d\n", raka[brojac].broj, raka[brojac].boja);
	}

	printf("%d\n", par(raka));
	printf("%d\n", dvaPara(raka));
	printf("%d\n", triling(raka));
	printf("%d\n", cetiri(raka));
	printf("%d\n", boja(raka));
	printf("%d\n", kenta(raka));


	raka[4].boja = 1;
	raka[3].boja = 1;
	raka[2].boja = 1;
	raka[1].boja = 1;
	raka[0].boja = 1;

	raka[4].broj = 7;
	raka[3].broj = 6;
	raka[2].broj = 5;
	raka[1].broj = 4;
	raka[0].broj = 3;

	brojac = 5;
	while (brojac--)
	{
		printf("%d %d\n", raka[brojac].broj, raka[brojac].boja);
	}

	printf("%d\n", par(raka));
	printf("%d\n", dvaPara(raka));
	printf("%d\n", triling(raka));
	printf("%d\n", cetiri(raka));
	printf("%d\n", boja(raka));
	printf("%d\n", kenta(raka));

	brojac = 52;
	while (brojac--)
	{
		tmp[brojac] = 0;
	}

	meshaj(karti);
	printf("\nMesanje karti\n");

	brojac = 52;
	while (brojac--)
	{
		tmp[brojac] = 0;
	}

	printf("\n\nDelenje karti na dva igraci:\n");
	karta raka1[5], raka2[5];
	hand(karti, raka1);
	hand(karti, raka2);
	printf("\nPrv igrac:\n");
	brojac = 5;
	while (brojac--)
	{
		printf("%d %d\n", raka1[brojac].broj, raka1[brojac].boja);
	}

	printf("\nPrv igrac:\n");
	brojac = 5;
	while (brojac--)
	{
		printf("%d %d\n", raka2[brojac].broj, raka2[brojac].boja);
	}
	putchar('\n');

	printf("%d\n", par(raka1));
	printf("%d\n", dvaPara(raka1));
	printf("%d\n", triling(raka1));
	printf("%d\n", cetiri(raka1));
	printf("%d\n", boja(raka1));
	printf("%d\n", kenta(raka1));

	putchar('\n');

	printf("%d\n", par(raka2));
	printf("%d\n", dvaPara(raka2));
	printf("%d\n", triling(raka2));
	printf("%d\n", cetiri(raka2));
	printf("%d\n", boja(raka2));
	printf("%d\n", kenta(raka2));

	int dobitniPrv[6], dobitniVtor[6];

	dobitniPrv[0] = par(raka1);
	dobitniPrv[1] = dvaPara(raka1);
	dobitniPrv[2] = triling(raka1);
	dobitniPrv[3] =	cetiri(raka1);
	dobitniPrv[4] =	boja(raka1);
	dobitniPrv[5] = kenta(raka1);

	dobitniVtor[0] = par(raka2);
	dobitniVtor[1] = dvaPara(raka2);
	dobitniVtor[2] = triling(raka2);
	dobitniVtor[3] = cetiri(raka2);
	dobitniVtor[4] = boja(raka2);
	dobitniVtor[5] = kenta(raka2);

	int max1 = -1, max2 = -1;

	brojac = 6;
	while (brojac--)
	{
		if (dobitniPrv[brojac] == 1)
		{
			max1 = brojac;
			break;
		}
	}


	brojac = 6;
	while (brojac--)
	{
		if (dobitniVtor[brojac] == 1)
		{
			max2 = brojac;
			break;
		}
	}

	printf("Pobednik e %s\n", max1 > max2 ? "prviot" : max1 < max2 ? "vtoriot" : "nikoj");

	printf("Prviot ima: ");
	switch(max1)
	{
	case 5: printf("kenta\n"); break;
	case 4: printf("boja\n"); break;
	case 3: printf("cetiri karti so ist broj\n"); break;
	case 2: printf("triling\n"); break;
	case 1: printf("dva para\n"); break;
	case 0: printf("par\n"); break;
	default: printf("nisto\n"); break;
	}

	printf("Vtoriot ima: ");
	switch(max2)
	{
	case 5: printf("kenta\n"); break;
	case 4: printf("boja\n"); break;
	case 3: printf("cetiri karti so ist broj\n"); break;
	case 2: printf("triling\n"); break;
	case 1: printf("dva para\n"); break;
	case 0: printf("par\n"); break;
	default: printf("nisto\n"); break;
	}

	return 0;
}

void meshaj(karta * p)
{
	srand(time(NULL));
	int brojac = 52;
	int card;
	while (brojac--)
	{
		do
		{
			card = (double)rand() / RAND_MAX * 52;
			/* printf("brojac: %d card: %d\n", brojac, card); */
		}
		while (tmp[card] == 1);
		p[brojac].broj = card % 13 + 1;
		p[brojac].boja = card / 13;
		tmp[card] = 1;
	}
}

karta deli(karta *p)
{
	int card;
	do
	{
		card = (double)rand() / RAND_MAX * 52;
	}
	while (tmp[card] == 1);
	tmp[card] = 1;

	return p[card];
}

void hand(karta * spil, karta *p)
{
	int brojac = 5;
	while (brojac--)
	{
		p[brojac] = deli(spil);
	}
	qsort(p, 5, sizeof(karta), compare);
}

int par(karta *p)
{
	int brojac = 5;
	int ima = 0;
	while (brojac-- > 1)
	{
		if (p[brojac].broj == p[brojac-1].broj)
		{
			ima = 1;
			break;
		}
	}
	return ima;
}

int dvaPara(karta *p)
{
	if (!par(p))
		return 0;
	int brojac = 5;
	int ima = 0;
	int prv = 0;
	while (brojac-- > 1)
	{
		if (p[brojac].broj == p[brojac-1].broj)
		{
			if (!prv)
				prv = 1;
			else
			{
				ima = 1;
				break;
			}
			brojac--;
		}
	}
	return ima;
}

int triling(karta *p)
{
	if (!par(p))
		return 0;

	int brojac = 5;
	int ima = 0;
	while (brojac-- > 2)
	{
		if (p[brojac].broj == p[brojac-1].broj &&
			p[brojac-1].broj == p[brojac-2].broj)
		{
			ima = 1;
			break;
		}
	}
	return ima;
}

int cetiri(karta *p)
{
	int brojac = 5;
	int ima = 0;
	if (!dvaPara(p))
		return 0;
	while (brojac-- > 3)
	{
		if (p[brojac].broj == p[brojac-1].broj &&
			p[brojac-1].broj == p[brojac-2].broj &&
			p[brojac-2].broj == p[brojac-3].broj)
		{
			ima = 1;
			break;
		}
	}
	return ima;
}

int boja(karta *p)
{
	return (p[4].boja == p[3].boja && p[3].boja == p[2].boja &&
			p[2].boja == p[1].boja && p[1].boja == p[0].boja);
}

int kenta(karta *p)
{
	if (!boja(p))
		return 0;
	int brojac = 5;
	int ima = 1;
	while (brojac-- > 1)
	{
		if (p[brojac].broj-1 != p[brojac-1].broj)
		{
			ima = 0;
			break;
		}
	}
	return ima;
}
void print(karta *p)
{
	int brojac = 52;
	while(brojac--)
	{
		printf("%d: %d %d\n", brojac, p[brojac].broj, p[brojac].boja);
	}
}

int compare (const void * a, const void * b)
{
	karta * sa = (karta *) a;
	karta * sb = (karta *) b;
	return (sa->broj - sb->broj);
}
