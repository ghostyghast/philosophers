/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:36:28 by amaligno          #+#    #+#             */
/*   Updated: 2023/09/04 16:49:53 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	sleepy(t_philo *philo)
{
	if (!check_death(philo))
		return (0);
	print_state(philo, SLEEPING);
	ft_usleep(philo->info->time_sleep);
	return (1);
}

int	eat(t_philo *philo)
{
	if (!check_death(philo))
		return (0);
	if (philo->philo_number % 2 == 0)
		take_fork(philo, philo->l_fork);
	else
		take_fork(philo, philo->r_fork);
	philo->hand = 2;
	if (!check_death(philo))
		return (0);
	print_state(philo, EATING);
	ft_usleep(philo->info->time_eat);
	philo->die_time = ft_gettime() + philo->info->time_die;
	put_forks(philo);
	philo->hand = 0;
	return (1);
}

int	think(t_philo *philo)
{
	if (!check_death(philo))
		return (0);
	print_state(philo, THINKING);
	if (philo->philo_number % 2 == 0)
		take_fork(philo, philo->r_fork);
	else
		take_fork(philo, philo->l_fork);
	philo->hand = 1;
	return (1);
}

int	life(t_philo *philo)
{
	if (!think(philo))
		return (0);
	if (!eat(philo))
		return (0);
	if (!sleepy(philo))
		return (0);
	return (1);
}
