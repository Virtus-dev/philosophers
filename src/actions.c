/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:32:40 by arigonza          #+#    #+#             */
/*   Updated: 2024/03/15 21:25:25 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void    ft_right_left_handler(t_table *table, t_philosopher philo)
{
	if (philo.id % 2 == 0)
	{
		pthread_mutex_lock(&table->forks[philo.id + 1]);
		ft_print_msg(table, philo, TAKING_FORKS);
		pthread_mutex_lock(&table->forks[philo.id]);
		ft_print_msg(table, philo, TAKING_FORKS);
		

	}else
	{
		pthread_mutex_lock(&table->forks[philo.id]);
		ft_print_msg(table, philo, TAKING_FORKS);
		pthread_mutex_lock(&table->forks[philo.id + 1]);
		ft_print_msg(table, philo, TAKING_FORKS);
	}
}

void	ft_eat(t_table *table, int id)
{
		ft_print_msg(table, table->philosophers[id], EATING);
		pthread_mutex_lock(&table->philosophers[id].eating_mutex);
		table->philosophers[id].last_meal = get_current_time(table);
		pthread_mutex_unlock(&table->philosophers[id].eating_mutex);
		
		pthread_mutex_unlock(&table->forks[table->philosophers[id].id]);
		pthread_mutex_unlock(&table->forks[table->philosophers[id].id + 1]);
}

// TODO implement a function to check if someone died while is sleeping.
void	ft_sleeping(t_table *table, int id)
{
	long long	currnt;
	
	ft_print_msg(table, table->philosophers[id], SLEEPING);
	currnt = get_current_time(table);
	while (get_current_time(table) < (currnt + table->time_to_sleep))
		usleep(100);
	return ;
}
void	ft_thinking(t_table *table, int id)
{
	long long	currnt;

	ft_print_msg(table, table->philosophers[id], THINKING);
	currnt = get_current_time(table);
	while (get_current_time(table) < (currnt + table->time_to_think))
		usleep(100);
	return ;
}