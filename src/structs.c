/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:36:54 by arigonza          #+#    #+#             */
/*   Updated: 2024/03/11 16:01:11 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

t_philosopher	ft_create_philo(int id)
{
	t_philosopher	*philo;
	
	philo = (t_philosopher *)malloc(sizeof(t_philosopher));
	philo->id = id;
	return (*philo);
}

t_philosopher	*ft_init_philos(int n)
{
	int				i;
	t_philosopher	*philos;

	i = 0;
	philos = malloc(sizeof(t_philosopher) * n);
	//philos[0] = ft_create_philo(i);
	while (i <= n)
	{
		philos[i] = ft_create_philo((i + 1));
		i++;
	}
	return (philos);
}

t_table	*ft_init_table(int n_philosophers)
{
	t_table			*table;
	struct timeval	start;

	table = (t_table *)malloc(sizeof(t_table));
	table->n_philosophers = 0;
	table->philosophers = ft_init_philos(n_philosophers);
	table->forks = ft_init_forks(n_philosophers);
	table->started = gettimeofday(&start, NULL);
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
