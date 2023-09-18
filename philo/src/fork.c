/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pringles <pringles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:31:28 by amaligno          #+#    #+#             */
/*   Updated: 2023/09/18 17:03:27 by pringles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo, pthread_mutex_t *fork)
{
	if (!check_death(philo))
		return ;
	// printf("philo n%i, inside take fork\n", philo->philo_number);
	pthread_mutex_lock(fork);
	philo->hand++;
	print_state(philo, TAKE_FORK);
}

void	put_forks(t_philo *philo)
{
	if (philo->hand >= 1)
		pthread_mutex_unlock(philo->r_fork);
	if (philo->hand == 2)
		pthread_mutex_unlock(philo->l_fork);
	philo->hand = 0;
}

void	smart_sleep(t_philo *philo, u_int64_t time)
{
	if ((ft_gettime() + time) >= philo->die_time)
		ft_usleep(philo->die_time - ft_gettime());
	else
		ft_usleep(time);
}