/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:36:54 by arigonza          #+#    #+#             */
/*   Updated: 2024/05/14 12:16:48 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/*
void	print_philos(t_table *table)
{
	int	i;
	int	n_philos;

	i = 0;
	n_philos = table->n_philosophers;
	printf("N_PHILOS = %d\n", n_philos);
	while (i < n_philos)
	{
		printf("PHILOSOPHER ID -> %d\n", table->philosophers[i].id);
		printf("PHILOSOPHER MUTEX_ADDRESS -> %p\n", table->philosophers[i].eating_mutex);
		printf("PHILOSOPHER LAST_MEAL -> %lld\n", table->philosophers[i].last_meal);
		printf("PHILOSOPHER TIMES_EATEN -> %d\n", table->philosophers[i].times_eaten);
		printf("PHILOSOPHER R_FORK ADDRESS -> %p\n", table->philosophers[i].r_fork);
		printf("PHILOSOPHER L_FORK ADDRESS -> %p\n\n\n", table->philosophers[i].l_fork);
		i++;
	}
}
*/

void	ft_init_philosophers(t_philosopher *philo, t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philosophers)
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
		i++;
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
	table->philosophers = malloc(sizeof(t_philosopher) * table->n_philosophers);
	if (!table->philosophers)
		ft_error(MALLOC_ERR);
	table->print_mutex = malloc(sizeof(pthread_mutex_t));
	if (!table->print_mutex)
		ft_error(MALLOC_ERR);
	pthread_mutex_init(table->print_mutex, NULL);
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
