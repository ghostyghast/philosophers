/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:31:28 by amaligno          #+#    #+#             */
/*   Updated: 2023/09/06 15:52:24 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo, pthread_mutex_t *fork)
{
	if (!check_death(philo))
		return ;
	pthread_mutex_lock(fork);
	print_state(philo, TAKE_FORK);
}

void	put_fork(pthread_mutex_t *fork)
{
	pthread_mutex_unlock(fork);
}

void	put_forks(t_philo *philo)
{
	if (philo->hand == 1)
	{
		if (philo->philo_number % 2 == 0)
			pthread_mutex_unlock(philo->l_fork);
		else
			pthread_mutex_unlock(philo->r_fork);
	}
	else if (philo->hand == 2)
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
	}
}
