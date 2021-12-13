/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:33:32 by gpaul             #+#    #+#             */
/*   Updated: 2021/12/10 18:44:11 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_sleep(t_philo *philo)
{
	ft_print(philo, 2);
	usleep(philo->tab->time_to_sleep * 1000);
}

void	philo_think(t_philo *philo)
{
	ft_print(philo, 3);
}

void	philo_take_forks(t_philo *philo)
{
	if (philo->id == philo->tab->nbr_philo)
		pthread_mutex_lock(&philo->tab->forks[0]);
	else
		pthread_mutex_lock(&philo->tab->forks[philo->id]);
	ft_print(philo, 0);
	pthread_mutex_lock(philo->fork_l);
	ft_print(philo, 0);
}

void	philo_eat(t_philo *philo)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	philo->last_eat = ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	ft_print(philo, 1);
	usleep(philo->tab->time_to_eat * 1000);
	if (philo->id == philo->tab->nbr_philo)
		pthread_mutex_unlock(&philo->tab->forks[0]);
	else
		pthread_mutex_unlock(&philo->tab->forks[philo->id]);
	pthread_mutex_unlock(philo->fork_l);
	philo->nbr_eat++;
}
