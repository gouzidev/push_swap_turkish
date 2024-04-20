/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouzi <sgouzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:07:04 by sgouzi            #+#    #+#             */
/*   Updated: 2024/04/20 19:16:09 by sgouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	res;

	res = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		if (res > INT_MAX || (res * sign) < INT_MIN)
			print_exit("Error\n");
		i++;
	}
	return (res * sign);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = ((unsigned char *)s1);
	str2 = ((unsigned char *)s2);
	i = 0;
	while (str2[i] != '\0' && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

int	is_valid_op(char *op)
{
	return ((ft_strcmp(op, "sa") == 0) || (ft_strcmp(op, "sb") == 0 || ft_strcmp(op, "ss") == 0)
		|| (ft_strcmp(op, "pb") == 0) || (ft_strcmp(op, "pa") == 0)
		|| (ft_strcmp(op, "ra") == 0) || (ft_strcmp(op, "rb") == 0)
		|| (ft_strcmp(op, "rr") == 0) || (ft_strcmp(op, "rra") == 0)
		|| (ft_strcmp(op, "rrb") == 0) || (ft_strcmp(op, "rrr") == 0));
}

bool	handle_op(char *op, t_stack **a, t_stack **b)
{
	if (ft_strcmp(op, "sa\n") == 0)
		swap_stack(a, "sa", false);
	else if (ft_strcmp(op, "sb\n") == 0)
		swap_stack(b, "sb", false);
	else if (ft_strcmp(op, "ss\n") == 0)
		(swap_stack(a, "sa", false), swap_stack(b, "sb", false));
	else if (ft_strcmp(op, "pa\n") == 0)
		push_a_to_b(a, b, false);
	else if (ft_strcmp(op, "pb\n") == 0)
		push_b_to_a(a, b, false);
	else if (ft_strcmp(op, "ra\n") == 0)
		rotate_stack(a, "ra", false);
	else if (ft_strcmp(op, "rb\n") == 0)
		rotate_stack(b, "rb", false);
	else if (ft_strcmp(op, "rr\n") == 0)
		rotate_ab(a, b, false);
	else if (ft_strcmp(op, "rra\n") == 0)
		reverse_rotate_stack(a, "rra", false);
	else if (ft_strcmp(op, "rrb\n") == 0)
		reverse_rotate_stack(a, "rrb", false);
	else if (ft_strcmp(op, "rrr\n") == 0)
		reverse_rotate_ab(a, b, false);
	else
	{
		write(2, "Error\n", 6);
		free(op);
		clear(a);
		clear(b);
		return false;
	}
	return true;
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	bool res;
	char	*line;

	if (ac < 2)
		return (0);
	a = NULL;
	b = NULL;
	a = parse(ac, av);
	line = get_next_line(0);
	while (line)
	{
		res = handle_op(line, &a, &b);
		if (res == false)
			return (1);
		line = get_next_line(0);
	}
	if (is_stack_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	clear(&a);
	return 0;
}