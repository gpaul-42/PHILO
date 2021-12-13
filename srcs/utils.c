/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:38:57 by gpaul             #+#    #+#             */
/*   Updated: 2021/12/10 18:18:56 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int				ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	re;

	re = 0;
	i = 0;
	sign = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		re = re * 10 + (str[i++] - '0');
	}
	if (sign == 1)
		return ((int) -re);
	else
		return ((int)re);
}

int				check_malloc(void *dest, size_t size)
{
	*(void**)dest = malloc(size);
	if (*(void**)dest == NULL)
		return (1);
	memset(*(void**)dest, 0, size);
	return (0);
}

void			ft_print(t_philo *philo, int option)
{
	unsigned int ms;
	struct timeval time;
	
	gettimeofday(&time, NULL);
	ms = ((time.tv_sec * 1000) + (time.tv_usec / 1000)) - philo->time_crea;
	if (option == 0)
		printf("%u %d has taken a fork\n", ms, philo->id);
	else if (option == 1)
		printf("%u %d is eating\n", ms, philo->id);
	else if (option == 2)
		printf("%u %d is sleeping\n", ms, philo->id);
	else if (option == 3)
		printf("%u %d is thinking\n", ms, philo->id);
	else if (option == 4)
		printf("%u %d died\n", ms, philo->id);
}

unsigned int	time_to_ms(t_info *tab)
{
	unsigned int re;

	re = ((tab->time.tv_sec * 1000) + (tab->time.tv_usec / 1000));
	return (re);
}
