/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:35:19 by amaligno          #+#    #+#             */
/*   Updated: 2023/08/16 14:15:30 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_philosopher
{
	int	philo_number;
	int	die_count;
	int	eat_count;
	int	sleep_count;
	int	number_eat;
}		t_philosopher;

typedef struct s_info
{
	int	philo_amount;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	
}		t_info;

#endif