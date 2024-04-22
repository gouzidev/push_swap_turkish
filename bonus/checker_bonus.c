/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouzi <sgouzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:07:04 by sgouzi            #+#    #+#             */
/*   Updated: 2024/04/21 20:42:21 by sgouzi           ###   ########.fr       */
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
		if ((res * sign) > INT_MAX || (res * sign) < INT_MIN)
			print_exit("Error\n");
		i++;
	}
	return (res * sign);
}

bool handle_rotate(char *op, t_stack **a, t_stack **b)
{
	if (ft_strcmp(op, "ra\n") == 0)
		rotate_stack(a, "ra", false);
	else if (ft_strcmp(op, "rb\n") == 0)
		rotate_stack(b, "rb", false);
	else if (ft_strcmp(op, "rr\n") == 0)
		rotate_ab(a, b, false);
	else if (ft_strcmp(op, "rra\n") == 0)
		reverse_rotate_stack(a, "rra", false);
	else if (ft_strcmp(op, "rrb\n") == 0)
		reverse_rotate_stack(b, "rrb", false);
	else if (ft_strcmp(op, "rrr\n") == 0)
		reverse_rotate_ab(a, b, false);
	else
	{
		write(2, "Error\n", 6);
		return false;
	}
	return true;
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
		push_b_to_a(a, b, false);
	else if (ft_strcmp(op, "pb\n") == 0)
		push_a_to_b(a, b, false);
	else
		return handle_rotate(op, a, b);
	return true;
}
#include <stdio.h>
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
		free(line);
		if (res == false)
			return (clear(&a), clear(&b), 255);
		line = get_next_line(0);
	}
	
	if (is_stack_sorted(a) && get_size(b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	clear(&a);
	return 0;
}