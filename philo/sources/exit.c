/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:03:06 by yukravch          #+#    #+#             */
/*   Updated: 2025/05/06 14:57:44 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	ft_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
}

void    ft_free_array(t_philos** philos, int nb_of_philos)
{

        int     i = 0;
        while (i < nb_of_philos && philos[i])
        {
                free(philos[i]);
                i++;
        }
        free(philos);
}
