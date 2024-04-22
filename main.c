/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouzi <sgouzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:07:16 by sgouzi            #+#    #+#             */
/*   Updated: 2024/04/22 10:19:36 by sgouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(t_stack *head)
{
	while (head && head->next)
	{
		if (head->n > head->next->n)
			return (0);
		head = head->next;
	}
	return (1);
}

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

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = parse(ac, av);
	if (ac == 2 && ft_strcmp(av[1], "") == 0)
		return (print_exit("Error\n"), 1);
	if (!is_stack_sorted(a))
		sort(&a, &b);
	clear(&a);
	return (0);
}
