/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:29:31 by yukravch          #+#    #+#             */
/*   Updated: 2025/08/22 11:31:34 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *data)
{
	t_philo		*philo;
	long long	now;

	philo = (t_philo *)data;
	philo->last_meal_time = philo->main->start_of_simulation;

	//just testing time counting
	now = ft_count_time_from_the_start(philo->main);
	if (now == ERROR)
	{
		//stop flag
		return (NULL);
	}
	pthread_mutex_lock(&philo->main->write_mutex);
	printf("%d philo's start time %lld and now to print = %lld\n", philo->index, philo->last_meal_time, now);
	pthread_mutex_unlock(&philo->main->write_mutex); 
	return (NULL);
}
