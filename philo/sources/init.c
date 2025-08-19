/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 19:25:06 by yukravch          #+#    #+#             */
/*   Updated: 2025/08/19 19:40:05 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init(char **av)
{
	t_general	*main;

	main = calloc(sizeof(t_general), 1);
	if (!main)
		return (ERROR);
	main->nb_of_philo = ft_atoi(av[1]);
	main->time_to_die = ft_atoi_unsigned_longlong(av[2]);
	main->time_to_eat = ft_atoi_unsigned_longlong(av[3]);
	main->time_to_sleep = ft_atoi_unsigned_longlong(av[4]);
	if (av[5])
		main->must_to_eat = ft_atoi(av[5]);
	return (SUCCESS);
}
