/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:05:20 by amaligno          #+#    #+#             */
/*   Updated: 2023/08/30 18:15:40 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philos(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->philo_amount)
	{
		info->philos[i].info = info;
		info->philos[i].philo_number = i + 1;
		info->philos[i].die_time = 0;
		info->philos[i].lock = &info->lock;
		info->philos[i].l_fork = &info->forks[i];
		info->philos[i].r_fork = &info->forks[(i + 1) % (info->philo_amount)];
	}
}

int	malloc_data(t_info *info)
{
	int	i;

	info->philos = malloc(sizeof(t_philo) * info->philo_amount);
	if (!info->philos)
		return (0);
	info->forks = malloc(sizeof(pthread_mutex_t) * info->philo_amount);
	if (!info->forks)
		return (0);
	i = -1;
	while (++i < info->philo_amount)
		pthread_mutex_init(&info->forks[i], NULL);
	return (1);
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
	pthread_mutex_init(&info->lock, NULL);
	pthread_mutex_init(&info->print, NULL);
	if (!malloc_data(info))
		return (0);
	init_philos(info);
	return (1);
}
