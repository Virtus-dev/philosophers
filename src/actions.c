/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:32:40 by arigonza          #+#    #+#             */
/*   Updated: 2024/05/01 18:37:13 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void    ft_right_left_handler(t_philosopher *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->table->forks[philo->id + 1]);
		ft_print_msg(philo->table, *philo, TAKING_FORKS);
		pthread_mutex_lock(&philo->table->forks[philo->id]);
		ft_print_msg(philo->table, *philo, TAKING_FORKS);
		

	}else
	{
		pthread_mutex_lock(&philo->table->forks[philo->id]);
		ft_print_msg(philo->table, *philo, TAKING_FORKS);
		pthread_mutex_lock(&philo->table->forks[philo->id + 1]);
		ft_print_msg(philo->table, *philo, TAKING_FORKS);
	}
}

void	ft_eat(t_philosopher *philo)
{
	long long	currnt;
	
	currnt = get_current_time(philo->table);
	ft_print_msg(philo->table, *philo, EATING);
	pthread_mutex_lock(philo->eating_mutex);
	philo->times_eaten++;
	philo->last_meal = get_current_time(philo->table);
	pthread_mutex_unlock(philo->eating_mutex);
	while (get_current_time(philo->table) < (currnt + philo->table->time_to_eat))
		usleep(100);	
	pthread_mutex_unlock(&philo->table->forks[philo->id]);
	pthread_mutex_unlock(&philo->table->forks[philo->id + 1]);
}

// TODO implement a function to check if someone died while is sleeping.
void	ft_sleeping(t_philosopher *philo)
{
	long long	currnt;
	
	ft_print_msg(philo->table, *philo, SLEEPING);
	currnt = get_current_time(philo->table);
	while (get_current_time(philo->table) < (currnt + philo->table->time_to_sleep))
		usleep(100);
	return ;
}
void	ft_thinking(t_philosopher *philo)
{
	// long long	currnt;

	ft_print_msg(philo->table, *philo, THINKING);
	// currnt = get_current_time(philo->table);
	// while (get_current_time(philo->table) < (currnt + philo->table->time_to_think))
	// 	usleep(100);
	return ;
}