/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:51:14 by amaligno          #+#    #+#             */
/*   Updated: 2023/06/13 18:16:14 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_int	*ft_lstnew(int num)
{
	t_int	*new;

	new = (t_int *)malloc(sizeof(t_int));
	if (!new)
		return (NULL);
	new->num = num;
	new->index = -1;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}
