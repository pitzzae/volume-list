/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mounted_fs_content.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:33:03 by gtorresa          #+#    #+#             */
/*   Updated: 2019/06/13 13:30:47 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_volume_list.h"

t_data *ft_mounted_fs_content(char *path, char *mount, char *device, char *fstype) {
	t_data *content;

	content = malloc(sizeof(t_data));
	content->path = ft_strdup(path);
	content->mount = ft_strdup(mount);
	content->device = ft_strdup(device);
	content->fstype = ft_strdup(fstype);
	content->free = 0;
	content->size = 0;
	content->used = 0;
	return content;
}