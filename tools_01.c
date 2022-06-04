/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelgharo <yelgharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 21:28:05 by yelgharo          #+#    #+#             */
/*   Updated: 2022/06/04 22:20:56 by yelgharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	sleep_time(long time)
{
	long	current_time;

	current_time = ft_time();
	while ((ft_time() - current_time) < time)
		usleep(100);
}

void	func(int nb, t_data *t)
{
	t->num = nb;
	t->dead = 0;
	t->s = 0;
}
