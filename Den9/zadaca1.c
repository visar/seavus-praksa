#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LENGTH 20

typedef struct vraboten
{
	int ID;
	char ime[LENGTH];
	char prezime[LENGTH];
	unsigned vozrast;
	char pol;
	char bracnaSostojba[LENGTH];
	int kredibilnost;
	char adresa[2*LENGTH];
	unsigned tekovnaPlata;
	unsigned poranesnaPlata;
} vraboten;

vraboten vnesiVraboten(int);
void print(vraboten *, int);
void printCustom(vraboten *, int, char);
void sort_kred(vraboten *, int);
void sort_tekovnaPlata(vraboten *, int);
void sort_minataPlata(vraboten *, int);
void koregiraj_vraboten(vraboten *, int, int);
void koregiraj_kredibilnost(vraboten *, int);

int main(int argc, char * argv[])
{
	printf("Zdravo korisniku!\n");
	printf("Dali znaes kolku vraboteni ke vneses? Ako ne znaes ne e strasno, samo vnesi gi vrabotenite, jas ke gi brojam za tebe! ;) \nOdgovori so DA/NE\n");
	char odgovor2[] = "NE";
	if (!scanf("%s", odgovor2))
		exit(EXIT_FAILURE);
	char *t = odgovor2;
	while (*t)
	{
		*t = toupper(*t);
		t++;
	}
	int size = 1;

	if (!strcmp(odgovor2, "DA"))
	{
		printf("Vnesi go brojot na vrabotenite: ");
		if (!scanf("%d", &size))
			exit(EXIT_FAILURE);
	}
	else
	{
		printf("OK jas ke gi brojam vrabotenite.\n");
	}
	getchar();

	vraboten * vraboteni = (vraboten *)malloc(size * sizeof(vraboten));
	int brVraboteni = 0;
	char odgovor[] = "DA";
	do
	{
		printf("Vnesi nov vraboten:\n");
		if (size <= brVraboteni)
		{
			size *= 2;
			vraboteni = (vraboten *)realloc(vraboteni, size * sizeof(vraboten));
		}
		vraboteni[brVraboteni] = vnesiVraboten(brVraboteni);
		brVraboteni++;
		printf("Dali sakate da vnesete nov vraboten? (DA/NE)\n");
		if (scanf("%s", odgovor) != 1)
			exit(EXIT_FAILURE);
		getchar();
		char * s = odgovor;
		while (*s)
		{
			*s = toupper(*s);
			s++;
		}
	}
	while (!strcmp(odgovor,"DA"));

	print(vraboteni, brVraboteni);

	printf("\nSortirani spored kredibilnost:\n");
	sort_kred(vraboteni, brVraboteni);
	printCustom(vraboteni, brVraboteni, 'k');

	printf("\nSortirani spored tekovna plata:\n");
	sort_tekovnaPlata(vraboteni, brVraboteni);
	printCustom(vraboteni, brVraboteni, 't');

	printf("\nSortirani spored poranesna plata:\n");
	sort_minataPlata(vraboteni, brVraboteni);
	printCustom(vraboteni, brVraboteni, 'm');

	int korekcija;
	printf("\nKoj vraboten sakas da go koregiras:\n");
	if (!scanf("%d", &korekcija))
		exit(EXIT_FAILURE);
	getchar();
	/* korekcija = korekcija < brVraboteni ? korekcija : brVraboteni-1; */
	/* korekcija = korekcija >= 0 ? korekcija : 0; */
	koregiraj_vraboten(vraboteni, brVraboteni, korekcija);

	print(vraboteni, brVraboteni);

	printf("\nSortirani spored kredibilnost:\n");
	sort_kred(vraboteni, brVraboteni);
	printCustom(vraboteni, brVraboteni, 'k');

	printf("\nSortirani spored tekovna plata:\n");
	sort_tekovnaPlata(vraboteni, brVraboteni);
	printCustom(vraboteni, brVraboteni, 't');

	printf("\nSortirani spored poranesna plata:\n");
	sort_minataPlata(vraboteni, brVraboteni);
	printCustom(vraboteni, brVraboteni, 'm');

	koregiraj_kredibilnost(vraboteni, brVraboteni);
	print(vraboteni, brVraboteni);

	free(vraboteni);
	return EXIT_SUCCESS;
}

