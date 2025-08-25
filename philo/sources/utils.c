/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:35:39 by yukravch          #+#    #+#             */
/*   Updated: 2025/08/25 18:55:43 by yukravch         ###   ########.fr       */
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

int	ft_stop_flag_is_true(t_general *main)
{
	if (pthread_mutex_lock(&main->stop_mutex) != SUCCESS)
		return (ERROR);
	main->stop = true;
	if (pthread_mutex_unlock(&main->stop_mutex) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}

long long	ft_min(long long a, long long b)
{
	if (a <= b)
		return (a);
	else if (b < a)
		return (b);
	return (ERROR);
}

int	ft_monitor_checking(t_general *main, long long current_time, int i)
{
	if (pthread_mutex_lock(&main->food_status_mutex) != SUCCESS)
		return (ERROR);
	if ((current_time - main->philo[i].last_meal_time)
			>= main->time_to_die)
	{
		if (pthread_mutex_unlock(&main->food_status_mutex) != SUCCESS)
			return (ERROR);
		if (ft_protected_write(&main->philo[i], DIE) == ERROR)
			return (ERROR);
		if (ft_stop_flag_is_true(main) == ERROR)
			return (ERROR);
		if (ft_protected_write(&main->philo[i], STOP) == ERROR)
			return (ERROR);
		return (SUCCESS);
	}
	if (main->must_to_eat != NOT_SPECIFIED
			&& ft_not_hungry(main, &main->philo[i]) == true)
	{
		if (pthread_mutex_unlock(&main->food_status_mutex) != SUCCESS)
			return (ERROR);
		if (ft_stop_flag_is_true(main) == ERROR)
			return (SUCCESS);
		if (ft_protected_write(&main->philo[i], STOP) == ERROR)
			return (ERROR);
		return (SUCCESS);
	}
	if (pthread_mutex_unlock(&main->food_status_mutex) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}
