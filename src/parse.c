/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:25:18 by arigonza          #+#    #+#             */
/*   Updated: 2024/02/01 14:46:01 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_check_argv(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc == 6 || argc == 5)
	{
		while (argv[i])
		{
			j = 0;
			while (argv[i][j])
			{
				if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
					return (ft_error(INVALID_INPUT), 0);
				j++;
			}
			i++;
		}
		return (1);
	}
	else
		return (ft_error(INVALID_N_ARGV), 0);
}

void	ft_parse(char **argv, t_table *table)
{
	int	n_philos;
	
	n_philos = atoi(argv[1]);
	table->time_to_die = (long)atoi(argv[2]);
	table->time_to_eat = (long)atoi(argv[3]);
	table->time_to_sleep = (long)atoi(argv[4]); 
	table->n_philosophers = n_philos;
	table->time_to_think = table->time_to_sleep;
	table->philosophers = ft_init_philos(n_philos);
	ft_init_forks(table);
}