/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:09:38 by amaligno          #+#    #+#             */
/*   Updated: 2023/09/18 17:22:33 by amaligno         ###   ########.fr       */
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

void	smart_sleep(t_philo *philo, u_int64_t time)
{
	if ((ft_gettime() + time) >= philo->die_time)
	{
		ft_usleep(philo->die_time - ft_gettime());
		check_death(philo);
	}
	else
		ft_usleep(time);
}

void	print_state(t_philo *philo, char *status)
{
	if (status == NULL)
	{
		sem_wait(philo->info->print);
		printf("%llu %i %s\n", ft_gettime() - philo->info->base_time,
			philo->philo_number, DEAD);
	}
	else
	{
		sem_wait(philo->info->print);
		if (check_death(philo))
			printf("%llu %i %s\n", ft_gettime() - philo->info->base_time,
				philo->philo_number, status);
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
