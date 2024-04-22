/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouzi <sgouzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:07:23 by sgouzi            #+#    #+#             */
/*   Updated: 2024/04/22 12:47:58 by sgouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	valid(char *num)
{
	int	i;

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

void	verify_push(char **split_arr, t_stack **a, int j)
{
	t_stack	*node;

	if ((ft_strcmp(split_arr[j], "") == 0) || !valid(split_arr[j]))
		(clear(a), free_all(split_arr), print_exit("Error\n"));
	else
	{
		node = new (ft_atoi(split_arr[j]));
		if (!node || exists(*a, node))
			(clear(a), free_all(split_arr), free(node), print_exit("Error\n"));
		push_end(a, node);
	}
}

t_stack	*parse(int ac, char *av[])
{
	t_stack	*a;
	char	**split_arr;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	while (++i < ac)
	{
		if (ft_strcmp(av[i], "") == 0)
			(clear(&a), print_exit("Error\n"));
		split_arr = ft_split(av[i], ' ');
		if (split_arr == NULL)
			(clear(&a), print_exit("Error\n"));
		j = -1;
		while (split_arr[++j])
			verify_push(split_arr, &a, j);
		free_all(split_arr);
	}
	return (a);
}
