/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pringles <pringles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:09:38 by amaligno          #+#    #+#             */
/*   Updated: 2023/09/14 17:52:11 by pringles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

u_int64_t	ft_gettime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(u_int64_t time)
{
	u_int64_t		start;

	start = ft_gettime();
	while ((ft_gettime() - start) < time)
		usleep(time / 10);
}

void	print_state(t_philo *philo, char *status)
{
	if (status == NULL)
	{
		sem_wait(philo->info->print);
		printf("%lu %i %s\n", ft_gettime() - philo->info->base_time, philo->philo_number, DEAD);
	}
	else
	{
		sem_wait(philo->info->print);
		if (check_death(philo))
			printf("%lu %i %s\n", ft_gettime() - philo->info->base_time, philo->philo_number, status);
		sem_post(philo->info->print);
	}
}

int	check_death(t_philo *philo)
{	
	if (ft_gettime() >= philo->die_time)
	{
		put_forks(philo);
		philo->info->dead = 1;
		print_state(philo, NULL);
		exit(0);
	}
	return (1);
}

void	free_stuff(t_info *info)
{
	sem_close(info->death);
	sem_close(info->forks);
	sem_close(info->print);
}
