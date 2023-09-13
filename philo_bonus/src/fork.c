/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <antoinemalignon@yahoo.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:31:28 by amaligno          #+#    #+#             */
/*   Updated: 2023/09/14 02:41:31 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	take_fork(t_philo *philo)
{
	if (!check_death(philo))
		return ;
	sem_wait(philo->info->forks);
	print_state(philo, TAKE_FORK);
	philo->hand++;
}

void	put_forks(t_philo *philo)
{
	if (philo->hand == 1)
		sem_post(philo->info->forks);
	else if (philo->hand == 2)
	{
		sem_post(philo->info->forks);
		sem_post(philo->info->forks);
	}
	philo->hand = 0;
}
