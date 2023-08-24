/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:39:35 by amaligno          #+#    #+#             */
/*   Updated: 2023/06/06 16:47:53 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_char(char c, char *s)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

static int	is_space(char c)
{
	return (is_char(c, "\t\n\v\f\r "));
}

static int	is_operator(char c)
{
	return (is_char(c, "+-"));
}

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

long	ft_atoi(char *str)
{
	long int		result;
	long int		sign;

	result = 0;
	sign = 1;
	while (is_space(*str))
		str++;
	if (is_operator(*str))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (is_digit(*str))
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result * sign);
}
