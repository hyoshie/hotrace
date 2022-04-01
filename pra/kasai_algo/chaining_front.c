#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TableSize 1024
#define ModSize 1024

int	hash(char *);

struct	tfield{
	char			name[20];
	char			telnum[20];
	struct tfield	*next;
} *dat[TableSize]; //Pointer Table

struct tfield	*talloc(void);

int	main(void)
{
	int	n;
	char	key[20];
	struct tfield	*p;

	for (int i = 0; i < TableSize; i++) {
		dat[i] = NULL;
	}

	printf("name tel\n");
	while (p = talloc(), scanf("%s %s", p->name, p->telnum) != EOF) {
		n = hash(p->name);
		//add front
		p->next = dat[n];
		dat[n] = p;
	}
	rewind(stdin);//?
	printf("please search data\n");
	while (scanf("%s", key) != EOF) {
		n = hash(key);
		p = dat[n];
		while (p != NULL)
		{
			if (strcmp(key, p->name) == 0) {
				printf("%15s%15s\n", p->name, p->telnum);
				printf("[hash(a)]%d\n", n);
			}
			p = p->next;
		}
	}
	return (0);
}

int	hash(char *s)
{
	int	n;

	n = strlen(s);
	return (s[0]-'A'+(s[n/2-1]-'A')*26+(s[n-2]-'A')*26*26) % ModSize;
}

struct tfield	*talloc(void)
{
	return (struct tfield *)malloc(sizeof(struct tfield));
}
