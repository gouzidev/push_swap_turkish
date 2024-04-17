/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouzi <sgouzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:07:16 by sgouzi            #+#    #+#             */
/*   Updated: 2024/04/17 17:48:02 by sgouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	i = 0;
	b = NULL;
	a = parse(ac, av);
	if (is_stack_sorted(a))
		return (0);
	if (get_size(a) == 2)
		sort_two(&a);
	else if (get_size(a) == 3)
		sort_three(&a);
	else
		sort_more(&a, &b);
	clear(&a);
}
