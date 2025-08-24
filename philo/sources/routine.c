/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:29:31 by yukravch          #+#    #+#             */
/*   Updated: 2025/08/24 16:08:54 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_personal_inf(t_philo *philo)
{
	philo->has_eaten_times = 0;
	//philo->last_meal_time = philo->main->start_of_simulation;
	if (philo->index == 0)
	{
		philo->right_fork = philo->main->nb_of_philo - 1;
		philo->left_fork = 0;
	}
	else
	{
		philo->right_fork = philo->index - 1;
		philo->left_fork = philo->index;
	}
}

void	ft_many_philos(t_philo *philo)
{
	if (ft_check_stop_flag(philo->main) != SUCCESS)
		return ;
	ft_init_personal_inf(philo);
	while (1)
	{
		if (ft_check_stop_flag(philo->main) != SUCCESS)
			return ;
		if (ft_think(philo) == ERROR)
			return ;
		if (ft_check_stop_flag(philo->main) != SUCCESS)
			return ;
		if (ft_eat(philo) == ERROR)
			return ;
		if (ft_check_stop_flag(philo->main) != SUCCESS)
			return ;
		if (ft_sleep(philo) == ERROR)
			return ;
		if (ft_check_stop_flag(philo->main) != SUCCESS)
			return ;
	}
}
void	*ft_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (ft_check_stop_flag(philo->main) != SUCCESS)
		return (NULL);
	/*if (philo->main->nb_of_philo == 1)
	{
		if (ft_protected_write(philo, FORK) == ERROR)
			return (NULL);
		ft_protected_write(philo, DIE);
	}
	else*/
	ft_many_philos(philo);
	return (NULL);
}



	/*else if (philo->main->nb_of_philo % 2 == 0)
		ft_even_nb_of_philo(philo);
	else if (philo->main->nb_of_philo % 2 != 0)
		ft_odd_nb_of_philo(philo);*/
