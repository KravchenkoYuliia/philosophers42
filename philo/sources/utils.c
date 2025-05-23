/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:34:08 by yukravch          #+#    #+#             */
/*   Updated: 2025/05/18 14:26:25 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_printf_mtx(t_index msg_index, t_dinner *dinner, size_t index)
{
	const char* messages[5] = {
		"has taken a fork", "is eating", "is sleeping", "is thinking", "died"
	};

	size_t  time_to_print;
	struct timeval end_time;
	gettimeofday(&end_time, NULL);

	time_to_print = ft_get_time_to_print(dinner->start_time.tv_usec, end_time.tv_usec);

	pthread_mutex_lock(&dinner->mtx_printf);
	if (msg_index == EAT) {
		printf("%zu %zu %s\n", time_to_print, index, messages[FORK]);
		printf("%zu %zu %s\n", time_to_print, index, messages[FORK]);
	}
	printf("%zu %zu %s\n", time_to_print, index, messages[msg_index]);
	pthread_mutex_unlock(&dinner->mtx_printf);
}

size_t	ft_atoi(char *str)
{
	size_t		result;

	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (SUCCESS);
	while (str[i])
		i++;
	return (i);
}

int	ft_isdigit(int ac, char **av)
{
	int	arg;
	int	i;

	arg = 1;
	while (av[arg] && arg < ac)
	{
		i = 0;
		while (av[arg][i])
		{
			if(!(av[arg][i] >= '0' && av[arg][i] <= '9'))
			{
				return (ERROR);
			}
			i++;
		}
		arg++;
	}
	return (SUCCESS);
}

unsigned long long	ft_atoi_long(char *str)
{
	unsigned long long	result;

	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result);
}

int	ft_MAX(int ac, char **av)
{
	int	arg;
	size_t	max_size_t;

	if (ft_atoi(av[1]) > 200)
	{
		ft_error("Number of philosophers can't exceed 200");
		return (ERROR);
	}
	if (ft_atoi(av[1]) == 0)
	{
		printf("Add at least one philosopher\n");
		return (ERROR);
	}
	arg = 2;
	max_size_t = 4294967295;
	while (av[arg] && arg < ac)
	{
		if (ft_atoi_long(av[arg]) > max_size_t)
		{
			ft_error("Don't exceed the size_t max in arguments");
			return (ERROR);
		}
		arg++;
	}
	return (SUCCESS);
}

size_t	ft_get_time_to_print(suseconds_t start, suseconds_t end)
{
	size_t	result;

	result = end - start;
	return (result);
}
