/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:01:40 by arigonza          #+#    #+#             */
/*   Updated: 2024/03/18 19:10:38 by arigonza         ###   ########.fr       */
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

int	ft_check(t_philosopher *philo)
{
	long long	currnt;
	
	//mutex por favor
	pthread_mutex_lock(philo->eating_mutex);
	currnt = get_current_time(philo->table) - philo->last_meal;
	pthread_mutex_unlock(philo->eating_mutex);
	if (currnt >= philo->table->time_to_die)
		return (ft_print_msg(philo->table, *philo, DIED), 0);
	return (1);
}