/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:25:18 by arigonza          #+#    #+#             */
/*   Updated: 2024/01/27 16:59:30 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_check_argv(int   argc, char **argv)
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
				if (argv[i][j] >= '0' && argv[i][j] <= '9')
					j++;
				else
					return (ft_error(INVALID_INPUT), 0);
			}
			i++;
		}
		return (1);
    }
	else
		return (ft_error(INVALID_N_ARGV), 0);
}