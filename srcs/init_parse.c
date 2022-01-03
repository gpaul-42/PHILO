/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:51:34 by gpaul             #+#    #+#             */
/*   Updated: 2021/12/20 16:20:25 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static t_info	*get_arg(int argc, char **argv)
{
	t_info	*tab;

	if (check_malloc(&tab, sizeof(t_info) * 1))
		return (NULL);
	init_var(tab);
	if (check_arg(argv[1]) == 0 && ft_atoi(argv[1]) <= MAX)
		tab->nbr_philo = (int)ft_atoi(argv[1]);
	if (check_arg(argv[2]) == 0 && ft_atoi(argv[2]) <= MAX)
		tab->time_to_die = (int)ft_atoi(argv[2]);
	if (check_arg(argv[3]) == 0 && ft_atoi(argv[3]) <= MAX)
		tab->time_to_eat = (int)ft_atoi(argv[3]);
	if (check_arg(argv[4]) == 0 && ft_atoi(argv[4]) <= MAX)
		tab->time_to_sleep = (int)ft_atoi(argv[4]);
	if (argc == 6)
	{
		if (check_arg(argv[5]) == 0 && ft_atoi(argv[5]) <= MAX)
			tab->nbr_time_to_eat = (int)ft_atoi(argv[5]);
		tab->nbr_arg = 1;
	}
	return (tab);
}

static int	parse_arg(t_info *tab)
{
	if (tab->nbr_philo <= 0 && tab->nbr_philo < MAX)
		return (free_error(tab, "philo"));
	if (tab->nbr_arg && tab->nbr_time_to_eat <= 0)
		return (free_error(tab, "nbr of time to eat"));
	if (tab->time_to_die <= 0)
		return (free_error(tab, "time to die"));
	if (tab->time_to_eat <= 0)
		return (free_error(tab, "time to eat"));
	if (tab->time_to_sleep <= 0)
		return (free_error(tab, "time to sleep"));
	return (0);
}

t_info	*parse_get_arg(int argc, char **argv)
{
	t_info	*tab;

	tab = get_arg(argc, argv);
	if (tab == NULL)
		return (NULL);
	tab->exit = 0;
	tab->eaten = 0;
	if (parse_arg(tab) == 1)
		return (NULL);
	return (tab);
}

int	init_mutex(t_info *tab)
{
	int	i;

	if (check_malloc(&tab->philo, sizeof(t_philo) * tab->nbr_philo))
		return (1);
	i = 0;
	if (check_malloc(&tab->forks, sizeof(pthread_mutex_t) * tab->nbr_philo))
		return (1);
	while (i < tab->nbr_philo)
	{
		tab->philo[i].id = i + 1;
		if (pthread_mutex_init(&tab->forks[i], NULL))
			return (1);
		tab->philo[i].fork_l = &tab->forks[i];
		tab->philo[i].tab = tab;
		i++;
	}
	return (0);
}

int	mutex_exit(t_info *tab)
{
	if (pthread_mutex_init(&tab->lock_exit, NULL))
		return (1);
	if (pthread_mutex_init(&tab->lock_eaten, NULL))
		return (1);
	return (0);
}
