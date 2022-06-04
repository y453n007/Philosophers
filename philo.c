/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelgharo <yelgharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 04:11:03 by yelgharo          #+#    #+#             */
/*   Updated: 2022/06/04 01:08:22 by yelgharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	func(int nb, t_data *t)
{
	t->num = nb;
	t->dead = 0;
	t->s = 0;
}

int	ft_parse(int nb, char **str, t_data *t)
{
	int	i;

	i = (t->tt_many = ft_atoi(str[1]));
	if (i < 1)
		return (1);
	i = (t->tt_die = ft_atoi(str[2]));
	if (i < 0)
		return (1);
	i = (t->tt_eat = ft_atoi(str[3]));
	if (i < 0)
		return (1);
	i = (t->tt_sleep = ft_atoi(str[4]));
	if (i < 0)
		return (1);
	if (nb == 6)
	{
		i = (t->tt_repeat = ft_atoi(str[5]));
		if (i < 0)
			return (1);
	}
	else
		t->tt_repeat = -1;
	func(nb, t);
	t->starting = ft_time();
	return (0);
}

int	ft_start(t_philo **d)
{
	t_philo		*tmp;
	int			nb;

	tmp = *d;
	while (tmp)
	{
		nb = pthread_create(&tmp->thread_id, NULL, (void *)routine, tmp);
		if (nb != 0)
			return (1);
		tmp->last = ft_time();
		tmp = tmp->next;
	}
	return (0);
}

int	ft_create(t_data *t, t_philo **d)
{
	int		i;
	t_philo	*tmp;

	i = 1;
	tmp = NULL;
	while (i <= t->tt_many)
	{
		tmp = ft_lstnew(i, t);
		ft_lstadd_back(d, tmp);
		if (i == 1)
			t->head = tmp ;
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	t;
	t_philo	*d;

	d = NULL;
	if (ac > 4 && ac < 7)
	{
		if (ft_parse(ac, av, &t))
			return (1);
		pthread_mutex_init(&(t.tap), NULL);
		if (ft_create(&t, &d))
			return (1);
		if (ft_start(&d))
			return (1);
		while (1)
		{
			if (t.s == t.tt_many)
				break ;
			usleep(500);
		}
	}
	return (0);
}
