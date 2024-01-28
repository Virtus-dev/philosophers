/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:25:18 by arigonza          #+#    #+#             */
/*   Updated: 2024/01/28 18:06:59 by arigonza         ###   ########.fr       */
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
	long	t_die;
	long	t_eat;
	long	t_sleep;
	
	n_philos = atoi(argv[1]);
	t_die = (long)atoi(argv[2]);
	t_eat = (long)atoi(argv[3]);
	t_sleep = (long)atoi(argv[4]);
	table->n_philosophers = n_philos;
	table->philosophers = ft_init_philos(n_philos, t_die, t_eat, t_sleep);
	table->forks = ft_init_forks(n_philos);
}