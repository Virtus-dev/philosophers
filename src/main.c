/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:59:47 by arigonza          #+#    #+#             */
/*   Updated: 2024/03/11 15:04:10 by arigonza         ###   ########.fr       */
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
		ft_print_msg(table, table->philosophers[1], 2);
	
	return (0);
}
