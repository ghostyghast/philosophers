/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <antoinemalignon@yahoo.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:49:12 by amaligno          #+#    #+#             */
/*   Updated: 2023/08/31 01:25:18 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[++i] && str[i][0])
	{
		j = -1;
		while (str[i][++j])
		{
			if (str[i][j] < '0' || str[i][j] > '9')
				return (0);
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

int	main(int c, char **str)
{
	t_info	info;
	int		i;

	if (c != 5 && c != 6)
		return (printf("invalid arg amount\n"), -1);
	if (!check_args(str))
		return (printf("invalid arguments\n"), -1);
	if (!init_vars(str, c, &info))
		return (printf("error during variable initiation\n"), -1);
	i = -1;
	while (++i < info.philo_amount)
		pthread_create(&info.philos[i].th_id, NULL, routine, &info.philos[i]);
	i = -1;
	while (++i < info.philo_amount)
		pthread_join(info.philos[i].th_id, NULL);
	free_stuff(&info);
	return (0);
}
