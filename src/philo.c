/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:49:12 by amaligno          #+#    #+#             */
/*   Updated: 2023/08/29 17:57:19 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(char **str)
{
	str++;
	while (str++ && *str)
	{
		while (**str)
		{
			if (**str <= '0' || **str >= '9')
				return (0);
			(*str)++;
		}
	}
	return (1);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		i;

	i = -1;
	philo = (t_philo *)arg;
	if (philo->info->meal_amnt > 0)
	{
		while (++i < philo->info->meal_amnt)
			if (!life(philo))
				return (NULL);
	}
	else
		while (1)
			if (!life(philo))
				return (NULL);
	return (NULL);
}

int	death_checker(t_info *info)
{
	while (info->dead == 0)
	{
		pthread_mutex_lock(info->lock);
	}
}

int	main(int c, char **str)
{
	t_info	info;
	int		i;

	if (c != 5 && c != 6)
		return (ft_printf("invalid arg amount\n"), -1);
	if (!check_args(str))
		return (ft_printf("invalid arguments\n"), -1);
	if (!init_vars(str, c, &info))
		return (ft_printf("error during variable initiation\n"), -1);
	i = -1;
	while (++i < info.philo_amount)
		pthread_create(&info.philos[i].th_id, NULL, routine, &info.philos[i]);
	i = -1;
	death_checker(&info);
	while (++i < info.philo_amount)
		pthread_join(&info.philos[i].th_id, NULL);
	return (0);
}
