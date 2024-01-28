/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:01:40 by arigonza          #+#    #+#             */
/*   Updated: 2024/01/28 18:35:36 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_error(char *error)
{
	printf("%sError : %s%s\n", FRED, error, DEF_COLOR);
	return (-1);
}
long	get_current_time(struct timeval *start, struct timeval *end)
{
	return ((end->tv_usec - start->tv_usec ) + 1e-6 * (end->tv_usec - start->tv_usec));
}