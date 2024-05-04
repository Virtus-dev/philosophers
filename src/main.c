/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:59:47 by arigonza          #+#    #+#             */
/*   Updated: 2024/05/04 11:43:28 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (ft_check_argv(argc, argv))
	{
		ft_check_argv(argc, argv);
		ft_init_table(argc, argv, &table);
		ft_init_philosophers(table.philosophers, &table);
		//print_philos(&table);
		ft_create_threads(table.philosophers, &table);
	}
	return (0);
}
