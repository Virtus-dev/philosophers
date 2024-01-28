/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:36:54 by arigonza          #+#    #+#             */
/*   Updated: 2024/01/28 18:30:27 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

t_philosopher	*ft_create_philo(long t_die, long t_eat, long t_sleep, int id)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)malloc(sizeof(t_philosopher));
	philo->time_to_die = t_die;
	philo->time_to_eat = t_eat;
	philo->time_to_sleep = t_sleep;
	philo->n_times_eaten = 0;
	philo->id = id;
	philo->next = NULL;
	philo->prev = NULL;
	return (philo);
}

t_philosopher	*ft_init_philos(int n, long die, long eat, long sleep)
{
	int				i;
	t_philosopher	*head;
	t_philosopher	*prev;
	t_philosopher	*current;

	i = 1;
	head = ft_create_philo(die, eat, sleep, i);
	current = head;
	while (i <= n)
	{
		if (current->next)
			current->prev = prev;
		prev = current;
		current->next = ft_create_philo(die, eat, sleep, (i + 1));
		current = current->next;
		i++;
	}
	return (head);
}

t_table	*ft_init_table()
{
	t_table	*table;

	table = (t_table *)malloc(sizeof(t_table));
	table->n_philosophers = 0;
	table->philosophers = NULL;
	table->forks = NULL;
	return (table);
}

t_fork	*ft_create_fork(void)
{
	pthread_mutex_t	lock;
	t_fork			*fork;

	fork = (t_fork *)malloc(sizeof(fork));
	pthread_mutex_init(&lock, NULL);
	fork->lock = lock;
	fork->next = NULL;
	return (fork);
}

t_fork	*ft_init_forks(int n)
{
	int		i;
	t_fork	*current;
	t_fork	*head;

	i = 0;
	head = ft_create_fork();
	current = head;
	while (i < n)
	{
		current->next = ft_create_fork();
		current = current->next;
		i++;
	}
	return (head);
}
