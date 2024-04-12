#include "push_swap.h"

void	swap_stack(t_stack **head, char *msg)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if ((*head) && (*head)->next)
	{
		tmp1 = new ((*head)->n);
		pop(head);
		tmp2 = new ((*head)->n);
		pop(head);
		push(head, tmp1);
		push(head, tmp2);
	}
	printf("%s", msg);

}
void	push_b_to_a(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!a || !b)
	{
		printf("Error\n");
		exit(1);
	}
	if (*b)
	{
		temp = duplicate(*b);
		pop(b);
		push(a, temp);
	}
	if (*a)
		give_index(*a, false);
	if (*b)
		give_index(*b, false);
    printf("pa\n");

}
void	push_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!a || !b)
	{
		printf("Error\n");
		exit(1);
	}
	if (*a)
	{
		temp = duplicate(*a);
		pop(a);
		push(b, temp);
	}
	if (*a)
		give_index(*a, false);
	if (*b)
		give_index(*b, false);
	printf("pb\n");
}
void	rotate_stack(t_stack **stack, char *msg)
{
	t_stack	*last_a;
	t_stack	*new_head;

	if (!stack || !*stack || !(*stack)->next)
		return ;
    
	new_head = (*stack)->next;
	last_a = get_last(*stack);
	if (last_a)
		last_a->next = *stack;
	(*stack)->next = NULL;
	(*stack) = new_head;
	give_index(*stack, false);
	printf("%s", msg);
}
void	rotate_ab(t_stack **a, t_stack **b)
{
	rotate_stack(a, "");
	rotate_stack(b, "");
	printf("rr\n");
}
void	reverse_rotate_stack(t_stack **stack, char *msg)
{
	t_stack	*before_last_node;
	t_stack	*last_node;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	before_last_node = before_last(*stack);
	last_node = before_last_node->next;
	last_node->next = *stack;
	before_last_node->next = NULL;
	*stack = last_node;
	give_index(*stack, false);
	printf("%s", msg);
}
void	reverse_rotate_ab(t_stack **a, t_stack **b)
{
	// t_stack	*before_last_node_a;
	// t_stack	*before_last_node_b;
	// t_stack	*last_node_a;
	// t_stack	*last_node_b;

	// if (!a || !(*a) || !(*a)->next)
	// 	return ;
	// if (!b || !(*b) || !(*b)->next)
	// 	return ;
	// before_last_node_a = before_last(*a);
	// before_last_node_b = before_last(*b);
	// last_node_a = before_last_node_a->next;
	// last_node_b = before_last_node_b->next;
	// last_node_a->next = *a;
	// last_node_b->next = *b;
	// before_last_node_a->next = NULL;
	// before_last_node_b->next = NULL;
	// *a = last_node_a;
	// *b = last_node_b;
	reverse_rotate_stack(a, "");
	reverse_rotate_stack(b, "");
	printf("rrr\n");
}
