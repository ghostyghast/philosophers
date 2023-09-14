/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pringles <pringles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:07:40 by amaligno          #+#    #+#             */
/*   Updated: 2023/09/14 18:00:26 by pringles         ###   ########.fr       */
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
			if (str[i][j] < '0' || str[i][j] > '9')
				return (0);
	}
	return (1);
}

void	life(t_philo *philo)
{
	print_state(philo, THINKING);
	take_fork(philo);
	take_fork(philo);
	print_state(philo, EATING);
	ft_usleep(philo->info->time_eat);
	put_forks(philo);
	if (check_death(philo))
		philo->die_time = ft_gettime() + philo->info->time_die;
	print_state(philo, SLEEPING);
	ft_usleep(philo->info->time_sleep);
}

void	routine(t_philo *philo)
{
	int	i;

	i = -1;
	if (philo->philo_number % 2 == 0)
	{
		print_state(philo	, THINKING);
		ft_usleep(philo->info->time_eat);
	}
	philo->die_time = ft_gettime() + philo->info->time_die;
	if (philo->info->meal_amnt > 0)
		while (++i < philo->info->meal_amnt && check_death(philo))
			life(philo);
	else
		while (check_death(philo))
			life(philo);
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
	info.base_time = ft_gettime();
	while (++i < info.philo_amount && pid != 0)
	{
		pid = fork();
		info.philos.philo_number++;
		if (pid == 0)
			routine(&info.philos);
	}
	pid = waitpid(-1, NULL, 0);
	i = -1;
	kill(0, SIGINT);
	free_stuff(&info);
	return (0);
}

// void	kill_processes(t_info info)
// {
	
// }
