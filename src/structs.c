/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:36:54 by arigonza          #+#    #+#             */
/*   Updated: 2024/03/18 16:35:27 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

t_philosopher	ft_create_philo(int id, t_table *table)
{
	t_philosopher	philo;
	
	philo.id = id;
	philo.eating_mutex = malloc(sizeof(pthread_mutex_t));
	philo.times_eaten = 0;
	philo.table = table;
	return (philo);
}

t_philosopher	*ft_init_philos(int n, t_table *table)
{
	int				i;
	t_philosopher	*philos;

	i = 0;
	philos = malloc(sizeof(t_philosopher *) * n);
	while (i < n)
	{
		philos[i] = ft_create_philo((i + 1), table);
		i++;
	}
	return (philos);
}

t_table	*ft_init_table(char **argv)
{
	t_table			*table;
	int				n_philosophers;
	
	n_philosophers = atoi(argv[1]);
	table = (t_table *)malloc(sizeof(t_table));
	table->time_to_die = (long)atoi(argv[2]);
	table->time_to_eat = (long)atoi(argv[3]);
	table->time_to_sleep = (long)atoi(argv[4]); 
	table->n_philosophers = n_philosophers;
	table->time_to_think = (table->time_to_die - (table->time_to_sleep + table->time_to_eat)) / 2;
	table->forks = ft_init_forks(n_philosophers);
	table->philosophers = ft_init_philos(n_philosophers, table);
	return (table);
}

pthread_mutex_t	*ft_init_forks(int n)
{
	int				i;
	pthread_mutex_t	*forks;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * n);
	if (!forks)
	{
		ft_free_mutex(forks, n);
		ft_error(MALLOC_ERR);
	}
	while (i < n)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0) 
		{
			ft_free_mutex(forks, n);
			ft_error(MALLOC_ERR);
		}
		i++;
	}
	return (forks);
}
