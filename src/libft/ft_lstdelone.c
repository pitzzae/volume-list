/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 14:12:25 by gtorresa          #+#    #+#             */
/*   Updated: 2019/06/13 13:30:47 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

void ft_lstdelone(t_list **alst, void (*del)(void *, size_t)) {
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
