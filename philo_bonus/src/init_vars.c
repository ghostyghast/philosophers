/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pringles <pringles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:05:20 by amaligno          #+#    #+#             */
/*   Updated: 2023/09/14 18:03:13 by pringles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_sem(t_info *info)
{
	sem_unlink("print");
	sem_unlink("death");
	sem_unlink("forks");
	info->print = sem_open("print", O_CREAT, 0600, 1);
	info->death = sem_open("death", O_CREAT, 0600, 1);
	info->forks = sem_open("forks", O_CREAT, 0600, info->philo_amount);
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
	info->philos.info = info;
	info->philos.philo_number = 0;
	info->philos.die_time = 0;
	info->philos.hand = 0;
	init_sem(info);
	return (info->philo_amount);
}
