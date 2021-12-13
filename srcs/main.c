/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:10:02 by gpaul             #+#    #+#             */
/*   Updated: 2021/12/13 18:34:51 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	exit_free_philo(t_info *tab)
{
	int	i;

	i = 0;
	while (i < tab->nbr_philo)
	{
		pthread_mutex_destroy(tab->philo[i].fork_l);
		i++;
	}
	free(tab->philo);
	free(tab->forks);
	free(tab);
}

void	*checker(void *arg)
{
	t_info	*tab;
	int		i;
	int		exit;

	tab = arg;
	exit = 0;
	while (exit == 0 && tab->eaten != tab->nbr_philo)
	{
		i = 0;
		while (i < tab->nbr_philo && (exit == 0
				&& tab->eaten != tab->nbr_philo))
		{
			gettimeofday(&tab->time, NULL);
			if ((time_to_ms(tab) - tab->philo[i].last_eat)
				> (unsigned int)tab->time_to_die)
				exit = i;
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
		if (tab->philo[i].id % 2 == 0)
			pthread_create(&tab->philo[i].philo,
				NULL, philo_life0, &tab->philo[i]);
		else
			pthread_create(&tab->philo[i].philo,
				NULL, philo_life1, &tab->philo[i]);
		i++;
	}
	pthread_create(&tab->checker, NULL, checker, tab);
}

int	main(int argc, char **argv)
{
	t_info	*tab;

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
