/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:05:20 by amaligno          #+#    #+#             */
/*   Updated: 2023/09/05 18:51:49 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_philos(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->philo_amount)
	{
		info->philos[i].info = info;
		info->philos[i].philo_number = i + 1;
		info->philos[i].die_time = 0;
		info->philos[i].hand = 0;
	}
}

int	init_vars(char **str, int c, t_info *info)
{
	info->philo_amount = (int)ft_atoi(str[1]);
	info->time_die = (u_int64_t)ft_atoi(str[2]);
	info->time_eat = (u_int64_t)ft_atoi(str[3]);
	info->time_sleep = (u_int64_t)ft_atoi(str[4]);
	info->dead = 0;
	if (c == 6)
		info->meal_amnt = ft_atoi(str[5]);
	else
		info->meal_amnt = 0;
	info->philos = malloc(sizeof(t_philo) * info->philo_amount);
	if (!info->philos)
		return (0);
	info->print = sem_open("print", O_CREAT, 0600, 1);
	info->forks = sem_open("fork", O_CREAT, 0600, info->philo_amount);
	info->death = sem_open("death", O_CREAT, 0600, 1);
	init_philos(info);
	return (info->philo_amount);
}
