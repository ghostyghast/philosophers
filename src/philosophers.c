/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:49:12 by amaligno          #+#    #+#             */
/*   Updated: 2023/08/15 18:36:10 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_vars(char **str, int c, )
{
	
}

int	check_args(char **str)
{
	str++;
	while (str++ && *str)
	{
		while (**str)
		{
			if (**str <= '0' || **str >= '9')
				return (0);
			(*str)++;
		}
	}
	return (1);
}

int	main(int c, char **str)
{
	(void)str;
	if (c == 5 || c == 6)
		return (ft_printf("invalid arg amount\n"), -1);
	if (!check_args(str))
		return (ft_printf("invalid arguments\n"), -1);
	if (!init_var())
		return (ft_printf("error during variable initiation\n"), -1);
	return (0);
}
