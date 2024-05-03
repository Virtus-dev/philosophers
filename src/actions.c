/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:32:40 by arigonza          #+#    #+#             */
/*   Updated: 2024/05/04 00:11:14 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_right_left_handler(t_philosopher *philo)
{
	if (ft_check(*philo))
		return ;
	if (philo->id % 2 == 0)
	{
		if (ft_check(*philo))
			return ;
		pthread_mutex_lock(philo->r_forks);
		ft_print_msg(philo->table, *philo, TAKING_FORKS);
		if (ft_check(*philo))
			return ;
		pthread_mutex_lock(philo->l_forks);
		ft_print_msg(philo->table, *philo, TAKING_FORKS);
	}
	else
	{
		if (ft_check(*philo))
			return ;
		pthread_mutex_lock(philo->l_forks);
		ft_print_msg(philo->table, *philo, TAKING_FORKS);
		if (ft_check(*philo))
			return ;
		pthread_mutex_lock(philo->r_forks);
		ft_print_msg(philo->table, *philo, TAKING_FORKS);
	}
}

void	ft_eat(t_philosopher *philo)
{
	long long	currnt;

	ft_right_left_handler(philo);
	currnt = get_current_time(philo->table);
	ft_print_msg(philo->table, *philo, EATING);
	pthread_mutex_lock(philo->eating_mutex);
	philo->times_eaten++;
	if (philo->times_eaten == philo->table->n_times_to_eat)
	{
		philo->table->finished++;
		//printf("finished-> %d\n", philo->table->finished);
	}
	philo->last_meal = get_current_time(philo->table);
	pthread_mutex_unlock(philo->eating_mutex);
	while (get_current_time(philo->table)
		< (long long)(currnt + philo->table->time_to_eat))
		usleep(1);
	pthread_mutex_unlock(philo->l_forks);
	pthread_mutex_unlock(philo->r_forks);
}

// TODO implement a function to check if someone died while is sleeping.
void	ft_sleeping(t_philosopher *philo)
{
	long long	currnt;

	ft_print_msg(philo->table, *philo, SLEEPING);
	currnt = get_current_time(philo->table);
	while (get_current_time(philo->table)
		< (currnt + philo->table->time_to_sleep))
		usleep(100);
	return ;
}

void	ft_thinking(t_philosopher *philo)
{
	long long	currnt;

	ft_print_msg(philo->table, *philo, THINKING);
	currnt = get_current_time(philo->table);
	while (get_current_time(philo->table)
		< (currnt + philo->table->time_to_think))
		usleep(100);
	return ;
}
