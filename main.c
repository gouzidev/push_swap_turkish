#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_stack *a;
	t_stack *b;
	int		size;
	int		i;

	i = 0;
	b = NULL;
	a = parse(ac, av);
	if (is_stack_sorted(a))
		return 0;
	if (get_size(a) == 2)
		sort_two(&a);
	else if (get_size(a) == 3)
		sort_three(&a);
	else
		sort_more(&a, &b);
	// printf("is sorted %d\n", is_stack_sorted(a));
	clear(&a);
}
