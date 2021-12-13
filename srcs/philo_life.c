/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:10:02 by gpaul             #+#    #+#             */
/*   Updated: 2021/12/10 18:40:39 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philo_life0(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (philo->tab->exit == 0)
	{
		if (philo->tab->exit == 0)
		{
			philo_take_forks(philo);
			philo_eat(philo);
			if (philo->tab->nbr_arg == 1
				&& philo->nbr_eat == philo->tab->nbr_time_to_eat)
				philo->tab->eaten++;
		}
		if (philo->tab->exit == 0)
			philo_sleep(philo);
		if (philo->tab->exit == 0)
			philo_think(philo);
	}
	return (0);
}

void	*philo_life1(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (philo->tab->exit == 0)
	{
		if (philo->tab->exit == 0)
			philo_sleep(philo);
		if (philo->tab->exit == 0)
			philo_think(philo);
		if (philo->tab->exit == 0)
		{
			philo_take_forks(philo);
			philo_eat(philo);
			if (philo->tab->nbr_arg == 1
				&& philo->nbr_eat == philo->tab->nbr_time_to_eat)
				philo->tab->eaten++;
		}
	}
	return (0);
}