vraboten vnesiVraboten(int id)
{
	int nbytes = LENGTH;
	int num;
	char *str =(char *)malloc(LENGTH);
	vraboten nov;

	nov.ID = id;
	printf("%-20s\t", "Ime:");
	num = getline(&str, (size_t *)&nbytes, stdin);
	str[num-1] = '\0';			/* se brise \n na kraj sto go stava getline */
	strncpy(nov.ime, str, LENGTH-1);
	nov.ime[0] = toupper(nov.ime[0]);
	printf("%-20s\t", "Prezime:");
	num = getline(&str, (size_t *)&nbytes, stdin);
	str[num-1] = '\0';			/* se brise \n na kraj sto go stava getline */
	strncpy(nov.prezime, str, LENGTH-1);
	nov.prezime[0] = toupper(nov.prezime[0]);
	printf("%-20s\t", "Vozrast:");
	if (scanf("%d", &nov.vozrast) != 1)
		exit(EXIT_FAILURE);
	getchar();
	printf("%-20s\t", "Pol(M/Z):");
	if (scanf("%c", &nov.pol) != 1)
		exit(EXIT_FAILURE);
	nov.pol = toupper(nov.pol);
	getchar();
	while (nov.pol != 'M' && nov.pol != 'Z')
	{
		printf("Vnesi M za masko ili Z za zensko\n");
		if (scanf("%c", &nov.pol) != 1)
			exit(EXIT_FAILURE);
		nov.pol = toupper(nov.pol);
		getchar();
	}
	printf("%-20s\t", "Bracna sostojba:");
	num = getline(&str, (size_t *)&nbytes, stdin);
	str[num-1] = '\0';			/* se brise \n na kraj sto go stava getline */
	strncpy(nov.bracnaSostojba, str, LENGTH-1);
	printf("%-20s\t", "Kredibilnost:");
	if (scanf("%d", &nov.kredibilnost) != 1)
		exit(EXIT_FAILURE);
	nov.kredibilnost = nov.kredibilnost >= 0 ? nov.kredibilnost : 0;
	nov.kredibilnost = nov.kredibilnost <= 100 ? nov.kredibilnost : 100;
	getchar();
	printf("%-20s\t", "Adresa:");
	num = getline(&str, (size_t *)&nbytes, stdin);
	str[num-1] = '\0';			/* se brise \n na kraj sto go stava getline */
	strncpy(nov.adresa, str, 2*LENGTH-1);
	printf("%-20s\t", "Tekovna plata:");
	if (scanf("%d", &nov.tekovnaPlata) != 1)
		exit(EXIT_FAILURE);
	printf("%-20s\t", "Poranesna plata:");
	if (scanf("%d", &nov.poranesnaPlata) != 1)
		exit(EXIT_FAILURE);
	free(str);

	return nov;
}

void print(vraboten vr[], int br)
{
	int brojac = 0;
	for (brojac = 0; brojac < br; brojac++)
	{
		printf("%30s %d %31s\n", "------------------------------", vr[brojac].ID, "-------------------------------");
		printf("%-20s|\t%40s\n", "Ime",vr[brojac].ime);
		printf("%-20s|\t%40s\n", "Prezime",vr[brojac].prezime);
		printf("%-20s|\t%40d\n", "Vozrast", vr[brojac].vozrast);
		printf("%-20s|\t%40c\n", "Pol",vr[brojac].pol);
		printf("%-20s|\t%40s\n", "Bracna sostojba",vr[brojac].bracnaSostojba);
		printf("%-20s|\t%40d\n", "Kredibilnost",vr[brojac].kredibilnost);
		printf("%-20s|\t%40s\n", "Adresa",vr[brojac].adresa);
		printf("%-20s|\t%40d\n", "Tekovna plata",vr[brojac].tekovnaPlata);
		printf("%-20s|\t%40d\n", "Poranesna plata",vr[brojac].poranesnaPlata);
	}
}

