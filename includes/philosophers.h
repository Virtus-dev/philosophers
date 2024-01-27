/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:58:41 by arigonza          #+#    #+#             */
/*   Updated: 2024/01/27 17:03:28 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "constants.h"

typedef struct s_philosopher
{
	long	time_to_eat;
	long	time_to_sleep;
	long	time_to_think;
	long	time_to_die;
	int		n_times_to_eat;
}			t_philosopher;

typedef struct s_table
{
    int				n_philosophers;
	t_philosopher	*philosophers;

}		t_table;

typedef struct s_fork
{
	pthread_mutex_t	lock;
	
}					t_fork;

/**
 * @brief 
 * Print on the console the actual error.
 * 
 * @return -1 as an error.
 */
int	ft_error(char *error);

/**
 * @brief 
 * 
 * Check if there´s only numbers on the parameters.
 * 
 * @return 0 in case of error, 1 in case its all ok.
 */
int	ft_check_argv(int   argc, char **argv);


#endif