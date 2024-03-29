/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:44:41 by arigonza          #+#    #+#             */
/*   Updated: 2024/03/14 21:14:55 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

// errors
# define INVALID_INPUT "Invalid input."
# define INVALID_N_ARGV "Invalid number of arguments!"
# define PARSING_EXPL "Follow the following rules: ./philo num_of_philos time_to_die time_to_eat time_to_sleep"
# define MALLOC_ERR "Malloc failed."
# define THREAD_ERR "Error creating thread"
# define MUTEX_ERR "Mutex error."

// States
# define TAKING_FORKS 1
# define EATING 2
# define SLEEPING 3
# define THINKING 4
# define DIED 5

// Colors Start
# define FRED "\033[0;31m"
# define FGREEN "\033[0;32m"
# define FYELLOW "\033[0;33m"
# define FBLUE "\033[0;34m"
# define FPURPLE "\033[0;35m"
# define WHITE "\033[0;37m"
# define DEF_COLOR "\033[0;39m"
// Colors End

#endif