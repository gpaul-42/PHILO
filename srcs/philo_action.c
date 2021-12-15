/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:33:32 by gpaul             #+#    #+#             */
/*   Updated: 2021/12/13 17:48:36 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	philo_sleep(t_philo *philo)
{
	if (lock_unlock_exit(philo->tab) == 0)
	{
		ft_print(philo, 2);
		usleep(philo->tab->time_to_sleep * 1000);
		return (0);
	}
	return (1);
}

int	philo_think(t_philo *philo)
{
	if (lock_unlock_exit(philo->tab) == 0)
	{
		ft_print(philo, 3);
		return (0);
	}
	return (1);
}

int	philo_take_forks(t_philo *philo)
{
	if (lock_unlock_exit(philo->tab) == 0)
	{
		if (philo->id == philo->tab->nbr_philo)
			pthread_mutex_lock(&philo->tab->forks[0]);
		else
			pthread_mutex_lock(&philo->tab->forks[philo->id]);
		ft_print(philo, 0);
		pthread_mutex_lock(philo->fork_l);
		ft_print(philo, 0);
		philo->h_fork = 1;
		return (0);
	}
	return (1);
}

int	philo_eat(t_philo *philo)
{
	struct timeval	time;

	if (lock_unlock_exit(philo->tab) == 0)
	{
		gettimeofday(&time, NULL);
		pthread_mutex_lock(&philo->lock_l_eat);
		philo->last_eat = ((time.tv_sec * 1000) + (time.tv_usec / 1000));
		pthread_mutex_unlock(&philo->lock_l_eat);
		ft_print(philo, 1);
		usleep(philo->tab->time_to_eat * 1000);
		philo->nbr_eat++;
		return (0);
	}
	return (1);
}

int	philo_drop_forks(t_philo *philo)
{
	if (philo->id == philo->tab->nbr_philo)
		pthread_mutex_unlock(&philo->tab->forks[0]);
	else
		pthread_mutex_unlock(&philo->tab->forks[philo->id]);
	pthread_mutex_unlock(philo->fork_l);
	philo->h_fork = 0;
	return (0);
}
