#include <stdio.h>
#include <string.h>

#define TableSize 1024
#define ModSize 1024

int	hash(char *);

struct	tel{
	char	name[20];
	char	telnum[20];
} dat[TableSize];

int	main(void)
{
	int	n;
	char	a[20], b[20];

	printf("name tel\n");
	while (scanf("%s %s", a, b) != EOF) {
		n = hash(a);
		strcpy(dat[n].name, a);
		strcpy(dat[n].telnum, b);
	}
	rewind(stdin);//?
	printf("please search data\n");
	while (scanf("%s", a) != EOF) {
		n = hash(a);
		printf("%15s%15s\n", dat[n].name, dat[n].telnum);
		printf("[hash(a)]%d\n", hash(a));
	}
	return (0);
}

int	hash(char *s)
{
	int	n;

	n = strlen(s);
	return (s[0]-'A'+(s[n/2-1]-'A')*26+(s[n-2]-'A')*26*26) % ModSize;
}
