/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:23:29 by yukravch          #+#    #+#             */
/*   Updated: 2025/05/01 11:13:06 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	ft_init(t_philo **philo, int ac, char **av)
{
	*philo = (t_philo *)malloc(sizeof(t_philo));
	if (!*philo)
	{
		write(2, "Malloc failed in init\n", 22);
		return ;
	}
	(*philo)->nb_of_philo = ft_atoi(av[1]);
	(*philo)->time_to_die = ft_atoi(av[2]);
	(*philo)->time_to_eat = ft_atoi(av[3]);
	(*philo)->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		(*philo)->nb_of_times_philo_must_eat = ft_atoi(av[5]);
	
	free(*philo);
}

int	main(int ac, char** av)
{
	t_philo	*philo;

	if (ac != 5 && ac != 6)
	{
		write(2, "Write the correct arguments, please\n", 36);
		return (-1);
	}
	ft_init(&philo, ac, av);

}
