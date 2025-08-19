/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:25:37 by yukravch          #+#    #+#             */
/*   Updated: 2025/08/19 19:15:38 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>

#define	SIGNED_LONG_LONG 9223372036854775807

typedef enum e_index {
	SUCCESS,
	ERROR,
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE
}	t_index;

/////////////libft

int			ft_strlen(char *str);
int			ft_atoi(const char *nptr);
unsigned long long	ft_atoi_unsigned_longlong(char *str);
//////////////

int	ft_isdigit(int ac, char **av);
int	ft_limits(int ac, char **av);

///////////////errors

void	ft_error(char *msg);

# endif
