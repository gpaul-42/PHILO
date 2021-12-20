/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:33:32 by gpaul             #+#    #+#             */
/*   Updated: 2021/12/20 16:16:22 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	lock_unlock_eaten(t_info *tab)
{
	int	eaten;

	pthread_mutex_lock(&tab->lock_eaten);
	eaten = tab->eaten;
	pthread_mutex_unlock(&tab->lock_eaten);
	return (eaten);
}

void	add_eaten(t_info *tab)
{
	pthread_mutex_lock(&tab->lock_eaten);
	tab->eaten++;
	pthread_mutex_unlock(&tab->lock_eaten);
}

unsigned int	lock_unlock_last_eat(t_philo *philo)
{
	int	last;

	pthread_mutex_lock(&philo->lock_l_eat);
	last = philo->last_eat;
	pthread_mutex_unlock(&philo->lock_l_eat);
	return (last);
}

int	check_arg(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] >= 48 && argv[i] <= 57)
			i++;
		else
			return (1);
	}
	return (0);
}

void	init_var(t_info *tab)
{
	tab->nbr_philo = 0;
	tab->time_to_die = 0;
	tab->time_to_eat = 0;
	tab->time_to_sleep = 0;
	tab->nbr_time_to_eat = 0;
}
