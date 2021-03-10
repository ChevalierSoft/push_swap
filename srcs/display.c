#include "../inc/header.h"

void	display_lists(t_game *g)
{
	system("cls");
	printf(" a  |  b\n");
	printf("---------\n");
	while (g->a || g->b)
	{
		if (g->a)
		{
			printf("%d", *((int *)g->a->content));
			g->a = g->a->next;
		}
		if (g->b)
		{
			printf("  |  %d", *((int *)g->b->content));
			g->b = g->b->next;
		}
		printf("\n");
	}
}