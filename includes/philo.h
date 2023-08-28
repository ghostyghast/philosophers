/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:35:19 by amaligno          #+#    #+#             */
/*   Updated: 2023/08/28 19:04:53 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"

//status 1 : eating, 2 : thinking, 3 :sleeping
typedef struct s_philo
{
	struct s_info	*data;
	int				philo_number;
	int				die_time;
	int				number_eat;
	int				status;
	pthread_mutex_t	*lock;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}		t_philo;

typedef struct s_info
{
	t_philo			*philo_ids;
	int				philo_amount;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	pthread_mutex_t	lock;
	pthread_mutex_t	print;
}		t_info;

#endif