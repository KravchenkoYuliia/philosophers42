/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:34:45 by yukravch          #+#    #+#             */
/*   Updated: 2025/08/24 19:11:41 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_get_current_time()
{
	struct timeval time;

	if (gettimeofday(&time, NULL) != SUCCESS)
		return (ERROR);
	return ((long long)time.tv_sec * 1000 + time.tv_usec / 1000);
}


long long	ft_count_time_from_the_start(t_general *main)
{
	long long	current_time;
	long long	result;
	struct timeval	time;

	if (gettimeofday(&time, NULL) != SUCCESS)
		return (ERROR);
	current_time = (long long)time.tv_sec * 1000 + time.tv_usec / 1000;
	result = current_time - main->start_of_simulation;
	return (result);
}
