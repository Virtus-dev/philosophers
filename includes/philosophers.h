/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:58:41 by arigonza          #+#    #+#             */
/*   Updated: 2024/02/01 14:38:24 by arigonza         ###   ########.fr       */
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
	int						id;
	pthread_t				thread_id;
	pthread_mutex_t			*r_fork;
	pthread_mutex_t			*l_fork;
	int						times_eaten;
	struct s_philosopher	*next;
}			t_philosopher;

typedef struct s_table
{
	int				n_philosophers;
	long			time_to_eat;
	long			time_to_sleep;
	long			time_to_die;
	long			time_to_think;
	int				n_times_to_eat;
	t_philosopher	**philosophers;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*table_mutex;
	long long			started;
}					t_table;

/**
 * @brief 
 * Print on the console the actual error.
 * 
 * @return -1 as an error.
 */
void			ft_error(char *error);

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
t_philosopher	*ft_create_philo(int id);

/**
 * @brief 
 * creates a list of philosophers
 * @param n Number of philosophers to create
 * @return A pointer to the head of the list.
 */
t_philosopher	**ft_init_philos(int n);


/**
 * @brief Creates an array of forks.
 * 
 * @param t_table
 * @return An array of forks.
 */
void			ft_init_forks(t_table *table);

/**
 * @brief 
 * 
 * @param t_table*
*/
void			ft_free_mutex(t_table *table);

/**
 * @brief Initialize the struct table.
 * @return The table itself
 */
t_table			*ft_init_table();

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
