/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelgharo <yelgharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 00:02:08 by yelgharo          #+#    #+#             */
/*   Updated: 2022/06/04 01:01:45 by yelgharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_thinking(t_philo *philo)
{
	if (philo->shared->dead == 0)
	{
		pthread_mutex_lock(&(philo->shared->tap));
		printf("%lld %d %s\n", (ft_time() - philo->shared->starting), \
			philo->id, "is thinking");
		pthread_mutex_unlock(&(philo->shared->tap));
	}
}

void	ft_sleeping(t_philo *philo)
{
	if (philo->shared->dead == 0)
	{
		sleep_time(philo->shared->tt_sleep);
		pthread_mutex_lock(&(philo->shared->tap));
		printf("%lld %d %s\n", (ft_time() - philo->shared->starting), \
			philo->id, "is sleeping");
		pthread_mutex_unlock(&(philo->shared->tap));
	}
}

void	ft_eating(t_philo *philo)
{
	t_philo	*next_fork;

	if (philo->next == NULL)
		next_fork = philo->shared->head;
	else
		next_fork = philo->next;
	if (philo->shared->dead == 0)
	{
		pthread_mutex_lock(&(philo->fork));
		pthread_mutex_lock(&(philo->shared->tap));
		printf("%lld %d %s\n", (ft_time() - philo->shared->starting), \
			philo->id, "taked his fork");
		pthread_mutex_unlock(&(philo->shared->tap));
		pthread_mutex_lock(&(next_fork->fork));
		pthread_mutex_lock(&(philo->shared->tap));
		printf("%lld %d %s\n", (ft_time() - philo->shared->starting), \
			philo->id, "taked next fork");
		pthread_mutex_unlock(&(philo->shared->tap));
		pthread_mutex_lock(&(philo->shared->tap));
		printf("%lld %d %s\n", (ft_time() - philo->shared->starting), \
			philo->id, "is eating");
		pthread_mutex_unlock(&(philo->shared->tap));
		sleep_time(philo->shared->tt_eat);
		philo->last = ft_time();
		philo->m_eaten++;
		if (philo->m_eaten == philo->shared->tt_repeat)
			philo->shared->s++;
		pthread_mutex_unlock(&(next_fork->fork));
		pthread_mutex_unlock(&(philo->fork));
	}
}

void	routine(void *phil)
{
	t_philo	*philo;

	philo = (t_philo *)phil;
	if (philo->id % 2)
		usleep(100);
	while (philo->shared->dead == 0 && \
		philo->shared->s != philo->shared->tt_many)
	{
		ft_eating(philo);
		if (philo->m_eaten == philo->shared->tt_repeat)
			break ;
		ft_sleeping(philo);
		ft_thinking(philo);
	}
	return ;
}
