/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelgharo <yelgharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:32:24 by yelgharo          #+#    #+#             */
/*   Updated: 2022/06/04 01:14:49 by yelgharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data {
	int				tt_many;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				tt_repeat;
	int				num;
	int				dead;
	int				s;
	pthread_mutex_t	tap;
	long long		starting;
	struct s_philo	*head;
}	t_data;

typedef struct s_philo {
	int					id;
	pthread_t			thread_id;
	pthread_mutex_t		fork;
	t_data				*shared;
	int					m_eaten;
	long				last;
	struct s_philo		*next;
}	t_philo;

void	routine(void *phil);
void	sleep_time(long time);

int		ft_atoi(const char *str);
t_philo	*ft_lstnew(int i, t_data *shared);
void	ft_lstadd_back(t_philo **alst, t_philo *new);
long long	ft_time(void);

#endif