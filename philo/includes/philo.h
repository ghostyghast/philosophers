/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:35:19 by amaligno          #+#    #+#             */
/*   Updated: 2023/09/15 17:59:43 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/types.h>
# include <stdio.h>

# define DEAD "died"
# define EATING "is eating"
# define THINKING "is thinking"
# define SLEEPING "is sleeping"
# define TAKE_FORK "has taken a fork"

typedef struct s_philo
{
	struct s_info	*info;
	pthread_t		th_id;
	int				philo_number;
	int				hand;
	int				meals_eaten;
	u_int64_t		die_time;
	pthread_mutex_t	*lock;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}		t_philo;

typedef struct s_info
{
	t_philo			*philos;
	int				philo_amount;
	int				meal_amnt;
	u_int64_t		base_time;
	u_int64_t		time_die;
	u_int64_t		time_eat;
	u_int64_t		time_sleep;
	int				meals_eaten;
	bool			all_full;
	bool			dead;
	pthread_mutex_t	lock;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
}		t_info;

//life
void		life(t_philo *philo);

//init
int			init_vars(char **str, int c, t_info *info);

//forks
void		take_fork(t_philo *philo, pthread_mutex_t *fork);
void		put_fork(pthread_mutex_t *fork);
void		put_forks(t_philo *philo);

//utils (smart sleep is in forks.c cuz no space lol )
void		smart_sleep(t_philo *philo, u_int64_t time);
int			check_death(t_philo *philo);
long		ft_atoi(char *str);
void		print_state(t_philo *philo, char *status);
void		ft_usleep(u_int64_t time);
void		free_stuff(t_info *info);
u_int64_t	ft_gettime(void);

#endif