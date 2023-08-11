/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:43:05 by amaligno          #+#    #+#             */
/*   Updated: 2023/05/24 19:17:50 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putptr(unsigned long int n, int *len)
{
	if (n >= 16)
	{
		ft_putptr(n / 16, len);
		ft_putptr(n % 16, len);
	}
	else
	{
		if (n >= 10)
			ft_putchar((n - 10) + 'a', len);
		else
			ft_putchar(n + '0', len);
	}
}

void	ft_puthexcap(unsigned int n, int *len)
{
	if (n >= 16)
	{
		ft_puthexcap(n / 16, len);
		ft_puthexcap(n % 16, len);
	}
	else
	{
		if (n >= 10)
			ft_putchar((n - 10) + 'A', len);
		else
			ft_putchar(n + '0', len);
	}
}

void	conver_check(const char *str, va_list args, int *len)
{
	if (*str == 'c')
		ft_putchar(va_arg(args, int), len);
	if (*str == 's')
		writer(va_arg(args, const char *), len);
	else if (*str == 'i' || *str == 'd')
		ft_putnbr(va_arg(args, int), len);
	else if (*str == 'u')
		ft_putunsigned(va_arg(args, unsigned int), len);
	else if (*str == 'p')
	{
		writer("0x", len);
		ft_putptr(va_arg(args, unsigned long int), len);
	}
	else if (*str == 'x')
		ft_puthexa(va_arg(args, int), len);
	else if (*str == 'X')
		ft_puthexcap(va_arg(args, int), len);
	else if (*str == '%')
		ft_putchar('%', len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			conver_check(str, args, &len);
		}
		else
		{
			write(1, &*str, 1);
			len++;
		}
		str++;
	}
	va_end(args);
	return (len);
}

// int	main(void)
// {
// 	int	len;
// 	int	num = 89;
// 	int	*ptr = &num;
// 	int rlen;
// 	// if (c == 1)
// 	// {
// 	// 	printf("not enough args");
// 	// }
// 	// else
// 	// {
// 	// 	len = ft_printf("%s%s%s");
// 	// 	printf("%i", len);
// 	// }
// 	len = ft_printf("mine %c\n", 'c');
// 	rlen = printf("real %c\n", 'c');
// 	printf("rlen = %i, mlen = %i", rlen, len);
// }