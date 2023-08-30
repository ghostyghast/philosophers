/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:09:38 by amaligno          #+#    #+#             */
/*   Updated: 2023/08/30 21:36:00 by amaligno         ###   ########.fr       */
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
		usleep(time / 10);
}

void	print_state(t_philo *philo, char *status)
{
	pthread_mutex_lock(&philo->info->print);
	printf("%llu %i %s\n", ft_gettime(), philo->philo_number, status);
	pthread_mutex_unlock(&philo->info->print);
}

int	check_death(t_philo *philo)
{	
	pthread_mutex_lock(philo->lock);
	if (philo->info->dead == 1)
		return (printf("another philo died\n"), 0);
	if (ft_gettime() >= philo->die_time)
	{
		philo->info->dead = 1;
		print_state(philo, DEAD);
		pthread_mutex_unlock(philo->lock);
		return (printf("i died cuz of time\n"), 0);
	}
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
