/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stats_fs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:33:03 by gtorresa          #+#    #+#             */
/*   Updated: 2019/06/28 08:54:44 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_volume_list.h"

char *select_path(t_data *data) {
	if (data->path != NULL)
		return data->path;
	else
		return data->mount;
}

void ft_stats_fs(t_list *lst) {
	struct statvfs buf;
	t_data *data;

	data = (t_data *) lst->content;
	if (!statvfs(select_path(data), &buf)) {
		data->size = buf.f_blocks * buf.f_frsize;
		data->free = buf.f_bfree * buf.f_frsize;
		data->used = data->size - data->free;
	}
}