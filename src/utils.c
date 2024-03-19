/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:01:40 by arigonza          #+#    #+#             */
/*   Updated: 2024/03/19 20:48:50 by arigonza         ###   ########.fr       */
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

int	ft_check(t_philosopher philo)
{
	long long	currnt;
	
	pthread_mutex_lock(philo.eating_mutex);
	currnt = get_current_time(philo.table) - philo.last_meal;
	pthread_mutex_unlock(philo.eating_mutex);
	if (currnt >= philo.table->time_to_die || philo.times_eaten >= philo.table->n_times_to_eat)
		return (0);
	return (1);
}

void	ft_free_philos(t_philosopher *philo)
{
	int	i;
	int	n_philo;
	
	i = 0;
	n_philo = philo->table->n_philosophers;
	while (i < n_philo)
	{
		pthread_mutex_destroy(philo[i].eating_mutex);
		free(philo[i].eating_mutex);
		free(philo[i].table);
		i++;
	}
}

void	ft_free_all(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philosophers)
	{
		pthread_join(table->philosophers[i].thread, NULL);
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	ft_free_philos(table->philosophers);
	free(table->forks);
	free(table->philosophers);
	pthread_mutex_destroy(table->print_mutex);
	free(table->print_mutex);
	free(table);
}