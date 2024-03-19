/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:02:25 by arigonza          #+#    #+#             */
/*   Updated: 2024/03/19 20:52:23 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_error(char *error)
{
	printf("%sError : %s%s\n", FRED, error, DEF_COLOR);
    return ;
}

void    ft_print_msg(t_table *table, t_philosopher philo, int state)
{
    static int i;

    pthread_mutex_lock(table->print_mutex);
    if (state == TAKING_FORKS && i != 1)
    {
        printf("%s[%lld] %d Has taken a fork%s\n",
         FBLUE, get_current_time(table), philo.id, DEF_COLOR);
    }
    if (state == EATING && i != 1)
    {
        printf("%s[%lld] %d is eating%s\n",
         FGREEN, get_current_time(table), philo.id, DEF_COLOR);
    }
    if (state == SLEEPING && i != 1)
    {
        printf("%s[%lld] %d is sleeping%s\n",
         FPURPLE, get_current_time(table), philo.id, DEF_COLOR);
    }
    if (state == THINKING && i != 1)
    {
        printf("%s[%lld] %d is thinking%s\n",
         FYELLOW, get_current_time(table), philo.id, DEF_COLOR);
    }
    if (state == DIED && i != 1)
    {
        i = 1;
        printf("%s[%lld] %d died%s\n", FRED, get_current_time(table), philo.id, DEF_COLOR);
    }
   pthread_mutex_unlock(table->print_mutex);
}