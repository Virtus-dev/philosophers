/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:59:47 by arigonza          #+#    #+#             */
/*   Updated: 2024/01/28 18:29:05 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	struct timeval start;
	struct timeval end;
	
	gettimeofday(&start, NULL);
	if (ft_check_argv(argc, argv))
	{
		t_table	*table;

		table = ft_init_table();
		ft_parse(argv, table);
	}
	gettimeofday(&end, NULL);
	printf("%ld", get_current_time(&start, &end));
	return (0);
}
