#include <stdio.h>
#include <stdlib.h>

int chop(char *, char **, char);

int main(int argc, char * argv[])
{
	int nbytes = 0;
	char *str = (char *) malloc (1);
	char delimiter;
	printf("Vnesi niza od karakteri:\n");
	int num = getline(&str, (size_t *)&nbytes, stdin);
	str[num-1] = '\0';
	num--;
	char ** parts = (char **)malloc(num*sizeof(char *));
	printf("Vnesi delimiter: ");
	scanf("%c", &delimiter);
	num = chop(str, parts, delimiter);
	int i = 0;
	while (i < num)
	{
		printf("%s\n", parts[i++]);
	}

	free(parts);

	return 0;
}

int chop(char * str, char * arr[], char delim)
{
	int count = 0;
	int in = 0;

	while (*str)
	{
		if (*str == delim)
		{
			*str = '\0';
			in = 0;
		}
		else if (!in)
		{
			arr[count++] = str;
			in = 1;
		}
		str++;
	}
	return count;
}
