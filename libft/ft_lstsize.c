/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:44:57 by amaligno          #+#    #+#             */
/*   Updated: 2023/05/22 14:37:26 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_int *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (count);
	while (lst)
	{	
		lst = lst->next;
		count++;
	}
	return (count);
}
