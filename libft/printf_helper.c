/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:45:40 by amaligno          #+#    #+#             */
/*   Updated: 2023/05/24 19:18:08 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	writer(const char *str, int *i)
{
	if (!str)
	{
		write(1, "(null)", 6);
		*i += 6;
		return ;
	}
	while (*str)
	{
		write(1, str, 1);
		*i += 1;
		str++;
	}
}

void	ft_putchar(int c, int *i)
{	
	*i += 1;
	write(1, &c, 1);
}

void	ft_putnbr(int nb, int *len)
{
	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10, len);
		ft_putchar('8', len);
	}
	else if (nb < 0)
	{
		ft_putchar('-', len);
		ft_putnbr(-nb, len);
	}
	else
	{
		if (nb > 9)
		{
			ft_putnbr(nb / 10, len);
		}
		ft_putchar(48 + nb % 10, len);
	}
}

void	ft_putunsigned(unsigned int nb, int *len)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10, len);
	}
	ft_putchar(48 + nb % 10, len);
}

void	ft_puthexa(unsigned int n, int *len)
{
	if (n >= 16)
	{
		ft_puthexa(n / 16, len);
		ft_puthexa(n % 16, len);
	}
	else
	{
		if (n >= 10)
			ft_putchar((n - 10) + 'a', len);
		else
			ft_putchar(n + '0', len);
	}
}
