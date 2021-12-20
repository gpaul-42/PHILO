/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:10:02 by gpaul             #+#    #+#             */
/*   Updated: 2021/12/19 23:53:13 by gpaul            ###   ########.fr       */
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
		philo_eat(philo);
		if (philo->h_fork == 1)
			philo_drop_forks(philo);
		if (philo->tab->nbr_arg == 1
			&& philo->tab->nbr_time_to_eat == philo->nbr_eat)
			break ;
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
		philo_eat(philo);
		if (philo->h_fork == 1)
			philo_drop_forks(philo);
		if (philo->tab->nbr_arg == 1
			&& philo->tab->nbr_time_to_eat == philo->nbr_eat)
			break ;
	}
	return (0);
}
