/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:07:40 by amaligno          #+#    #+#             */
/*   Updated: 2023/09/05 18:34:52 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void	routine(t_philo *philo)
{
	int	i;

	i = -1;
	philo->die_time = ft_gettime() + philo->info->time_die;
	if (philo->info->meal_amnt > 0)
	{
		while (++i < philo->info->meal_amnt)
			if (!life(philo))
				exit(0);
	}
	else
		while (1)
			if (!life(philo))
				exit(0);
}

int	main(int c, char **str)
{
	t_info	info;
	int		pid;
	int		i;

	if (c != 5 && c != 6)
		return (printf("invalid arg amount\n"), -1);
	if (!check_args(str))
		return (printf("invalid arguments\n"), -1);
	if (!init_vars(str, c, &info))
		return (printf("error during variable initiation\n"), -1);
	i = -1;
	pid = 1;
	while (++i < c && pid != 0)
	{
		pid = fork();
		if (pid == 0)
			routine(&info.philos[i]);
	}
	while (wait(NULL) != -1)
		;
	free_stuff(&info);
	return (0);
}
