/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_sleep_die.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:01:15 by yukravch          #+#    #+#             */
/*   Updated: 2025/08/25 15:09:43 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_think(t_philo *philo)
{
	if (ft_check_stop_flag(philo->main) != SUCCESS)
		return (ERROR);
	if (ft_protected_write(philo, THINK) == ERROR)
		return (ERROR);
	if (philo->index % 2 != 0)
	{
		if (ft_check_stop_flag(philo->main) != SUCCESS)
			return (ERROR);
		if (usleep(500) != SUCCESS)
			return (ERROR);
		if (ft_check_stop_flag(philo->main) != SUCCESS)
			return (ERROR);
		if (usleep(500) != SUCCESS)
			return (ERROR);
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

