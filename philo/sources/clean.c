/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:36:38 by yukravch          #+#    #+#             */
/*   Updated: 2025/08/26 14:16:18 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_destroy_all_mutex(t_general *main)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&main->write_mutex);
	pthread_mutex_destroy(&main->food_status_mutex);
	pthread_mutex_destroy(&main->start_mutex);
	pthread_mutex_destroy(&main->stop_mutex);
	/*while (i < main->nb_of_philo)
	{
		pthread_mutex_destroy(&main->forks_mutex[i]);
		i++;
	}*/
	free(main->forks_mutex);
}
