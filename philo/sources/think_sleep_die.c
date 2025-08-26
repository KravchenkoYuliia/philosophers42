/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_sleep_die.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:01:15 by yukravch          #+#    #+#             */
/*   Updated: 2025/08/26 16:58:18 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_think(t_philo *philo)
{
	if (ft_check_stop_flag(philo->main) != SUCCESS)
		return (ERROR);
	if (ft_protected_write(philo, THINK) == ERROR)
		return (ERROR);
	if (philo->main->nb_of_philo % 2 == 1)
	{
		if (ft_check_stop_flag(philo->main) != SUCCESS)
			return (ERROR);
		
		t_time	think;
		think.current_time = ft_get_current_time();
		think.deadline = think.current_time + ((philo->main->time_to_eat * 2) - philo->main->time_to_sleep);
		think.time_left = SIGNED_LONG_LONG;
		while (think.time_left > 0)
		{
			think.current_time = ft_get_current_time();
			if (think.current_time == ERROR)
				return (ERROR);
			think.time_left = think.deadline - think.current_time;
			if (think.time_left <= 0)
				break ;
			if (ft_check_stop_flag(philo->main) != SUCCESS)
				return (ERROR);
			if (usleep(ft_min(think.time_left * 1000, 500)) != SUCCESS)
				return (ERROR);
		}
	}
	return (SUCCESS);
}

int	ft_sleep(t_philo *philo)
{
	t_time	sleep;

	if (ft_check_stop_flag(philo->main) != SUCCESS)
		return (ERROR);
	sleep.current_time = ft_get_current_time();
	if (sleep.current_time == ERROR)
		return (ERROR);
	sleep.deadline = sleep.current_time + philo->main->time_to_sleep;
	sleep.time_left = SIGNED_LONG_LONG;
	if (ft_protected_write(philo, SLEEP) == ERROR)
		return (ERROR);
	while (sleep.time_left > 0)
	{
		sleep.current_time = ft_get_current_time();
		if (sleep.current_time == ERROR)
			return (ERROR);
		sleep.time_left = sleep.deadline - sleep.current_time;
		if (sleep.time_left <= 0)
			break ;
		if (ft_check_stop_flag(philo->main) != SUCCESS)
			return (ERROR);
		if (usleep(ft_min(sleep.time_left * 1000, 500)) != SUCCESS)
			return (ERROR);
	}
	return (SUCCESS);
}
