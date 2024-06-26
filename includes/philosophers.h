/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:58:41 by arigonza          #+#    #+#             */
/*   Updated: 2024/05/04 12:59:08 by arigonza         ###   ########.fr       */
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

typedef struct s_table	t_table;

typedef struct s_philosopher
{
	int						id;
	pthread_t				thread;
	pthread_mutex_t			*eating_mutex;
	int						times_eaten;
	long long				last_meal;
	pthread_mutex_t			*r_fork;
	pthread_mutex_t			*l_fork;
	t_table					*table;
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
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*mutex_table;
	int				finished;
	long long		started;
	int				died;
}					t_table;

// Structs end

int	ft_is_dead(t_philosopher philo);

int	ft_must_stop(t_table *table);

long	ft_atol(char *str);

void	print_philos(t_table *table);

/**
 * @brief Checks if someone died.
 * 
 * @param philo 
 * @return int return 0 if the philosopher passed by parameter died 1 if is not.
 */
int	ft_check(t_philosopher philo);

/**
 * @brief check if all philosophers had eaten the total number of times.
 * 
 * @param philos
 * @return int 
 */
int	ft_check_n_meals(t_table *table);

/**
 * @brief 
 * Print on the console the actual error.
 */
void			ft_error(char *error);

/**
 * @brief Prints the message of the state of the philosopher.
 * 
 * @param table The handler.
 * @param philo The philosopher to print information by.
 * @param state The actual state (thinking, sleeping, eating...).
 */
void    ft_print_msg(t_table *table, t_philosopher philo, int state);

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
t_philosopher	ft_create_philo(int id, t_table *table);

/**
 * @brief 
 * creates an array of philosophers
 * @param n Number of philosophers to create
 * @return An array of philosophers.
 */
// t_philosopher	*ft_init_philos(int n, t_table *table);
void	ft_init_philosophers(t_philosopher *philo, t_table *table);
/**
 * @brief Creates an array of forks.
 * 
 * @param n Number of forks to be created.
 * @return An array of forks(pthread_mutex_t).
 */
void		ft_init_forks(t_table *table);

/**
 * @brief Free's all the mutex.
 * 
 * @param forks An array of mutex to be freed.
 * 
*/
void			ft_free_mutex(t_table *table);

/**
 * @brief Initialize the struct table parsing the arguments passed by.
 * @param argv The arguments passed by the user.
 * @return The table itself.
 */
void	ft_init_table(int argc, char **argv, t_table *table);

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
 * @return long long
 */
long long		get_current_time(t_table *table);

/**
 * @brief Parse de char* into int and longs,
 *  And fill up the table struct.
 * @param argv char** to be parsed.
 * @param table table to fill up. 
 */
void			ft_parse(char **argv, t_table *table);

/**
 * @brief 
 * 
 * @param table 
 */
void	ft_create_threads(t_philosopher *philos, t_table *table);

void	*ft_one_philo(void *arg);

/**
 * @brief 
 * 
 * @param arg 
 * @return void* 
 */
void	*ft_routine(void *arg);

/**
 * @brief 
 * 
 * @param table 
 */
void	ft_loop(t_table *table);

/**
 * @brief Checks if every philosopher is still alive.
 * @return 1 if all of them are alive, 0 in case someone died.
 */
int	ft_dead_check(t_philosopher *philo);

/**
 * @brief 
 * 
 * @param table 
 * @param philo 
 */
void    ft_right_left_handler(t_philosopher *philo);

/**
 * @brief 
 * 
 * @param table 
 * @param id 
 */
void	*ft_eat(t_philosopher *philo);

/**
 * @brief 
 * 
 * @param philo
 */
void	*ft_sleeping(t_philosopher *philo);

/**
 * @brief 
 * 
 * @param philo
 */
void	*ft_thinking(t_philosopher *philo);

/**
 * @brief 
 * 
 * @param table 
 */
void	ft_free_all(t_table *table);

/**
 * @brief 
 * 
 * @param philo 
 */
void	ft_free_philos(t_philosopher *philo);

#endif
