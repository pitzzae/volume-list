/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mounted_fs_filter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:33:03 by gtorresa          #+#    #+#             */
/*   Updated: 2019/06/13 13:30:47 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_volume_list.h"

int ft_mounted_fs_filter(t_list *l, char *s) {
	t_list *ptr;
	char *device;

	ptr = l;
	while (ptr) {
		device = ((t_data *) ptr->content)->device;
		if (device && ft_strcmp(device, s) == 0)
			return 0;
		ptr = ptr->next;
	}
	return 1;
}