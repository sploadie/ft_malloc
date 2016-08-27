/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 15:07:04 by tanguy            #+#    #+#             */
/*   Updated: 2016/08/27 21:55:31 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_data *saved = NULL;

t_data *alloc_data()
{
	if (saved == NULL)
	{
		saved = mmap(NULL, sizeof(t_data) + sizeof(t_link)
			+ getpagesize() * TNY_PAGE_MAX * 100
			+ getpagesize() * MED_PAGE_MAX * 100,
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		saved->tny_max = getpagesize() * TNY_PAGE_MAX * 100;
		saved->tny = (t_link*)(saved + 1);
		saved->tny->end = saved->tny + 1;
		saved->tny->next = NULL;
		saved->med_max = getpagesize() * MED_PAGE_MAX * 100;
		saved->med = (t_link*)((char*)saved->tny + saved->tny_max);
		saved->med->end = saved->med + 1;
		saved->med->next = NULL;
		saved->lrg = (t_link*)((char*)saved->med + saved->med_max);
		saved->lrg->end = saved->lrg + 1;
		saved->lrg->next = NULL;
	}
	return (saved);
}
