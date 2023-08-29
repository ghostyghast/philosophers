/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:35:19 by amaligno          #+#    #+#             */
/*   Updated: 2023/08/29 18:00:46 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <stdio.h>
# include "libft.h"

//status 1 : eating, 2 : thinking, 3 :sleeping
typedef struct s_philo
{
	struct s_info	*info;
	pthread_t		th_id;
	int				philo_number;
	int				die_time;
	int				status;
	pthread_mutex_t	*lock;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}		t_philo;

typedef struct s_info
{
	t_philo			*philos;
	int				philo_amount;
	int				meal_amnt;
	u_int64_t		time_die;
	u_int64_t		time_eat;
	u_int64_t		time_sleep;
	bool			dead;

	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	print;
}		t_info;

long	ft_atoi(char *str);
int		life(t_philo *philo);

#endif