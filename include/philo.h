/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:10:36 by gpaul             #+#    #+#             */
/*   Updated: 2021/12/14 15:42:06 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <string.h>

# define MAX 2147483647
# define MIN -2147483648

typedef struct s_philo
{
	struct s_info	*tab;
	pthread_t		philo;
	pthread_mutex_t	*fork_l;
	int				id;
	unsigned int	time_crea;
	unsigned int	last_eat;
	int				nbr_eat;
}				t_philo;

typedef struct s_info
{
	struct timeval	time;
	t_philo			*philo;
	pthread_t		checker;
	pthread_mutex_t	*forks;
	int				nbr_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_time_to_eat;
	int				nbr_arg;
	int				exit;
	int				eaten;
}				t_info;

/*
	INIT/PARSE
*/
t_info			*parse_get_arg(int argc, char **argv);
int				init_mutex(t_info *tab);
int				fork_give(t_info *tab);

/*
	PHILO LIFE
*/
int				philo_sleep(t_philo *philo, int status);
int				philo_think(t_philo *philo, int status);
int				philo_take_forks(t_philo *philo, int status);
int				philo_eat(t_philo *philo, int status);
int				philo_drop_forks(t_philo *philo);
void			*philo_life0(void *arg);
void			*philo_life1(void *arg);

/*
	UTILS
*/
int				ft_atoi(const char *str);
int				free_error(t_info *tab, char *str);
int				check_malloc(void *dest, size_t size);
void			ft_print(t_philo *philo, int option);
unsigned int	time_to_ms(t_info *tab);

#endif
