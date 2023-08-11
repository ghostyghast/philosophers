/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:13:56 by amaligno          #+#    #+#             */
/*   Updated: 2023/06/06 21:30:10 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_int **lst, t_int *new)
{
	t_int	*temp;

	if (!new)
		return ;
	new->prev = NULL;
	if (!lst || !*lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	temp = *lst;
	temp->prev = new;
	*lst = new;
}
