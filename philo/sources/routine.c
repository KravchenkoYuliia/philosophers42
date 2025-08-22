/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:29:31 by yukravch          #+#    #+#             */
/*   Updated: 2025/08/22 12:37:05 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_one_philo(t_philo *philo, t_general *main)
{
	if (ft_protected_write(philo, FORK) == ERROR || ft_protected_write(philo, DIE) == ERROR)
	{
		//stop flag
		//free all
		return (ERROR);
	}
	(void)main;
	//free all
	return (SUCCESS);
}

void	*ft_routine(void *data)
{
	t_philo		*philo;

	philo = (t_philo *)data;
	philo->last_meal_time = philo->main->start_of_simulation;
	if(philo->main->nb_of_philo == 1)
	{
		if (ft_one_philo(philo, philo->main) == ERROR)
			return (NULL);
		return (NULL);
	}
	return (NULL);
}
