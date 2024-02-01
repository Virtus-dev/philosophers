/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:01:40 by arigonza          #+#    #+#             */
/*   Updated: 2024/02/01 13:26:20 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_error(char *error)
{
	printf("%sError : %s%s\n", FRED, error, DEF_COLOR);
}

long long	get_sys_time(void)
{
	struct timeval	tv;
	
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

long long	get_current_time(t_table *table)
{
	return (get_sys_time() - table->started);
}

void	ft_free_mutex(t_table  *table)
{
	int	i;
	
	i = 0;
	while (i < table->n_philosophers)
		pthread_mutex_destroy(&table->forks[i++]);
}