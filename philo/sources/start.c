/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 20:12:31 by yukravch          #+#    #+#             */
/*   Updated: 2025/08/26 19:04:07 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_start_mutex(t_general *main)
{
	if (pthread_mutex_init(&main->start_mutex, NULL) != SUCCESS)
	{
		free(main->philo);
		free(main);
		return (ERROR);
	}
	return (SUCCESS);
}

int	ft_check_start_flag(t_general *main)
{
	if (pthread_mutex_lock(&main->start_mutex) != SUCCESS)
		return (ERROR);
	if (main->start == true)
	{
		if (pthread_mutex_unlock(&main->start_mutex) != SUCCESS)
			return (ERROR);
		return (START);
	}
	if (pthread_mutex_unlock(&main->start_mutex) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}

int	ft_start_flag_is_true(t_general *main)
{
	if (pthread_mutex_lock(&main->start_mutex) != SUCCESS)
		return (ERROR);
	main->start = true;
	if (pthread_mutex_unlock(&main->start_mutex) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}
