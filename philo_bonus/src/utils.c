/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <antoinemalignon@yahoo.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:09:38 by amaligno          #+#    #+#             */
/*   Updated: 2023/09/14 02:57:25 by amaligno         ###   ########.fr       */
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
		printf("%lu %i %s\n", ft_gettime() - philo->info->base_time, philo->philo_number, DEAD);
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
	// sem_wait(philo->info->death);
	printf("from philo n%idead bool : %i\n", philo->philo_number, philo->info->dead);
	if (philo->info->dead == 1)
	{
		put_forks(philo);
		// sem_post(philo->info->death);
		return (0);
	}
	if (ft_gettime() >= philo->die_time)
	{
		put_forks(philo);
		philo->info->dead = 1;
		print_state(philo, NULL);
		// sem_post(philo->info->death);
		return (0);
	}
	// sem_post(philo->info->death);
	return (1);
}

void	free_stuff(t_info *info)
{
	sem_close(info->death);
	sem_close(info->forks);
	sem_close(info->print);
	free(info->philos);
}
