/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_t_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 14:22:23 by gtorresa          #+#    #+#             */
/*   Updated: 2019/06/13 13:30:47 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_volume_list.h"

void ft_free_t_data(void *ptr, size_t len) {
	t_data *data;

	(void) len;
	data = (t_data *) ptr;
	free(data->path);
	free(data->mount);
	free(data->device);
	free(data->fstype);
	free(ptr);
}