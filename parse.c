#include "push_swap.h"

int	is_num(char c)
{
	return (c <= '9' && c >= '0');
}
int	is_sign(char c)
{
	return (c == '+' || c == '-');
}
int	is_space(char c)
{
	return (c == ' ');
}
void	check_format(char *s)
{
	int	i;
	int	found_num;

	i = 0;
	found_num = 0;
	if (!is_num(s[0]) && !(is_sign(s[0]) && is_num(s[1])))
		print_exit("Error in formatting");
	i++;
	while (s[i])
	{
		if (is_num(s[i]))
			i++;
		else if (is_space(s[i]) && is_num(s[i + 1]))
			i += 2;
		else if (is_space(s[i]) && is_sign(s[i + 1]) && is_num(s[i + 2]))
			i += 3;
		else
			print_exit("Error");
	}
}

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
			if (is_empty(split_arr[j]) || !valid(split_arr[j]))
				print_exit("Error\n");
			else
			{
				node = new (ft_atoi(split_arr[j]));
				if (!node || exists(a, node))
					(clear(&a), print_exit("Error\n"));
				push_end(&a, node);
			}
			j++;
		}
		i++;
		free_all(split_arr);
	}
	return (a);
}
