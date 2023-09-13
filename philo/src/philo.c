/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <antoinemalignon@yahoo.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:49:12 by amaligno          #+#    #+#             */
/*   Updated: 2023/09/14 01:05:25 by amaligno         ###   ########.fr       */
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

void	*one_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->info->base_time = ft_gettime();
	philo->die_time = (ft_gettime() - philo->info->base_time) + philo->info->time_die;
	take_fork(philo, philo->l_fork);
	print_state(philo, THINKING);
	while (1)
		if (!check_death(philo))
			return (arg);
	return (arg);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		i;

	i = -1;
	philo = (t_philo *)arg;
	if (philo->philo_number % 2 == 0)
		ft_usleep(philo->info->time_eat);
	philo->die_time = ft_gettime() + philo->info->time_die;
	if (philo->info->meal_amnt > 0)
	{
		while (++i < philo->info->meal_amnt && check_death(philo))
			life(philo);
	}
	else
		while (check_death(philo))
			life(philo);
	return (NULL);
}

void	life(t_philo *philo)
{
	print_state(philo, THINKING);
	take_fork(philo, philo->r_fork);
	take_fork(philo, philo->l_fork);
	print_state(philo, EATING);
	ft_usleep(philo->info->time_eat);
	put_forks(philo);
	if (check_death(philo))
		philo->die_time = ft_gettime() + philo->info->time_die;
	print_state(philo, SLEEPING);
	// u_int64_t time = ft_gettime();
	ft_usleep(philo->info->time_sleep);
	// printf ("time sleep %lu\n", ft_gettime() - time);
}


int	main(int c, char **str)
{
	t_info	info;
	int		i;

	if (c != 5 && c != 6)
		return (printf("invalid arg amount\n"), -1);
	if (!check_args(str))
		return (printf("invalid arguments\n"), -1);
	if (init_vars(str, c, &info) <= 0)
		return (printf("error during variable initiation\n"), -1);
	i = -1;
	info.base_time = ft_gettime();
	if (atoi(str[1]) == 1)
		pthread_create(&info.philos[0].th_id, NULL, one_philo, &info.philos[0]);
	else
		while (++i < info.philo_amount)
			pthread_create(&info.philos[i].th_id, NULL, routine,
				&info.philos[i]);
	i = -1;
	while (++i < info.philo_amount)
		pthread_join(info.philos[i].th_id, NULL);
	free_stuff(&info);
	return (0);
}
