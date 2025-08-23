/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_sleep_die.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:01:15 by yukravch          #+#    #+#             */
/*   Updated: 2025/08/23 12:59:46 by yukravch         ###   ########.fr       */
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
	if (ft_protected_write(philo, SLEEP) == ERROR)
		return (ERROR);
	if (usleep(philo->main->time_to_sleep * 1000) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}
