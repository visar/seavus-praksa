#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
	int data;					/**< Data pole vo jazel na drvo  */
	struct tree * lchild;		/**<  Levo dete  */
	struct tree * rchild;		/**<  Desno dete  */
} tree;

void inorder(tree *);
void insert(tree **, int);
int delete(tree **, int);
int empty(tree *);

/**
 * @name main - Main funkcija, kade sto se povikuvaat funkciite za vnesuvanje, brisenje i pecatenje na drvo vo inorder izminuvanje
 * @param argc - Broj na argumenti
 * @param argv - Vektor na argumenti
 * @return int
 */
int main(int argc, char * argv[])
{
	int x;
	tree * T = NULL;

	printf("Vnesi nov element:\t");

	while (scanf("%d", &x) == 1)
	{
		printf("Vnesi nov element:\t");
		insert(&T, x);
	}
	inorder(T);
	putchar('\n');
	getchar();

	while(1)
	{
		if (empty(T))
		{
			printf("Drvoto e prazno!\n");
			break;
		}

		printf("Vnesi koj element sakas da go izbrisam, za kraj vnesi bilo sto razlicno od integer:\n");
		if (scanf("%d", &x) != 1)
		{
			printf("Ova e krajnata sostojba:\n");
			inorder(T);
			putchar('\n');
			printf("Cao!\n");
			break;
		}
		if (!delete(&T, x))
		{
			printf("Posle brisenjeto na %d\n", x);
			inorder(T);
			putchar('\n');
		}
	}

	return EXIT_SUCCESS;
}
/**
 * @name empty - Proveruva dali drvoto e prazno
 * @param t -  drvo
 * @return int
 */
int empty(tree * t)
{
	return t == NULL;
}
/**
 * @name insert - Vnesuva nov element vo drvo
 * @param t -  drvo
 * @param val - Element koj se vnesuva
 * @return void
 */
void insert(tree ** t, int val)
{
	if (empty(*t))
	{
		tree * node = (tree *)malloc(sizeof(tree));
		node->data = val;
		node->lchild = node->rchild = NULL;
		*t = node;
		return;
	}
	if (val < (*t)->data)
		insert(&((*t)->lchild), val);
	else //if (val > (*t)->data)
		insert(&((*t)->rchild), val);
}
/**
 * @name inorder - Inorder izminuvanje na drvo
 * @param t -  drvo
 * @return void
 */
void inorder(tree *t)
{
	if (empty(t))
		return;
	inorder(t->lchild);
	printf("%d\t", t->data);
	inorder(t->rchild);
}
/**
 * @name search - Prebaruva vo drvoto dali postoi jazel so data pole ednakvo na vrednosta na val, ako postoi vraka pokazuvac kon toj jazel; dokolku ne postoi vraka NULL. Vo parent se smestuva roditelot koj pokazuva kon jazelot so data pole val, dodeka vo tag se smestuva informacijata dali jazelot e levo ili desno dete na svojot roditel
 * @param t -  drvo
 * @param val - vrednost koja se prebaruva
 * @param parent -  roditel
 * @param tag - tag karakter vo koj se zacuvuva informacijata dali jazelot e desno ili levo od svojot roditel
 * @return tree*
 */
tree * search(tree *t, int val, tree ** parent, char * tag)
{
	if (t == NULL)
		return NULL;
	if (t->data == val)
	{
		return t;
	}
	*parent = t;
	if (val < t->data)
	{
		*tag = 'l';
		return search(t->lchild, val, parent, tag);
	}
	*tag = 'r';
	return search(t->rchild, val, parent, tag);
}
/**
 * @name delete - Brise jazel so data pole ednakvo na val, dokolku postoi vo drvoto. Vraka int vo zavisnost dali brisenjeto e uspesno (0) ili neuspesno (-1)
 * @param t -  drvo
 * @return int
 */
