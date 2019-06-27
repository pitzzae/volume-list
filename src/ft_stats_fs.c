/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stats_fs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:33:03 by gtorresa          #+#    #+#             */
/*   Updated: 2019/06/13 13:30:47 by gtorresa         ###   ########.fr       */
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
	unsigned long blksize, blocks, freeblks;
	t_data *data;

	data = (t_data *) lst->content;
	if (!statvfs(select_path(data), &buf)) {
		blksize = buf.f_bsize;
		blocks = buf.f_blocks;
		freeblks = buf.f_bfree;
		data->size = blocks * blksize;
		data->free = freeblks * blksize;
		data->used = data->size - data->free;
	}
}