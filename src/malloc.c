/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 13:31:08 by tanguy            #+#    #+#             */
/*   Updated: 2016/08/27 10:28:41 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void *add_small_link(t_link *start, long size, long max)
{
	t_link *node;
	t_link *tmp;

	node = start;
	while (node->next != NULL)
	{
		if ((char*)node->next - (char*)node->end >= size)
			break;
		node = node->next;
	}
	if ((char*)node->end + size > (char*)start + max)
	{
		errno = ENOMEM;
		return NULL;
	}
	tmp = node->next;
	node->next = node->end;
	node->next->end = (t_link*)((char*)node->next + size);
	node->next->next = tmp;
	return node->next + 1;
}

void	*malloc(size_t size)
{
	t_link *node;

	size += sizeof(t_link);
	if (size <= TNY_MAX)
		return add_small_link(alloc_data()->tny, size, alloc_data()->tny_max);
	if (size <= MED_MAX)
		return add_small_link(alloc_data()->med, size, alloc_data()->med_max);
	node = alloc_data()->lrg;
	while (node->next != NULL)
		node = node->next;
	node->next = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (node->next == NULL)
	{
		errno = ENOMEM;
		return NULL;
	}
	node->next->end = (t_link*)((char*)node->next + size);
	node->next->next = NULL;
	return node->next + 1;
}
