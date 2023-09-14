/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pringles <pringles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:31:28 by amaligno          #+#    #+#             */
/*   Updated: 2023/09/14 19:09:16 by pringles         ###   ########.fr       */
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
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
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