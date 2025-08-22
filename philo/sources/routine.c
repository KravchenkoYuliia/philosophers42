/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:29:31 by yukravch          #+#    #+#             */
/*   Updated: 2025/08/22 14:31:38 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_one_philo(t_philo *philo)
{
	if (ft_protected_write(philo, FORK) == ERROR || ft_protected_write(philo, DIE) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

void	ft_many_philos(t_philo *philo)
{
	//eating
	if (philo->main->must_to_eat != NOT_SPECIFIED &&
		philo->has_eaten_times >= philo->main->must_to_eat)
		return ;
}
void	*ft_routine(void *data)
{
	t_philo		*philo;

	philo = (t_philo *)data;
	philo->has_eaten_times = 0;
	if (ft_check_stop_flag(philo->main) != SUCCESS)
		return (NULL);
	philo->last_meal_time = philo->main->start_of_simulation;
	if (philo->main->nb_of_philo == 1)
	{
		ft_one_philo(philo);
		return (NULL);
	}
	ft_many_philos(philo);
	return (NULL);
}



	/*else if (philo->main->nb_of_philo % 2 == 0)
		ft_even_nb_of_philo(philo);
	else if (philo->main->nb_of_philo % 2 != 0)
		ft_odd_nb_of_philo(philo);*/
