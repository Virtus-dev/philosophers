/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:20:21 by arigonza          #+#    #+#             */
/*   Updated: 2024/03/14 21:20:04 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_routine(void *arg)
{
	t_table		*table;
	int			i;

	i = 0;
	table = arg;
	while (ft_dead_check(table))
	{
		ft_right_left_handler(table, table->philosophers[i]);
		ft_eat(table, table->philosophers[i].id);
		ft_sleeping(table, table->philosophers[i].id);
		ft_thinking(table, table->philosophers[i].id);
	}
}

void	ft_create_threads(t_table *table)
{
	int			i;
	
	i = 0;
	table->started = get_current_time(table);
	while (i < table->n_philosophers)
	{
		if (!pthread_create(&table->philosophers[i].thread, NULL, ft_routine, &table))
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