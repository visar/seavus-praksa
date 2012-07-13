#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int num;
	struct node * prev;
	struct node * next;
} jazel;

typedef struct node_single
{
	int num;
	struct node_single * next;
} jazel_single;

void insert(jazel **, int);
void insertS(jazel_single **, int);
void pecati(jazel *);
void pecatiS(jazel_single *);
void reverse(jazel **);
void reverseS(jazel_single **);

int main(int argc, char * argv[])
{
	int broj;
	jazel * lista = NULL;
	jazel_single *lista_edinecna = NULL;

	printf("DVOJNA\n");
	printf("Vnesi integer za dodavanje vo lista, za kraj vnesi bilo sto razlicno od broj:\n");
	while (scanf("%d", &broj) == 1)
	{
		insert(&lista, broj);
		printf("Vnesi integer za dodavanje vo lista, za kraj vnesi bilo sto razlicno od broj:\n");
	}

	printf("*****\nPRED:\n*****\n");
	pecati(lista);
	reverse(&lista);
	printf("*****\nPOTOA:\n*****\n");
	pecati(lista);

	jazel * tmp;
	jazel * kraj = lista->prev;
	while (lista != kraj)
	{
		tmp = lista->next;
		free(lista);
		lista = tmp;
	}
	free(kraj);

	getchar();
	printf("EDINECNA\n");
	printf("Vnesi integer za dodavanje vo lista, za kraj vnesi bilo sto razlicno od broj:\n");
	while (scanf("%d", &broj) == 1)
	{
		insertS(&lista_edinecna, broj);
		printf("Vnesi integer za dodavanje vo lista, za kraj vnesi bilo sto razlicno od broj:\n");
	}
	printf("*****\nPRED:\n*****\n");
	pecatiS(lista_edinecna);
	reverseS(&lista_edinecna);
	printf("*****\nPOTOA:\n*****\n");
	pecatiS(lista_edinecna);

	jazel_single * tmp1;
	while (lista_edinecna)
	{
		tmp1 = lista_edinecna->next;
		free(lista_edinecna);
		lista_edinecna = tmp1;
	}


	return 0;
}

void insert(jazel **l, int n)
{
	if (*l == NULL)
	{
		*l = (jazel *)malloc(sizeof(jazel));
		(*l)->prev = (*l)->next = *l;
		(*l)->num = n;
		return;
	}
	jazel * tmp = (jazel *)malloc(sizeof(jazel));
	tmp->num = n;
	tmp->next = *l;
	tmp->prev = (*l)->prev;
	(*l)->prev->next = tmp;
	(*l)-> prev = tmp;
}

void insertS(jazel_single **l, int n)
{
	if (*l == NULL)
	{
		*l = (jazel_single *)malloc(sizeof(jazel_single));
		(*l) -> next = NULL;
		(*l)->num = n;
		return;
	}
	jazel_single * tmp = (jazel_single *)malloc(sizeof(jazel_single));
	tmp->num = n;
	tmp->next = *l;
	*l = tmp;
}


void pecati(jazel *l)
{
	jazel * aux = l;
	do
	{
		printf("%d ", l->num);
		l = l->next;
	}
	while (l != aux);
	putchar('\n');
}

void pecatiS(jazel_single *l)
{
	while (l)
	{
		printf("%d ", l->num);
		l = l->next;
	}
	putchar('\n');
}

void reverse(jazel **l)
{
	jazel * aux = *l;
	jazel * tmp;
	do
	{
		tmp = (*l)->next;
		(*l)->next = (*l)->prev;
		(*l)->prev = tmp;
		*l = (*l)->next;
	}
	while (*l != aux);
	*l = (*l)->next;
}

void reverseS(jazel_single **l)
{
	jazel_single *m = NULL;
	jazel_single *n = *l;
	jazel_single *p = (*l)->next;
	while (p)
	{
		n->next = m;
		m = n;
		n = p;
		p = p->next;
	}
	n->next = m;
	*l = n;
}
