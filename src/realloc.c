/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 13:31:08 by tanguy            #+#    #+#             */
/*   Updated: 2016/08/27 21:55:03 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static int	refit(t_link *start, t_link *node, long size, long max)
{
	if (((char*)node->next + size <= (char*)node->next->end)
		|| (node->next->next != NULL && (char*)node->next + size
		<= (char*)node->next->next) || (node->next->next == NULL
		&& ((char*)node->next + size) - (char*)start <= max))
	{
		node->next->end = (t_link*)((char*)node->next + size);
		return (1);
	}
	return (0);
}

static void	*realloc_small(t_link *start, t_link *ptr, long size, long max)
{
	t_link *node;

	node = start;
	while (node->next != NULL)
	{
		if (ptr == node->next + 1)
		{
			if (refit(start, node, size, max) == 1)
				return (ptr);
			ptr = malloc(size);
			if (ptr == NULL)
			{
				errno = ENOMEM;
				return (NULL);
			}
			if (size > (char*)node->next->end - (char*)node->next)
				size = (char*)node->next->end - (char*)node->next;
			ft_memcpy(ptr, node->next + 1, size);
			free(node->next);
			return (ptr);
		}
		node = node->next;
	}
	return (NULL);
}

void		*realloc(void *ptr, size_t size)
{
	t_link *node;

	size += sizeof(t_link);
	errno = 0;
	node = realloc_small(alloc_data()->tny, ptr, size, alloc_data()->tny_max);
	if (node != NULL || errno == ENOMEM)
		return (node);
	node = realloc_small(alloc_data()->med, ptr, size, alloc_data()->med_max);
	if (node != NULL || errno == ENOMEM)
		return (node);
	node = alloc_data()->lrg;
	while (node->next != NULL)
	{
		if (ptr != node->next + 1 && (node = node->next) != NULL)
			continue ;
		if ((ptr = malloc(size)) == NULL)
			return ((void*)((long)(errno = ENOMEM) * 0));
		if (size > (size_t)((char*)node->next->end - (char*)node->next))
			size = (char*)node->next->end - (char*)node->next;
		ft_memcpy(ptr, node->next + 1, size);
		free(node->next);
		return (ptr);
	}
	return (NULL);
}
