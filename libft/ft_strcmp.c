/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:56:33 by amaligno          #+#    #+#             */
/*   Updated: 2023/06/19 17:55:55 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	while ((*s1 == *s2) && *s1 && *s2)
	{
		s1++;
		s2++;
	}	
	return (*s1 - *s2);
}

// int	main(int argc, char  **str)
// {	
// 	if (!ft_strcmp("hello\n", "hello"))
// 		printf("same\n");
// 	else
// 		printf("diff\n");
// }