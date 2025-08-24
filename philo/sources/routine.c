/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:29:31 by yukravch          #+#    #+#             */
/*   Updated: 2025/08/24 17:13:13 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_personal_inf(t_philo *philo)
{
	philo->has_eaten_times = 0;
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

void	ft_philos_loop(t_philo *philo)
{
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
	ft_init_personal_inf(philo);
	if (ft_check_stop_flag(philo->main) != SUCCESS)
		return (NULL);
	ft_philos_loop(philo);
	return (NULL);
}
