/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:36:54 by arigonza          #+#    #+#             */
/*   Updated: 2024/02/01 14:54:21 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

t_philosopher	*ft_create_philo(int id)
{
	t_philosopher	*philo;
	
	philo = malloc(sizeof(t_philosopher));
	philo->id = id;
	philo->next = NULL;
	return (philo);
}

t_philosopher	**ft_init_philos(int n)
{
	int				i;
	t_philosopher	**philos;

	i = 1;
	philos = (t_philosopher **)malloc(sizeof(t_philosopher *) * n);
	philos[0] = ft_create_philo(i);
	while (i <= n)
	{
		philos[i] = ft_create_philo((i + 1));
		i++;
	}
	return (philos);
}

t_table	*ft_init_table()
{
	t_table			*table;
	struct timeval	start;

	table = (t_table *)malloc(sizeof(t_table));
	table->n_philosophers = 0;
	table->philosophers = NULL;
	table->forks = NULL;
	table->started = gettimeofday(&start, NULL);
	return (table);
}

void	ft_init_forks(t_table *table)
{
	int	i;

	i = 0;
	table->forks = malloc(sizeof(pthread_mutex_t) * table->n_philosophers);
	if (!table->forks)
	{	
		ft_free_mutex(table);
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
