/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:59:47 by arigonza          #+#    #+#             */
/*   Updated: 2024/05/03 18:08:03 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	if (ft_check_argv(argc, argv))
	{
		table = ft_init_table(argv);
		if (argc == 6)
			table->n_times_to_eat = atoi(argv[5]);
		else
			table->n_times_to_eat = -1;
		ft_create_threads(table->philosophers, table);
	}
	return (0);
}
