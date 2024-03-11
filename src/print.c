/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:02:25 by arigonza          #+#    #+#             */
/*   Updated: 2024/03/01 21:03:04 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_error(char *error)
{
	printf("%sError : %s%s\n", FRED, error, DEF_COLOR);
}

void    ft_print_msg(t_table *table, t_philosopher *philo, int state)
{
    if (state == TAKING_FORKS)
    {
        printf("%s[%lld] %d Has taken a fork%s",
         FBLUE, get_current_time(table), philo->id, DEF_COLOR);
    }
    if (state == EATING)
    {
        printf("%s[%lld] %d is eating%s",
         FGREEN, get_current_time(table), philo->id, DEF_COLOR);
    }
    if (state == SLEEPING)
    {
        printf("%s[%lld] %d is sleeping%s",
         FPURPLE, get_current_time(table), philo->id, DEF_COLOR);
    }
    if (state == THINKING)
    {
        printf("%s[%lld] %d is thinking%s",
         FYELLOW, get_current_time(table), philo->id, DEF_COLOR);
    }
    if (state == DIED)
    {
        printf("%s%d died%s", FRED, philo->id, DEF_COLOR);
    }
}