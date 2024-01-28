/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:58:41 by arigonza          #+#    #+#             */
/*   Updated: 2024/01/28 18:30:01 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <sys/time.h>
# include <time.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include "constants.h"

typedef struct s_philosopher
{
	long					time_to_eat;
	long					time_to_sleep;
	long					time_to_die;
	int						n_times_eaten;
	int						id;
	struct s_philosopher			*next;
	struct s_philosopher			*prev;
}			t_philosopher;

typedef struct s_fork
{
	pthread_mutex_t	lock;
	struct s_fork			*next;
}				t_fork;
typedef struct s_table
{
	int				n_philosophers;
	t_philosopher	*philosophers;
	t_fork			*forks;

}					t_table;



/**
 * @brief 
 * Print on the console the actual error.
 * 
 * @return -1 as an error.
 */
int				ft_error(char *error);

/**
 * @brief 
 * Check if there´s only numbers on the parameters.
 * 
 * @return 0 in case of error, 1 in case its all ok.
 */
int				ft_check_argv(int argc, char **argv);

/**
 * @brief 
 * Create a new philosopher and initiates his properties.
 * @param t_die Amount of time it takes to die after his last meal.
 * @param t_eat Amount of time philosopher takes to eat.
 * @param t_sleep Amount of time it takes to sleep.
 * @param id ID of the philosopher.
 * @return The philosopher itself.
 */
t_philosopher	*ft_create_philo(long t_die, long t_eat, long t_sleep, int id);

/**
 * @brief 
 * creates a list of philosophers
 * @param n Number of philosophers to create
 * @param die Amount of time it takes to die after his last meal.
 * @param eat Amount of time philosopher takes to eat.
 * @param sleep Amount of time it takes to sleep.
 * @return A pointer to the head of the list.
 */
t_philosopher	*ft_init_philos(int n, long die, long eat, long sleep);

t_fork	*ft_create_fork(void);

t_fork	*ft_init_forks(int n);

/**
 * @brief
 * Initialize the struct table.
 * @return The table itself
 */
t_table			*ft_init_table();

/**
 * @brief 
 * @return Gets the lapse of time passed
 */
long	get_current_time(struct timeval *start, struct timeval *end);

void	ft_parse(char **argv, t_table *table);

#endif
