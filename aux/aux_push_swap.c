/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_push_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:55:45 by mvicente          #+#    #+#             */
/*   Updated: 2023/02/03 13:55:46 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_lstiter(t_list *lst, t_list *lst_b)
{
	while (lst)
	{
		printf("a index %d, position %d, number %d\n", lst->index, lst->position, lst->number);
		if (!lst->next)
			break ;
		lst = lst->next;
	}
	printf("\n");
	while (lst_b)
	{
		printf("a index %d, position %d, number %d\n", lst->index, lst->position, lst->number);
		if (!lst_b->next)
			break ;
		lst_b = lst_b->next;
	}
}