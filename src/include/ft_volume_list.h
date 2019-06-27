/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_volume_list.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:33:03 by gtorresa          #+#    #+#             */
/*   Updated: 2019/06/13 13:30:47 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VOLUME_LIST_H
# define FT_VOLUME_LIST_H

#ifdef __APPLE__

#include <sys/ucred.h>

#else
#include <stdio.h>
#include <mntent.h>
#endif

#include <sys/statvfs.h>
#include <sys/param.h>
#include <sys/mount.h>

#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include "../libft/include/libft.h"
#include "../libnapi/include/libnapi.h"

#define MAX_FS 128

typedef struct s_data {
	unsigned long size;
	unsigned long used;
	unsigned long free;
	char *path;
	char *mount;
	char *device;
	char *fstype;
} t_data;


t_list *ft_mounted_fs(void);

void ft_stats_fs(t_list *lst);

t_data *ft_mounted_fs_content(char * path, char *mount, char *device, char *fstype);

int ft_mounted_fs_filter(t_list *l, char *s);

void ft_free_t_data(void *ptr, size_t len);

#endif