void printCustom(vraboten vr[], int br, char tag)
{
	int brojac = 0;
	switch(tag)
	{
	case 'k':
		for (brojac = 0; brojac < br; brojac++)
		{
			printf("%30s %d %31s\n", "------------------------------", vr[brojac].ID, "-------------------------------");
			printf("%-20s|\t%40s\n", "Ime",vr[brojac].ime);
			printf("%-20s|\t%40s\n", "Prezime",vr[brojac].prezime);
			printf("%-20s|\t%40d\n", "Kredibilnost",vr[brojac].kredibilnost);
		}
		break;
	case 't':
		for (brojac = 0; brojac < br; brojac++)
		{
			printf("%30s %d %31s\n", "------------------------------", vr[brojac].ID, "-------------------------------");
			printf("%-20s|\t%40s\n", "Ime",vr[brojac].ime);
			printf("%-20s|\t%40s\n", "Prezime",vr[brojac].prezime);
			printf("%-20s|\t%40d\n", "Tekovna plata",vr[brojac].tekovnaPlata);
		}
		break;
	case 'm':
		for (brojac = 0; brojac < br; brojac++)
		{
			printf("%30s %d %31s\n", "------------------------------", vr[brojac].ID, "-------------------------------");
			printf("%-20s|\t%40s\n", "Ime",vr[brojac].ime);
			printf("%-20s|\t%40s\n", "Prezime",vr[brojac].prezime);
			printf("%-20s|\t%40d\n", "Poranesna plata",vr[brojac].poranesnaPlata);
		}
		break;
	default:
		printf("Nema takov tag!\n");
	}
}

int cmpKred (const void * a, const void * b)
{
	vraboten * pa = (vraboten *) a;
	vraboten * pb = (vraboten *) b;
	return (pb->kredibilnost - pa->kredibilnost);
}

void sort_kred(vraboten vr[], int br)
{
	qsort(vr, br, sizeof(vraboten), cmpKred);
}

int cmpTekovna (const void * a, const void * b)
{
	vraboten * pa = (vraboten *) a;
	vraboten * pb = (vraboten *) b;
	return (pb->tekovnaPlata - pa->tekovnaPlata);
}

void sort_tekovnaPlata(vraboten vr[], int br)
{
	qsort(vr, br, sizeof(vraboten), cmpTekovna);
}

int cmpMinata (const void * a, const void * b)
{
	vraboten * pa = (vraboten *) a;
	vraboten * pb = (vraboten *) b;
	return (pb->poranesnaPlata - pa->poranesnaPlata);
}

void sort_minataPlata(vraboten vr[], int br)
{
	qsort(vr, br, sizeof(vraboten), cmpMinata);
}

int search(vraboten vr[], int br, int id)
{
	int brojac;

	for (brojac = 0; brojac < br; brojac++)
	{
		if (vr[brojac].ID == id)
			return brojac;
	}
	return -1;
}

void koregiraj_vraboten(vraboten vr[], int br, int id)
{
	int id2 = search(vr, br, id);
	if (id2 == -1)
	{
		printf("Nema takvo ID!\n");
		exit(EXIT_FAILURE);
	}
	vr[id2] = vnesiVraboten(id);
}

void koregiraj_kredibilnost(vraboten vr[], int br)
{
	int brojac;
	int tmp;

	for (brojac = 0; brojac < br; brojac++)
	{
		if (vr[brojac].tekovnaPlata > vr[brojac].poranesnaPlata)
		{
			vr[brojac].kredibilnost += 3;
			vr[brojac].kredibilnost = vr[brojac].kredibilnost <= 100 ? vr[brojac].kredibilnost : 100;
			tmp = vr[brojac].tekovnaPlata;
			vr[brojac].tekovnaPlata = vr[brojac].poranesnaPlata;
			vr[brojac].poranesnaPlata = tmp;
		}
		else if (vr[brojac].tekovnaPlata < vr[brojac].poranesnaPlata)
		{
			vr[brojac].kredibilnost -= 3;
			vr[brojac].kredibilnost = vr[brojac].kredibilnost >= 0 ? vr[brojac].kredibilnost : 0;
			tmp = vr[brojac].tekovnaPlata;
			vr[brojac].tekovnaPlata = vr[brojac].poranesnaPlata;
			vr[brojac].poranesnaPlata = tmp;
		}
	}
}
