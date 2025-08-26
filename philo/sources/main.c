/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:37:59 by yukravch          #+#    #+#             */
/*   Updated: 2025/08/26 18:48:34 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo(char **av)
{
	t_general	*main;

	if (ft_init(av, &main) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		ft_error("Write the correct number of arguments, please");
		return (ERROR);
	}
	else if (ft_isdigit(ac, av) == ERROR)
	{
		ft_error("Only positive numbers are accepted as arguments");
		return (ERROR);
	}
	else if (ft_limits(av) == ERROR)
		return (ERROR);
	else if (ft_philo(av) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
