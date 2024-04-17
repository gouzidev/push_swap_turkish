/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouzi <sgouzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:07:04 by sgouzi            #+#    #+#             */
/*   Updated: 2024/04/17 18:34:51 by sgouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
	return ((ft_strcmp(op, "sa") == 0) || (ft_strcmp(op, "sb") == 0)
		|| (ft_strcmp(op, "ra") == 0) || (ft_strcmp(op, "rb") == 0)
		|| (ft_strcmp(op, "rr") == 0) || (ft_strcmp(op, "rra") == 0)
		|| (ft_strcmp(op, "rrb") == 0) || (ft_strcmp(op, "rrr") == 0));
}

void	handle_op(char *op, t_stack **a, t_stack **b)
{
	if (ft_strcmp(op, "sa\n") == 0)
		swap_stack(a, "sa", false);
	else if (ft_strcmp(op, "sb\n") == 0)
		swap_stack(b, "sb", false);
	else if (ft_strcmp(op, "ra\n") == 0)
		rotate_stack(a, "ra", false);
	else if (ft_strcmp(op, "sb\n") == 0)
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
		print_exit("Error\n");
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	if (ac < 2)
		return (0);
	a = NULL;
	b = NULL;
	a = parse(ac, av);
	line = get_next_line(0);
	while (line)
	{
		handle_op(line, &a, &b);
		free(line);
		line = get_next_line(0);
	}
	if (is_stack_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