int delete(tree **t, int val)
{
	tree * parent = NULL;
	char tag = 'c';
	tree * p = search(*t, val, &parent, &tag); /* pronajdi go jazelot (p) cie data pole e ednakvo na
												  val - vrednosta sto sakame da ja izbriseme od
												  drvoto, parent e negoviot roditel, dodeka tag
												  oznacuva dali p e desno (tag == 'r') ili levo
												  (tag == 'l') dete na negoviot roditel (parent)
												*/
	if (empty(p))
	{
		printf("Takov element ne postoi.\n");
		return -1;
	}

	if (empty(p->lchild) && empty(p->rchild)) /* jazel bez deca */
	{
		if (p == *t)			/* koren bez deca */
		{
			free(*t);
			*t = NULL;
			return 0;
		}

		free(p);
		p = NULL;

		if (tag == 'r')			/* jazelot sto treba da se brise e desno dete
								   na negoviot roditel
								*/
		{
			parent->rchild = NULL;
		}
		else					/* jazelot sto treba da se brise e levo dete
								   na negoviot roditel
								 */
		{
			parent->lchild = NULL;
		}

		return 0;
	}

	if (empty(p->rchild))		/* jazel bez desno dete */
	{
		if (p == *t)			/* koren bez desno dete */
		{
			*t = p->lchild;
			free(p);
			return 0;
		}

		if (tag == 'r')			/* jazelot sto treba da se brise e desno dete na
								   negoviot roditel, zatoa desniot link na roditelot na jazelot
								   sto se brise ke pokazuva na levoto dete na jazelot sto se brise
								*/
		{
			parent->rchild = p->lchild;
		}
		else					/* jazelot sto treba da se brise e levo dete na
								   negoviot roditel, zatoa leviot link na roditelot na jazelot
								   sto se brise ke pokazuva na levoto dete na jazelot sto se brise
								 */
		{
			parent->lchild = p->lchild;
		}

		free(p);
		return 0;
	}

	if (empty(p->lchild))		/* jazel bez levo dete */
	{
		if (p == *t)			/* koren bez levo dete */
		{
			*t = p->rchild;
			free(p);
			return 0;
		}

		if (tag == 'r')			/* jazelot sto treba da se brise e desno dete na
								   negoviot roditel, zatoa desniot link na roditelot na jazelot
								   sto se brise ke pokazuva na desnoto dete na jazelot sto se brise
								 */
		{
			parent->rchild = p->rchild;
		}
		else					/* jazelot sto treba da se brise e levo dete na
								   negoviot roditel, zatoa leviot link na roditelot na jazelot
								   sto se brise ke pokazuva na desnoto dete na jazelot sto se brise
								 */
		{
			parent->lchild = p->rchild;
		}
		free(p);
		return 0;
	}

/* jazelot sto treba da se brise ima dve deca, zatoa na mestoto na toj jazel go stavame
   najmaliot jazel na desnoto pod-drvo za da ne se gubi podredenosta;
   t.e. go barame najleviot jazel na desnoto pod-drvo (istiot efekt bi se dobil ako go
   barame najdesniot jazel na levoto pod-drvo)
 */

	tree * q = p->rchild;		/* q ke pokazuva na najleviot jazel vo desnoto pod-drvo */
	tree * r = p;				/* r ke pokazuva na roditelot na q */

	while (!empty(q->lchild))
	{
		r = q;
		q = q->lchild;
	}
	p->data = q->data;

	if (r->rchild == q)			/* desnoto pod-drvo na jazelot sto ke go briseme nema levo pod-drvo
								   zatoa desniot link na r ke pokazuva na desnoto pod-drvo na
								   q (koe moze da bide i prazno, t.e. NULL)*/
	{
		r->rchild = q->rchild;
		free(q);
		q = NULL;
		return 0;
	}

/*  Vo ovoj moment q pokazuva na najleviot jazel na desnoto pod-drvo na jazelot sto treba da se brise
	dodeka r e negov roditel, t.e. q se naogja levo od r, zatoa posle ova leviot link na r
	ke pokaze na desnoto pod-drvo na q (koe moze da bide i prazno, t.e. NULL)
*/
	r->lchild = q->rchild;
	free(q);
	q = NULL;

	return 0;
}
