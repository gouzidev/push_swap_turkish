#include "push_swap.h"

#include "push_swap.h"

int	is_empty(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	valid(char *num)
{
	int i;

	i = 0;
	if (num[i] == '-' || num[i] == '+')
		i++;
	if (num[i] < '0' || num[i] > '9')
		return (0);
	while (num[i])
	{
		if (num[i] < '0' || num[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

t_stack	*parse(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*node;
	char	**split_arr;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	while (++i < ac)
	{
		split_arr = ft_split(av[i], ' ');
		if (split_arr == NULL)
			print_exit("Error\n");
		j = -1;
		while (split_arr[++j])
		{
			if (is_empty(split_arr[j]) || !valid(split_arr[j]))
                (clear(&a), free_all(split_arr), print_exit("Error\n"));
			else
			{
				node = new (ft_atoi(split_arr[j]));
				if (!node || exists(a, node))
					(clear(&a), free_all(split_arr), free(node), print_exit("Error\n"));
				push_end(&a, node);
			}
		}
		free_all(split_arr);
	}
	return (a);
}
