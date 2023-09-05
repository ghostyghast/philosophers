/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:02:09 by amaligno          #+#    #+#             */
/*   Updated: 2023/09/05 18:34:59 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdbool.h>
# include <semaphore.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>

# define DEAD "died"
# define EATING "is eating"
# define THINKING "is thinking"
# define SLEEPING "is sleeping"
# define TAKE_FORK "has taken a fork"

typedef struct s_philo
{
	struct s_info	*info;
	int				philo_number;
	u_int64_t		die_time;
	int				hand;
}		t_philo;

typedef struct s_info
{
	t_philo			*philos;
	int				philo_amount;
	int				meal_amnt;
	u_int64_t		time_die;
	u_int64_t		time_eat;
	u_int64_t		time_sleep;
	sem_t			*print;
	sem_t			*death;
	sem_t			*forks;
	bool			dead;

}		t_info;

//life cycle
int			sleepy(t_philo *philo);
int			think(t_philo *philo);
int			eat(t_philo *philo);
int			life(t_philo *philo);

//init
int			init_vars(char **str, int c, t_info *info);

//forks
void		take_fork(t_philo *philo);
void		put_fork(t_philo *philo);
void		put_forks(t_philo *philo);

//utils
int			check_death(t_philo *philo);
long		ft_atoi(char *str);
void		print_state(t_philo *philo, char *status);
void		ft_usleep(u_int64_t time);
void		free_stuff(t_info *info);
u_int64_t	ft_gettime(void);

#endif