/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:20:21 by arigonza          #+#    #+#             */
/*   Updated: 2024/03/19 19:07:07 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*ft_routine(void *arg)
{
	t_philosopher	*philo;

	philo = arg;
	pthread_mutex_lock(philo->eating_mutex);
	philo->last_meal = get_current_time(philo->table);
	pthread_mutex_unlock(philo->eating_mutex);
	while (ft_check(philo))
	{
		ft_right_left_handler(philo);
		ft_eat(philo);
		ft_sleeping(philo);
		ft_thinking(philo);
	}
	return (NULL);
}

void	ft_create_threads(t_philosopher *philos, t_table *table)
{
	int			i;
	
	i = 0;
	table->started = get_current_time(table);
	while (i < table->n_philosophers)
	{
		if (pthread_create(&philos[i].thread, NULL, ft_routine, &philos[i]))
			ft_error(THREAD_ERR);
		i++;
	}
	usleep(100);
	ft_loop(table);
	ft_free_all(table);
}

void	ft_loop(t_table *table)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < table->n_philosophers)
		{
			if (!ft_check(&table->philosophers[i]))
				return ;
			//usleep(25);
			i++;
		}
	}
	return ;
}