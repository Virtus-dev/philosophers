/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:25:18 by arigonza          #+#    #+#             */
/*   Updated: 2024/03/14 16:39:27 by arigonza         ###   ########.fr       */
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
					return (ft_error(INVALID_INPUT), printf("%s%s%s", FRED, PARSING_EXPL, DEF_COLOR), 0);
				j++;
			}
			i++;
		}
		return (1);
	}
	else
		return (ft_error(INVALID_N_ARGV), 0);
}
