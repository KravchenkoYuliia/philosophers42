/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:35:39 by yukravch          #+#    #+#             */
/*   Updated: 2025/08/24 15:07:01 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_stop_flag(t_general *main)
{
	if (pthread_mutex_lock(&main->stop_mutex) != SUCCESS)
		return (ERROR);
	if (main->stop == true)
	{
		if (pthread_mutex_unlock(&main->stop_mutex) != SUCCESS)
			return (ERROR);
		return (STOP);
	}
	if (pthread_mutex_unlock(&main->stop_mutex) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}

void	ft_stop_flag_is_true(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->main->stop_mutex) != SUCCESS)
		return ;
	philo->main->stop = true;
	pthread_mutex_unlock(&philo->main->stop_mutex);
}

long long	ft_min(long long a, long long b)
{
	if (a <= b)
		return (a);
	else if (b < a)
		return (b);
	return (ERROR);
}
