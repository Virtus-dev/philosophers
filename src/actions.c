/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:32:40 by arigonza          #+#    #+#             */
/*   Updated: 2024/05/04 12:58:05 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_right_left_handler(t_philosopher *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->r_fork);
		ft_print_msg(philo->table, *philo, TAKING_FORKS);
		if (ft_must_stop(philo->table))
			return ;
		pthread_mutex_lock(philo->l_fork);
		ft_print_msg(philo->table, *philo, TAKING_FORKS);
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		ft_print_msg(philo->table, *philo, TAKING_FORKS);
		if (ft_must_stop(philo->table))
			return ;
		pthread_mutex_lock(philo->r_fork);
		ft_print_msg(philo->table, *philo, TAKING_FORKS);
	}
}

void	*ft_eat(t_philosopher *philo)
{
	ft_right_left_handler(philo);
	ft_print_msg(philo->table, *philo, EATING);
	pthread_mutex_lock(philo->eating_mutex);
	philo->last_meal = get_current_time(philo->table);
	pthread_mutex_unlock(philo->eating_mutex);
	philo->times_eaten++;
	if (philo->times_eaten == philo->table->n_times_to_eat)
	{
		pthread_mutex_lock(philo->table->mutex_table);
		philo->table->finished++;
		pthread_mutex_unlock(philo->table->mutex_table);
	}
	while (!ft_must_stop(philo->table) && (get_current_time(philo->table)
		< get_current_time(philo->table) + philo->table->time_to_eat))
		usleep(1);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	return (NULL);
}

void	*ft_sleeping(t_philosopher *philo)
{
	long long	currnt;

	ft_print_msg(philo->table, *philo, SLEEPING);
	currnt = get_current_time(philo->table);
	while (!ft_must_stop(philo->table) && (get_current_time(philo->table)
		< (currnt + philo->table->time_to_sleep)))
		usleep(100);
	return (NULL);
}

void	*ft_thinking(t_philosopher *philo)
{
	long long	currnt;

	ft_print_msg(philo->table, *philo, THINKING);
	currnt = get_current_time(philo->table);
	while (get_current_time(philo->table)
		< (currnt + philo->table->time_to_think))
		usleep(100);
	return (NULL);
}
