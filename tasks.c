/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelgharo <yelgharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 00:02:08 by yelgharo          #+#    #+#             */
/*   Updated: 2022/05/25 18:29:38 by yelgharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_thinking(t_philo *philo)
{
	printf("%s %d %s\n", "timestamp_in_ms\tthe philo id :", \
		philo->id, "is thinking");
}

void	ft_sleeping(t_philo *philo)
{
	printf("%s %d %s\n", "timestamp_in_ms\tthe philo id :", \
		philo->id, "is sleeping");
	usleep(philo->shared->tt_sleep * 1000);
}

void	ft_eating(t_philo *philo)
{
	t_philo	*next_fork;

	if (philo->next == NULL)
		next_fork = philo->shared->head;
	else
		next_fork = philo->next;
	pthread_mutex_lock(&(philo->fork));
	printf("%s %d %s\n", "timestamp_in_ms\tthe philo id :", \
		philo->id, "taked his fork");
	pthread_mutex_lock(&(next_fork->fork));
	printf("%s %d %s\n", "timestamp_in_ms\tthe philo id :", \
		philo->id, "taked left fork");
	printf("%s %d %s\n", "timestamp_in_ms\tthe philo id :", \
	philo->id, "is eating");
	philo->m_eaten++;
	if(philo->m_eaten == philo->shared->tt_repeat)
		philo->shared->s++;
	usleep(philo->shared->tt_eat * 1000);
	pthread_mutex_unlock(&(next_fork->fork));
	pthread_mutex_unlock(&(philo->fork));
}
