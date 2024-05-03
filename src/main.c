/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:59:47 by arigonza          #+#    #+#             */
/*   Updated: 2024/05/03 23:59:11 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (ft_check_argv(argc, argv))
	{
		t_philosopher	*philos;

		ft_init_table(argc, argv, &table);
		philos = malloc(sizeof(t_philosopher) * table.n_philosophers);
		if (!philos)
			ft_error(MALLOC_ERR);
		ft_init_philosophers(table.philosophers, &table);
		if (argc == 6)
			table.n_times_to_eat = atoi(argv[5]);
		else
			table.n_times_to_eat = -1;
		ft_create_threads(table.philosophers, &table);
	}
	return (0);
}
