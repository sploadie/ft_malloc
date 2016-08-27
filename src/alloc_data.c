/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 15:07:04 by tanguy            #+#    #+#             */
/*   Updated: 2016/08/27 10:13:50 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_data *alloc_data()
{
	static t_data *saved = NULL;

	if (saved == NULL)
	{
		saved = mmap(NULL, sizeof(t_data), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		saved->tny_max = getpagesize() * TNY_PAGE_MAX * 100;
		saved->tny = mmap(NULL, saved->tny_max, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		saved->tny->end = saved->tny + 1;
		saved->tny->next = NULL;
		saved->med_max = getpagesize() * MED_PAGE_MAX * 100;
		saved->med = mmap(NULL, saved->med_max, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		saved->med->end = saved->med + 1;
		saved->med->next = NULL;
		saved->lrg = mmap(NULL, sizeof(t_link), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		saved->lrg->end = saved->lrg + 1;
		saved->lrg->next = NULL;
	}
	return saved;
}