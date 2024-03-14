/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:01:40 by arigonza          #+#    #+#             */
/*   Updated: 2024/03/14 20:59:16 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long long	get_sys_time(void)
{
	struct timeval	tv;
	
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

long long	get_current_time(t_table *table)
{
	return (get_sys_time() - table->started);
}

void	ft_free_mutex(pthread_mutex_t *forks, int n)
{
	int	i;
	
	i = 0;
	while (i < n)
		pthread_mutex_destroy(&(forks[i++]));
}

int	ft_dead_check(t_table *table)
{
	int			i;
	long long	currnt;
	
	i = 0;
	currnt = get_current_time(table);
	while (i < table->n_philosophers)
	{
		if (table->philosophers[i].last_meal > (currnt + table->time_to_die))
			return (0);
		i++;
	}
	return (1);
}