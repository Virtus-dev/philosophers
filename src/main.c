/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:59:47 by arigonza          #+#    #+#             */
/*   Updated: 2024/05/14 12:07:31 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_leaks()
{
	system("leaks -q philo");
}

int	main(int argc, char **argv)
{
	t_table	*table;
	
	table = malloc (sizeof(t_table));
	//atexit(ft_leaks);
	if (ft_check_argv(argc, argv))
	{
		ft_check_argv(argc, argv);
		ft_init_table(argc, argv, table);
		ft_init_philosophers(table->philosophers, table);
		//print_philos(&table);
		ft_create_threads(table->philosophers, table);
	}
	return (0);
}
