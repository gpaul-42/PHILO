/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:33:32 by gpaul             #+#    #+#             */
/*   Updated: 2021/12/19 18:27:43 by gpaul            ###   ########.fr       */
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
