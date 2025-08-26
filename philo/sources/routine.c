/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:29:31 by yukravch          #+#    #+#             */
/*   Updated: 2025/08/26 16:58:04 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_personal_inf(t_philo *philo)
{
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
	if (philo->index % 2 == 1)
        {
                if (usleep(philo->main->nb_of_philo * 30) != SUCCESS)
			return ;

        }
	while (1)
	{
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
		if (ft_think(philo) == ERROR)
			return ;
	}
}

void	*ft_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (ft_check_start_flag(philo->main) != START)
	{
		usleep(500);
		continue ;
	}
	if (ft_check_stop_flag(philo->main) != SUCCESS)
		return (NULL);
	ft_init_personal_inf(philo);
	if (ft_check_stop_flag(philo->main) != SUCCESS)
		return (NULL);
	ft_philos_loop(philo);

	// printf("PHILO %d\n", philo->index + 1);
	return (NULL);
}
