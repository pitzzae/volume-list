/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mounted_fs_darwin.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:33:03 by gtorresa          #+#    #+#             */
/*   Updated: 2019/06/28 16:03:46 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_volume_list.h"

#ifdef __APPLE__

t_list *add_element(struct statfs *buf) {
	return ft_lstnew(
			ft_mounted_fs_content(NULL,
								  buf->f_mntonname,
								  buf->f_mntfromname,
								  buf->f_fstypename),
			sizeof(t_data));
}

t_list *ft_mounted_fs(void) {
	struct statfs *buf;
	int fs_count;
	int i;
	t_list *l;

	i = 1;
	fs_count = getfsstat(NULL, 0, MNT_NOWAIT);
	if (fs_count == -1)
		return NULL;
	else {
		buf = malloc(fs_count * sizeof(*buf));
		ft_bzero(buf, fs_count * sizeof(*buf));
	}
	getfsstat(buf, fs_count * sizeof(*buf), MNT_NOWAIT);
	l = add_element(buf);
	buf++;
	while (i++ < fs_count) {
		if (ft_mounted_fs_filter(l, buf->f_mntonname))
			ft_lstadd(&l, add_element(buf));
		buf++;
	}
	free((buf - fs_count));
	return l;
}

#endif
