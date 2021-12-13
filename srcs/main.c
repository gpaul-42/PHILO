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

void	exit_free_philo(t_info *tab)
{
	int i;

	i = 0;
	while (i < tab->nbr_philo)
	{
		pthread_mutex_destroy(tab->philo[i].fork_l);
		pthread_detach(tab->philo[i].philo);
		i++;
	}
	free(tab->philo);
	free(tab);
}

void	*philo_life(void *arg)
{
	t_philo *philo;

	philo = arg;
	while (philo->tab->exit == 0)
	{
		if (philo->tab->exit == 0)
			philo_take_forks(philo);
		if (philo->tab->exit == 0)
			philo_eat(philo);
		if (philo->tab->exit == 0)
			philo_sleep(philo);
		if (philo->tab->exit == 0)
			philo_think(philo);
	}
	return (0);
}

void	*checker(void *arg)
{
	t_info	*tab;
	int		i;
	int		exit;
	int		eaten;

	tab = arg;
	exit = 0;
	while (exit == 0 && eaten != tab->nbr_philo)
	{
		i = 0;
		eaten = 0;
		while (i < tab->nbr_philo && (exit == 0 && eaten != tab->nbr_philo))
		{
			gettimeofday(&tab->time, NULL);
			if ((time_to_ms(tab) - tab->philo[i].last_eat) > (unsigned int)tab->time_to_die)
				exit = i;
			else if (tab->nbr_arg == 1 && tab->philo[i].nbr_eat >= tab->nbr_time_to_eat)
				eaten++;
			i++;
		}
		usleep(250);
	}
	tab->exit = 1;
	if (exit >= 1)
		ft_print(&tab->philo[exit], 4);
	return (0);
}

void	create_philo(t_info *tab)
{
	int	i;

	i = 0;
	while (i < tab->nbr_philo)
	{
		gettimeofday(&tab->time, NULL);
		tab->philo[i].time_crea = time_to_ms(tab);
		tab->philo[i].last_eat = time_to_ms(tab);
		pthread_create(&tab->philo[i].philo, NULL, philo_life, &tab->philo[i]);
		i++;
	}
	pthread_create(&tab->checker, NULL, checker, tab);
}

int		main(int argc, char **argv)
{
	t_info *tab;

	if (argc == 5 || argc == 6)
	{
		tab = parse_get_arg(argc, argv);
		if (tab == NULL)
			return (1);
		if (init_mutex(tab))
			return (1);
		create_philo(tab);
		pthread_join(tab->checker, NULL);
		exit_free_philo(tab);
		return (0);
	}
	else
		printf("Error : argc != 5 || argc != 6\n");
	return (1);
}
