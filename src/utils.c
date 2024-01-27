/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:01:40 by arigonza          #+#    #+#             */
/*   Updated: 2024/01/27 18:13:48 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_error(char *error)
{
	printf("%sError : %s\n%s", FRED, error, DEF_COLOR);
	return (-1);
}

t_philosopher	*ft_create_philo(long t_to_die, long t_to_eat, long t_to_sleep)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)malloc(sizeof(t_philosopher));
	philo->time_to_die = t_to_die;
	philo->time_to_eat = t_to_eat;
	philo->time_to_sleep = t_to_sleep;
	philo->n_times_eaten = 0;
	philo->next = NULL;
}

void	ft_init_structs(int n_philos, long t_to_die, long t_to_eat, long t_to_sleep, int n_times_to_eat)
{
	int				i;
	t_philosopher *current;

	i = 0;
	current = ft_create_philo(t_to_die, t_to_eat, t_to_sleep);
	while (i < n_philos)
	{
		current->next = ft_create_philo(t_to_die, t_to_eat, t_to_sleep);
	}
	
}
