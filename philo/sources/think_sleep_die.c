/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_sleep_die.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:01:15 by yukravch          #+#    #+#             */
/*   Updated: 2025/08/23 16:38:27 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_think(t_philo *philo)
{
	if (ft_protected_write(philo, THINK) == ERROR)
		return (ERROR);
	if (philo->index % 2 == 0)
	{
		if (usleep(1000) != SUCCESS)
			return (ERROR);
	}
	return (SUCCESS);
}

int	ft_sleep(t_philo *philo)
{
	int		i;
	long long	part;

	i = 0;
	part = (philo->main->time_to_sleep * 1000) / 4;
	if (ft_check_stop_flag(philo->main) != SUCCESS)
		return (ERROR);
	if (ft_protected_write(philo, SLEEP) == ERROR)
		return (ERROR);
	while (i < 4)
	{
		if (ft_check_stop_flag(philo->main) != SUCCESS)
			return (ERROR);
		if (usleep(part) != SUCCESS)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

bool	ft_die(t_philo *philo, long long current_time)
{
	 if ((current_time - philo->last_meal_time)
                        >= philo->main->time_to_die)
	{
		if (ft_protected_write(philo, DIE) == ERROR)
			return (ERROR);
		ft_stop_flag_is_true(philo);
		return (true);
	}
	return (false);
}
