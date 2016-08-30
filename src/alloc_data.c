/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 15:07:04 by tanguy            #+#    #+#             */
/*   Updated: 2016/08/27 22:06:48 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_data *g_saved = NULL;

t_data *alloc_data()
{
	if (g_saved == NULL)
	{
		g_saved = mmap(NULL, sizeof(t_data)
			+ getpagesize() * TNY_PAGE_MAX * 100
			+ getpagesize() * MED_PAGE_MAX * 100,
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		g_saved->tny_max = getpagesize() * TNY_PAGE_MAX * 100;
		g_saved->tny = (t_link*)(g_saved + 1);
		g_saved->tny->end = g_saved->tny + 2;
		g_saved->tny->next = NULL;
		g_saved->med_max = getpagesize() * MED_PAGE_MAX * 100;
		g_saved->med = (t_link*)((char*)g_saved->tny + g_saved->tny_max);
		g_saved->med->end = g_saved->med + 1;
		g_saved->med->next = NULL;
		g_saved->lrg = (t_link*)(g_saved->tny + 1);
		g_saved->lrg->end = g_saved->lrg + 1;
		g_saved->lrg->next = NULL;
	}
	return (g_saved);
}
