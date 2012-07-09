#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef char * STR;

int words(char *);
int chop(char *, char * []);
int nLetters(const char *);
int strCmp(const void *, const void *);

int main(int argc, char * argv[])
{
	int num, i;
	num = words(argv[1]);
	char ** word;
	word = (char **)malloc(num*sizeof(char *));
	num = chop(argv[1],word);
	qsort(word, num, sizeof(char *), strCmp);
	i = 0;
	while (i < num)
	{
		printf("%s\n", word[i++]);
	}
	free(word);
	return 0;
}

int words(char * str)
{
	int counter = 0;
	int inWord = 0;
	while (*str)
	{
		if (isalnum(*str)) {
			if (!inWord)
			{
				inWord = 1;
				counter++;
			}
		}
		else if (ispunct(*str) || isspace(*str))
		{
			inWord = 0;
		}
		str++;
	}
	return counter;
}

int chop(char * str, char * arr[])
{
	int count = 0;
	int inWord = 0;

	while (*str)
	{
		if (isalnum(*str)) {
			if (!inWord)
			{
				arr[count++] = str;
				inWord = 1;
			}
		}
		else if (ispunct(*str) || isspace(*str))
		{
			if (inWord)
			{
				*str = '\0';
				inWord = 0;
			}
		}
		str++;
	}
	return count;
}

int nLetters(const char * str)
{
	int counter = 0;
	while (*str)
	{
		counter++;
		str++;
	}

	return counter;
}

int strCmp(const void *a, const void *b)
{
	const char **ia = (const char **)a;
	const char **ib = (const char **)b;
	return nLetters(*ia) - nLetters(*ib);
}
