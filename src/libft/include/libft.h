/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:08:25 by gtorresa          #+#    #+#             */
/*   Updated: 2019/06/13 13:30:47 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H
# define FT_LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_list {
	void *content;
	size_t content_size;
	struct s_list *next;
} t_list;

t_list *ft_lstnew(void const *c, size_t cz);

void ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

void ft_lstdel(t_list **alst, void (*del)(void *, size_t));

void ft_lstadd(t_list **alst, t_list *newlst);

void ft_lstiter(t_list *lst, void (*f)(t_list *elem));

size_t ft_strlen(const char *s1);

int ft_strcmp(const char *s1, const char *s2);

char *ft_strdup(char *s1);

void *ft_memcpy(void *dst, const void *src, size_t len);

#endif
