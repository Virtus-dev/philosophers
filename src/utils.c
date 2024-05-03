/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:01:40 by arigonza          #+#    #+#             */
/*   Updated: 2024/05/03 20:20:30 by arigonza         ###   ########.fr       */
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

int	ft_check(t_philosopher philo)
{
	long long	currnt;

	pthread_mutex_lock(philo.eating_mutex);
	currnt = get_current_time(philo.table) - philo.last_meal;
	pthread_mutex_unlock(philo.eating_mutex);
	if (currnt >= philo.table->time_to_die)
	{
		philo.table->died = 1;
		ft_print_msg(philo.table, philo, DIED);
		return (1);
	}
	return (0);
}

int	ft_is_dead(t_philosopher philo)
{
	long long	time;

	pthread_mutex_lock(philo.table->mutex_table);
	pthread_mutex_lock(philo.eating_mutex);
	time = (get_current_time(philo.table) - philo.last_meal);
	pthread_mutex_unlock(philo.eating_mutex);
	if (time >= philo.table->time_to_die)
	{
		ft_print_msg(philo.table, philo, DIED);
		philo.table->died = 1;
		pthread_mutex_unlock(philo.table->mutex_table);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(philo.table->mutex_table);
		return (0);
	}
}

int	ft_check_n_meals(t_table *table)
{
	pthread_mutex_lock(table->mutex_table);
	if (table->finished == table->n_philosophers || table->died == 1)
	{
		pthread_mutex_unlock(table->mutex_table);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(table->mutex_table);
		return (0);
	}
}
