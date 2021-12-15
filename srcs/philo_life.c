/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:10:02 by gpaul             #+#    #+#             */
/*   Updated: 2021/12/14 15:41:21 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philo_life0(void *arg)
{
	t_philo	*philo;
	int		exit;

	exit = 0;
	philo = arg;
	while (exit == 0)
	{
		exit = lock_unlock_exit(philo->tab);
		philo_take_forks(philo);
		if (philo_eat(philo) == 0 && philo->tab->nbr_arg == 1
			&& philo->nbr_eat == philo->tab->nbr_time_to_eat)
		{
			pthread_mutex_lock(&philo->tab->lock_eaten);
			philo->tab->eaten++;
			pthread_mutex_unlock(&philo->tab->lock_eaten);
		}
		if (philo->h_fork == 1)
			philo_drop_forks(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (0);
}

void	*philo_life1(void *arg)
{
	t_philo	*philo;
	int		exit;

	exit = 0;
	philo = arg;
	while (exit == 0)
	{
		exit = lock_unlock_exit(philo->tab);
		philo_sleep(philo);
		philo_think(philo);
		philo_take_forks(philo);
		if (philo_eat(philo) == 0 && philo->tab->nbr_arg == 1
			&& philo->nbr_eat == philo->tab->nbr_time_to_eat)
		{
			pthread_mutex_lock(&philo->tab->lock_eaten);
			philo->tab->eaten++;
			pthread_mutex_unlock(&philo->tab->lock_eaten);
		}
		if (philo->h_fork == 1)
			philo_drop_forks(philo);
	}
	return (0);
}
