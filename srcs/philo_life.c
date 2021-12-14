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
	int		status;

	status = 0;
	philo = arg;
	while (status == 0)
	{
		status = philo_take_forks(philo, status);
		if (philo_eat(philo, status) == 0 && philo->tab->nbr_arg == 1
			&& philo->nbr_eat == philo->tab->nbr_time_to_eat)
			philo->tab->eaten++;
		philo_drop_forks(philo);
		status = philo_sleep(philo, status);
		status = philo_think(philo, status);
	}
	return (0);
}

void	*philo_life1(void *arg)
{
	t_philo	*philo;
	int		status;

	status = 0;
	philo = arg;
	while (philo->tab->exit == 0)
	{
		philo_sleep(philo, status);
		philo_think(philo, status);
		philo_take_forks(philo, status);
		if (philo_eat(philo, status) == 0 && philo->tab->nbr_arg == 1
			&& philo->nbr_eat == philo->tab->nbr_time_to_eat)
			philo->tab->eaten++;
		philo_drop_forks(philo);
	}
	return (0);
}
