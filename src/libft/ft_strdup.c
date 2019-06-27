/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:33:24 by gtorresa          #+#    #+#             */
/*   Updated: 2019/06/13 13:30:47 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

char *ft_strdup(char *src) {
	size_t a;
	size_t b;
	char *str2;

	if (src == NULL)
		return NULL;
	a = ft_strlen(src);
	str2 = (char *) malloc(sizeof(char) * (a + 1));
	b = 0;
	while (b < a) {
		str2[b] = src[b];
		b++;
	}
	str2[b] = '\0';
	return (str2);
}
