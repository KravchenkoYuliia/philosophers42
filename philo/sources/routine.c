/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:29:31 by yukravch          #+#    #+#             */
/*   Updated: 2025/08/24 21:06:32 by yukravch         ###   ########.fr       */
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
		if (ft_protected_write(philo, THINK) == ERROR)
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
	while (ft_check_start_flag(philo->main) != START)
	{
		usleep(100);
		continue ;
	}
	if (ft_check_stop_flag(philo->main) != SUCCESS)
		return (NULL);
	ft_init_personal_inf(philo);
	if (ft_check_stop_flag(philo->main) != SUCCESS)
		return (NULL);
	if (ft_think(philo) == ERROR)
		return (NULL);
	ft_philos_loop(philo);
	return (NULL);
}
