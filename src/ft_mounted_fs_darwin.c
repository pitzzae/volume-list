/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mounted_fs_darwin.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:33:03 by gtorresa          #+#    #+#             */
/*   Updated: 2019/06/13 13:30:47 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_volume_list.h"

#ifdef __APPLE__

t_list *ft_mounted_fs(void) {
	struct statfs buf[MAX_FS];
	int fs_count;
	int i;
	t_list *l;

	fs_count = getfsstat(NULL, 0, MNT_NOWAIT);
	if (fs_count == -1)
		return NULL;
	getfsstat(buf, fs_count * sizeof(buf[0]), MNT_NOWAIT);
	l = ft_lstnew(
			ft_mounted_fs_content(NULL,
								  buf[0].f_mntonname,
								  buf[0].f_mntfromname,
								  buf[0].f_fstypename),
			sizeof(t_data));
	for (i = 1; i < fs_count; ++i) {
		if (ft_mounted_fs_filter(l, buf[i].f_mntonname))
			ft_lstadd(&l, ft_lstnew(
					ft_mounted_fs_content(NULL,
										  buf[i].f_mntonname,
										  buf[0].f_mntfromname,
										  buf[0].f_fstypename),
					sizeof(t_data)));
	}
	return l;
}

#endif
