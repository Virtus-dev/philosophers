/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:58:41 by arigonza          #+#    #+#             */
/*   Updated: 2024/03/11 15:54:59 by arigonza         ###   ########.fr       */
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

// Structs

typedef struct s_philosopher
{
	int						id;
	pthread_t				thread_id;
	pthread_mutex_t			*r_fork;
	pthread_mutex_t			*l_fork;
	int						times_eaten;
}			t_philosopher;

typedef struct s_table
{
	int				n_philosophers;
	long			time_to_eat;
	long			time_to_sleep;
	long			time_to_die;
	long			time_to_think;
	int				n_times_to_eat;
	t_philosopher	*philosophers;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*table_mutex;
	long long			started;
}					t_table;

// Structs end

/**
 * @brief 
 * Print on the console the actual error.
 */
void			ft_error(char *error);

/**
 * @brief Prints the message of the state of the philosopher.
 * 
 * @param table 
 * @param philo 
 * @param state 
 */
void    ft_print_msg(t_table *table, t_philosopher *philo, int state);

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
 * @param id ID of the philosopher.
 * @return The philosopher itself.
 */
t_philosopher	ft_create_philo(int id);

/**
 * @brief 
 * creates an array of philosophers
 * @param n Number of philosophers to create
 * @return The array itself.
 */
t_philosopher	*ft_init_philos(int n);


/**
 * @brief Creates an array of forks.
 * 
 * @param n Number of forks to be created.
 * @return An array of forks.
 */
pthread_mutex_t			*ft_init_forks(int n);

/**
 * @brief Free's all the mutex.
 * 
 * @param forks An array of mutex to be freed.
 * @param n Number of mutex to be freed.
*/
void			ft_free_mutex(pthread_mutex_t *forks, int n);

/**
 * @brief Initialize the struct table.
 * @return The table itself
 */
t_table			*ft_init_table(int n_philosophers);

/**
 * @brief 
 * Retrieves the operating system's time values. To begin with, we
 * call gettimeofday, which provides us with the count of seconds (tv_sec) and
 * microseconds (tv_usec) that have transpired since 01/01/1970 – a date selected
 * for technical considerations. Subsequently, we convert each value to
 * milliseconds.
*/
long long		get_sys_time(void);

/**
 * @brief Gets the lapse of time passed since the start of the
 * program.
 * @return long
 */
long long		get_current_time(t_table *table);

/**
 * @brief Parse de char* into int and longs,
 *  And fill up the table struct.
 * @param argv char** to be parsed.
 * @param table table to fill up. 
 */
void			ft_parse(char **argv, t_table *table);

#endif
