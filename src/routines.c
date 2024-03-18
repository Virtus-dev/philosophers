/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:20:21 by arigonza          #+#    #+#             */
/*   Updated: 2024/03/18 16:41:24 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*ft_routine(void *arg)
{
	t_philosopher	*philo;

	philo = arg;
	while (ft_dead_check(philo->table))
	{
		/*ft_right_left_handler(table, table->philosophers[i]); */
		ft_eat(philo->table, philo->id);
		ft_sleeping(philo->table, philo->id);
		ft_thinking(philo->table, philo->id);
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
	ft_loop(table);
}

void	ft_loop(t_table *table)
{
	while (1)
	{
		if (!ft_dead_check(table))
			break;
		usleep(100);
	}
	return ;
}