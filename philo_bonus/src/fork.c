/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:32:19 by amaligno          #+#    #+#             */
/*   Updated: 2023/09/13 21:32:43 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	take_fork(t_philo *philo)
{
	if (!check_death(philo))
		return ;
	print_state(philo, TAKE_FORK);
	sem_wait(philo->info->forks);
}

void	put_fork(t_philo *philo)
{
	sem_post(philo->info->forks);
}

void	put_forks(t_philo *philo)
{
	sem_post(philo->info->forks);
	sem_post(philo->info->forks);
}
