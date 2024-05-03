/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:36:54 by arigonza          #+#    #+#             */
/*   Updated: 2024/05/03 23:50:40 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

t_philosopher	ft_create_philo(int id, t_table *table)
{
	t_philosopher	philo;

	philo.id = id;
	philo.eating_mutex = malloc(sizeof(pthread_mutex_t));
	if (!philo.eating_mutex)
		ft_error(MUTEX_ERR);
	if (pthread_mutex_init(philo.eating_mutex, NULL) != 0)
		ft_error(MUTEX_ERR);
	philo.times_eaten = 0;
	philo.table = table;
	philo.last_meal = 0;
	return (philo);
}

// t_philosopher	*ft_init_philos(int n, t_table *table)
// {
// 	int				i;
// 	t_philosopher	*philos;

// 	i = 0;
// 	philos = (t_philosopher *)malloc(sizeof(t_philosopher) * n);
// 	while (i < n)
// 	{
// 		philos[i] = ft_create_philo((i + 1), table);
// 		i++;
// 	}
// 	return (philos);
// }

void	ft_init_philosophers(t_philosopher *philo, t_table *table)
{
	int	i;

	i = -1;
	while (i++ < table->n_philosophers - 1)
	{
		philo[i].id = i + 1;
		philo[i].times_eaten = 0;
		philo[i].last_meal = 0;
		philo[i].table = table;
		philo[i].eating_mutex = malloc(sizeof(pthread_mutex_t));
		if (!philo[i].eating_mutex)
			ft_error(MALLOC_ERR);
		if ((pthread_mutex_init(philo[i].eating_mutex, NULL)) != 0)
			ft_error(MUTEX_ERR);
		if (philo[i].id == table->n_philosophers)
		{
			philo[i].l_fork = &table->forks[i];
			philo[i].r_fork = &table->forks[0];
		}
		else
		{
			philo[i].l_fork = &table->forks[i];
			philo[i].r_fork = &table->forks[i + 1];
		}
	}
}

void	ft_init_table(int argc, char **argv, t_table *table)
{
	table->n_philosophers = ft_atol(argv[1]);
	if (table->n_philosophers < 1 || table->n_philosophers > 200)
		ft_error(EXCED_LIMIT);
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	table->time_to_think = (table->time_to_die - \
		(table->time_to_eat + table->time_to_sleep)) / 2;
	if (argc == 6)
	{
		table->n_times_to_eat = ft_atol(argv[5]);
		if (table->n_times_to_eat == 0)
			ft_error(EXCED_LIMIT);
	}
	else
		table->n_times_to_eat = -1;
	table->finished = 0;
	table->died = 0;
	table->mutex_table = malloc(sizeof(pthread_mutex_t));
	if (!table->mutex_table)
		ft_error(MALLOC_ERR);
	if ((pthread_mutex_init(table->mutex_table, NULL)) != 0)
		ft_error(MUTEX_ERR);
	ft_init_forks(table);
}

void	ft_init_forks(t_table *table)
{
	int				i;

	i = 0;
	table->forks = malloc(sizeof(pthread_mutex_t) * table->n_philosophers);
	if (!table->forks)
	{
		ft_error(MALLOC_ERR);
	}
	while (i < table->n_philosophers)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
		{
			ft_free_mutex(table);
			ft_error(MALLOC_ERR);
		}
		i++;
	}
}
