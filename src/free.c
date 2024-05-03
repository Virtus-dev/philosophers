/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:05:44 by arigonza          #+#    #+#             */
/*   Updated: 2024/05/03 20:41:46 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_free_mutex(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philosophers)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	free(table->forks);
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
		i++;
	}
}

void	ft_free_all(t_table *table)
{
	int	i;

	printf("HACIENDO FREE\n");
	i = 0;
	while (i < table->n_philosophers)
	{
		printf("QUE HILO ES: %d %d\n", i, table->philosophers[i].id);
		pthread_join(table->philosophers[i].thread, NULL);
		printf("EN EL BUCLE DEL FREE");
		pthread_mutex_destroy(table->philosophers[i].eating_mutex);
		free(table->philosophers[i].eating_mutex);
		i++;
	}
	printf("en medio DEL FREE");
	//ft_free_philos(table->philosophers);
	ft_free_mutex(table);
	pthread_mutex_destroy(table->mutex_table);
	free(table->mutex_table);
	free(table->philosophers);
	pthread_mutex_destroy(table->print_mutex);
	free(table->print_mutex);
	free(table);
	printf("SALIENDO DEL FREE");
}
