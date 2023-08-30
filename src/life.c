/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <antoinemalignon@yahoo.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:36:28 by amaligno          #+#    #+#             */
/*   Updated: 2023/08/31 01:25:33 by amaligno         ###   ########.fr       */
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
	philo->die_time = ft_gettime() + philo->info->time_die;
	if (!check_death(philo))
		return (0);
	philo->hand = 2;
	if (philo->philo_number % 2 == 0)
		take_fork(philo, philo->l_fork);
	else
		take_fork(philo, philo->r_fork);
	if (!check_death(philo))
		return (0);
	print_state(philo, EATING);
	ft_usleep(philo->info->time_eat);
	put_fork(philo->l_fork);
	put_fork(philo->r_fork);
	philo->hand = 0;
	return (1);
}

int	think(t_philo *philo)
{
	if (philo->die_time == 0)
		philo->die_time = ft_gettime() + philo->info->time_die;
	if (!check_death(philo))
		return (0);
	print_state(philo, THINKING);
	philo->hand = 1;
	if (philo->philo_number % 2 == 0)
		return (take_fork(philo, philo->r_fork), 1);
	else
		return (take_fork(philo, philo->l_fork), 1);
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
