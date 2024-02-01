/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:59:47 by arigonza          #+#    #+#             */
/*   Updated: 2024/02/01 14:55:13 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	if (ft_check_argv(argc, argv))
	{
		t_table	*table;

		table = ft_init_table();
		ft_parse(argv, table);
		if (argc == 6)
			table->n_times_to_eat = atoi(argv[5]);
		printf("%lld\n", get_current_time(table));
		printf("times to eat: %d\n", table->n_times_to_eat);
		printf("philosopher with id->%d times_eaten: %d\n", table->philosophers[1]->id,
		 table->philosophers[1]->times_eaten);
	}

	return (0);
}
