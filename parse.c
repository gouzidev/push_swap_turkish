#include "push_swap.h"

t_stack	*parse(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*node;
	char	**split_arr;
	int		i;
	int		j;

	a = NULL;
	i = 1;
	while (i < ac)
	{
		split_arr = ft_split(av[i], ' ');
		if (split_arr == NULL)
			print_exit("Error NULL MALLOC\n");
		j = 0;
		while (split_arr[j])
		{
			if (is_empty(split_arr[j]))
				print_exit("Error (empty)\n");
			if (!valid(split_arr[j]))
				print_exit("Error (not valid)\n");
			else
			{
				node = new (ft_atoi(split_arr[j]));
				if (!node || exists(a, node))
					print_exit("Error Bad Node");
				push_end(&a, node);
			}
			j++;
		}
		i++;
		free_all(split_arr);
	}
	return (a);
}
