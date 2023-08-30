/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:09:38 by amaligno          #+#    #+#             */
/*   Updated: 2023/08/30 18:19:38 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

u_int64_t	ft_gettime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_usec);
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
	// if (status == EATING)
	// 	printf(" eating\n");
	// else if (status == THINKING)
	// 	printf(" thinking\n");
	// else if (status == SLEEPING)
	// 	printf(" sleeping\n");
	// else if (status == TAKE_FORK)
	// 	printf(" has taken a fork\n");
	// else if (status == DEAD)
	// 	printf(" has died\n");
	pthread_mutex_unlock(&philo->info->print);
}

int	check_death(t_philo *philo)
{
	if (ft_gettime() >= philo->info->time_die)
	{
		pthread_mutex_lock(philo->lock);
		philo->info->dead = 1;
		print_state(philo, DEAD);
		pthread_mutex_unlock(philo->lock);
		return (0);
	}
	if (philo->info->dead == 1)
		return (0);
	return (1);
}

void	free_stuff(t_info *info)
{
	int i;

	i = info->philo_amount;
	while (i--)
		pthread_mutex_destroy(&info->forks[i]);
	free(info->forks);
	free(info->philos);
	pthread_mutex_destroy(&info->lock);
	pthread_mutex_destroy(&info->print);
}