/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:37:59 by yukravch          #+#    #+#             */
/*   Updated: 2025/08/19 17:40:56 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char** av)
{
	if (ac != 5 && ac != 6)
	{
		ft_error("Write the correct number of arguments, please");
		return (ERROR);
	}
	if (ft_isdigit(ac, av) == ERROR)
	{
		ft_error("Only positive numbers are accepted as arguments");
		return (ERROR);
	}
	if (ft_limits(ac, av) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
