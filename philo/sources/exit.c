/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:03:06 by yukravch          #+#    #+#             */
/*   Updated: 2025/05/06 16:37:17 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	ft_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
}

void    ft_free_array(t_philos** philos, size_t nb_of_philos)
{

        size_t    i = 0;
        while (i < nb_of_philos && philos[i])
        {
                free(philos[i]);
                i++;
        }
        free(philos);
}

void	ft_stop_created_threads(t_philos **philos, size_t ind_of_failed_philo)
{
	size_t	i;

	i = 0;
	while (i < ind_of_failed_philo)
	{
		pthread_join((*philos)[i].thread_id, NULL);
		i++;
	}

}
