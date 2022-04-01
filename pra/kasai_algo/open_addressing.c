#include <stdio.h>
#include <string.h>

#define TableSize 1024
#define ModSize 1024

int	hash(char *);

struct	tel{
	char	name[20];
	char	telnum[20];
	int		empty;
} dat[TableSize];

int	main(void)
{
	int	n;
	char	a[20], b[20];

	printf("name tel\n");
	while (scanf("%s %s", a, b) != EOF) {
		n = hash(a);
		while (dat[n].empty == 1 && n < TableSize)
			n++;
		if (n < TableSize) {
			strcpy(dat[n].name, a);
			strcpy(dat[n].telnum, b);
			dat[n].empty = 1;
		}
		else
			printf("table is full!!\n");
	}
	rewind(stdin);//?
	printf("please search data\n");
	while (scanf("%s", a) != EOF) {
		n = hash(a);
		while (strcmp(a, dat[n].name) != 0 && n < TableSize)
			n++;
		if (n < TableSize) {
			printf("%15s%15s\n", dat[n].name, dat[n].telnum);
			printf("[hash(a)]%d\n", n);
		}
		else
			printf("Not Found\n");
	}
	return (0);
}

int	hash(char *s)
{
	int	n;

	n = strlen(s);
	return (s[0]-'A'+(s[n/2-1]-'A')*26+(s[n-2]-'A')*26*26) % ModSize;
}
