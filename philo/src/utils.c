/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pringles <pringles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:09:38 by amaligno          #+#    #+#             */
/*   Updated: 2023/09/18 16:54:03 by pringles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		usleep(50);
}

void	print_state(t_philo *philo, char *status)
{
	if (status == NULL)
		printf("%lu %i %s\n", ft_gettime() - philo->info->base_time,
			philo->philo_number, DEAD);
	else
	{
		pthread_mutex_lock(&philo->info->print);
		if (check_death(philo))
			printf("%lu %i %s\n", ft_gettime() - philo->info->base_time,
				philo->philo_number, status);
		pthread_mutex_unlock(&philo->info->print);
	}
}

int	check_death(t_philo *philo)
{	
	pthread_mutex_lock(philo->lock);
	// if (philo->philo_number == 1)
		// printf("philo n%i, inside check death\n", philo->philo_number);
	if (philo->info->dead || philo->info->all_full)
	{
		put_forks(philo);
		pthread_mutex_unlock(philo->lock);
		return (0);
	}
	if (ft_gettime() >= philo->die_time)
	{
		put_forks(philo);
		philo->info->dead = 1;
		print_state(philo, NULL);
		pthread_mutex_unlock(philo->lock);
		return (0);
	}
	if (philo->info->meals_eaten == philo->info->philo_amount)
		philo->info->all_full = 1;
	pthread_mutex_unlock(philo->lock);
	return (1);
}

void	free_stuff(t_info *info)
{
	int	i;

	i = info->philo_amount;
	while (i--)
		pthread_mutex_destroy(&info->forks[i]);
	free(info->forks);
	free(info->philos);
	pthread_mutex_destroy(&info->lock);
	pthread_mutex_destroy(&info->print);
}
