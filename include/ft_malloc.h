/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 15:35:45 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/08/27 22:09:23 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/mman.h>
# include <errno.h>
# include "libft.h"

# define TNY_PAGE_MAX 8
# define TNY_MAX (8 * 4096)
# define MED_PAGE_MAX 32
# define MED_MAX (32 * 4096)

typedef struct		s_link {
	struct s_link	*end;
	struct s_link	*next;
}					t_link;

typedef struct		s_data {
	t_link			*tny;
	size_t			tny_max;
	t_link			*med;
	size_t			med_max;
	t_link			*lrg;
}					t_data;

extern t_data		*g_saved;

void				free(void *ptr);
void				*malloc(size_t size);
void				*realloc(void *ptr, size_t size);
void				show_alloc_mem();
t_data				*alloc_data();

#endif
