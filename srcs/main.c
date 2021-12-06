/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:10:02 by gpaul             #+#    #+#             */
/*   Updated: 2021/12/06 18:45:02 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_philo *tab;

	if (argc < 4)
		return (0);
	else
	{
		tab = malloc(sizeof(t_philo) * 1);
		if (tab == NULL)
			return (1);
		tab->nbr_philo = ft_atoi(argv[1]);
		tab->time_to_die = ft_atoi(argv[2]);
		tab->time_to_eat = ft_atoi(argv[3]);
		tab->time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
		{
			tab->nbr_time_eat = ft_atoi(argv[5]);
			printf("%d\n%d\n%d\n%d\n%d\n", tab->nbr_philo, tab->time_to_die, tab->time_to_eat, tab->time_to_sleep, tab->nbr_time_eat);
		}
		else
			printf("%d\n%d\n%d\n%d\n", tab->nbr_philo, tab->time_to_die, tab->time_to_eat, tab->time_to_sleep);
		free(tab);
	}
	

	return 0;
}