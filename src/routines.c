/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:20:21 by arigonza          #+#    #+#             */
/*   Updated: 2024/03/14 20:24:31 by arigonza         ###   ########.fr       */
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
void	ft_sleep(t_table *table, t_philosopher philo)
{
	long long	start;
	
	start = get_current_time(table);
	while (get_current_time(table) < (start + table->time_to_sleep))
		usleep(100);
	return (NULL);
}
