/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:59:47 by arigonza          #+#    #+#             */
/*   Updated: 2024/03/18 17:07:57 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	if (ft_check_argv(argc, argv))
	{
		t_table	*table;

		table = ft_init_table(argv);
		if (argc == 6)
			table->n_times_to_eat = atoi(argv[5]);
		ft_print_msg(table, table->philosophers[3], EATING);
		//ft_create_threads(table->philosophers, table);
	}
	return (0);
}
