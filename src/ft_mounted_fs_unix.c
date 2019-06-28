/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mounted_fs_unix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 14:22:23 by gtorresa          #+#    #+#             */
/*   Updated: 2019/06/28 12:05:53 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_volume_list.h"

#ifdef __linux__

t_list *ft_mounted_fs(void) {
	void *mounts;
	struct mntent *ent;
	t_list *mount_list;
	t_list *mount_list_tmp;

	mounts = setmntent("/etc/mtab", "r");
	mount_list = NULL;
	while ((ent = getmntent(mounts)) != NULL) {
		if (ent->mnt_fsname[0] == '/') {
			if (mount_list != NULL && ft_mounted_fs_filter(mount_list, ent->mnt_fsname)) {
				mount_list_tmp = ft_lstnew(NULL, sizeof(t_data));
				mount_list_tmp->content = ft_mounted_fs_content(NULL, ent->mnt_dir, ent->mnt_fsname, ent->mnt_type);
				ft_lstadd(&mount_list, mount_list_tmp);
			} else if (mount_list == NULL) {
				mount_list = ft_lstnew(NULL, sizeof(t_data));
				mount_list->content = ft_mounted_fs_content(NULL, ent->mnt_dir, ent->mnt_fsname, ent->mnt_type);
			}
		}
	}
	endmntent(mounts);
	return mount_list;
}

#endif
