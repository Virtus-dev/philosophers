/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:20:21 by arigonza          #+#    #+#             */
/*   Updated: 2024/05/03 20:20:56 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*ft_one_philo(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	if (philo->table->n_times_to_eat == 0)
		return (NULL);
	if (philo->table->time_to_die == 0)
		return (NULL);
	philo->last_meal = get_current_time(philo->table);
	pthread_mutex_lock(&philo->table->forks[0]);
	ft_print_msg(philo[0].table, philo[0], TAKING_FORKS);
	pthread_mutex_unlock(&philo->table->forks[0]);
	while ((get_current_time(philo->table) + philo->last_meal) \
		< philo->table->time_to_die)
		usleep(100);
	ft_print_msg(philo[0].table, philo[0], DIED);
	return (NULL);
}

void	*ft_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	if (philo->table->time_to_die == 0)
		return (NULL);
	while (get_current_time(philo->table) < 0)
	{
		pthread_mutex_lock(philo->eating_mutex);
		philo->last_meal = get_current_time(philo->table);
		pthread_mutex_unlock(philo->eating_mutex);
		usleep(20);
	}
	if (philo->id % 2 == 0)
		usleep(50);
	philo->last_meal = get_current_time(philo->table);
	while (philo->table->died != 1 || ft_check_n_meals(philo->table))
	{
		pthread_mutex_lock(philo->eating_mutex);
		philo->last_meal = get_current_time(philo->table);
		pthread_mutex_unlock(philo->eating_mutex);
		if (!ft_check(*philo))
			ft_eat(philo);
		if (!ft_check(*philo))
			ft_sleeping(philo);
		if (!ft_check(*philo))
			ft_thinking(philo);
	}
	return (NULL);
}

void	ft_create_threads(t_philosopher *philos, t_table *table)
{
	int			i;
	int			n_philos;

	i = 0;
	n_philos = table->n_philosophers;
	table->started = get_current_time(table);
	if (n_philos == 1)
	{
		if (pthread_create(&philos[i].thread, NULL, ft_one_philo, &philos[i]))
			ft_error(THREAD_ERR);
	}
	else
	{
		while (i < n_philos)
		{
			if (pthread_create(&philos[i].thread, NULL, ft_routine, &philos[i]))
				ft_error(THREAD_ERR);
			i++;
		}
	}
	usleep(200);
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
			if (ft_is_dead(table->philosophers[i]))
				break ;
			i++;
		}
		if (ft_check_n_meals(table))
			break ;
		usleep(100);
	}
	return ;
}
