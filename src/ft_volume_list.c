/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   volume_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:33:03 by gtorresa          #+#    #+#             */
/*   Updated: 2019/06/28 12:54:12 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_volume_list.h"

void ft_lsttoarray(napi_env env, t_list *lst,
				   void (*f)(napi_env env, t_list *elem, napi_value *myArray),
				   napi_value *myArray) {
	t_list *tmp;
	size_t p;

	tmp = lst;
	p = 0;
	while (tmp->next) {
		tmp->content_size = p;
		if (((t_data *) tmp->content)->size) {
			(*f)(env, tmp, myArray);
			p++;
		}
		tmp = tmp->next;
	}
	tmp->content_size = p;
	if (((t_data *) tmp->content)->size)
		(*f)(env, tmp, myArray);
}

napi_value create_volume(t_list *lst) {
	napi_value Object;
	t_data *data;

	data = (t_data *) lst->content;
	Object = ft_napi_create_object();

	ft_napi_set_object_property(Object, "size",
								ft_napi_set_object_number(data->size));

	ft_napi_set_object_property(Object, "used",
								ft_napi_set_object_number(data->used));

	ft_napi_set_object_property(Object, "free",
								ft_napi_set_object_number(data->free));

	if (data->mount != NULL)
		ft_napi_set_object_property(Object, "mount",
									ft_napi_set_object_string(data->mount));

	if (data->device != NULL)
		ft_napi_set_object_property(Object, "device",
									ft_napi_set_object_string(data->device));

	if (data->fstype != NULL)
		ft_napi_set_object_property(Object, "fstype",
									ft_napi_set_object_string(data->fstype));

	if (data->path != NULL)
		ft_napi_set_object_property(Object, "path",
									ft_napi_set_object_string(data->path));
	return Object;
}

void data_display(napi_env env, t_list *lst, napi_value *myArray) {
	napi_status status;

	status = napi_set_element(env, *myArray, (uint32_t) lst->content_size,
							  create_volume(lst));
	if (status != napi_ok) {
		napi_throw_error(env, NULL, "Unable to push myObject value");
	}
}

void print_lst(t_list *lst) {
	t_data *data;

	data = (t_data *) lst->content;
	printf("data->path = %s\n", data->path);
	printf("data->mount = %s\n", data->mount);
	printf("data->fstype = %s\n", data->fstype);
	printf("data->device = %s\n", data->device);
	printf("data->fsid = %lu\n", data->fsid);
	printf("data->free = %zu\n", data->free);
	printf("data->size = %zu\n", data->size);
	printf("data->used = %zu\n\n", data->used);
}

void get_device_info(t_list *lst_mount, t_list *lst_arg) {
	t_list *tmp1;
	t_list *tmp2;
	t_data *data1;
	t_data *data2;

	tmp1 = lst_arg;
	tmp2 = lst_mount;
	while (tmp1) {
		data1 = (t_data *) tmp1->content;
		while (tmp2) {
			data2 = (t_data *) tmp2->content;
			if (data1->fsid == data2->fsid) {
				data1->mount = ft_strdup(data2->mount);
				data1->fstype = ft_strdup(data2->fstype);
				data1->device = ft_strdup(data2->device);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
		tmp2 = lst_mount;
	}
}

napi_value DiskList(napi_env env, napi_callback_info info) {
	napi_status status;
	napi_value myArray;
	t_list *lst_mount;
	t_list *lst_arg;

	status = napi_create_array(env, &myArray);
	if (status != napi_ok) {
		napi_throw_error(env, NULL, "Unable to create myArray value");
	}

	lst_arg = ft_napi_get_array_arg(info);
	lst_mount = ft_mounted_fs();
	if (lst_arg == NULL) {
		ft_lstiter(lst_mount, ft_stats_fs);
		//ft_lstiter(lst_mount, print_lst);
		ft_lsttoarray(env, lst_mount, data_display, &myArray);
		ft_lstdel(&lst_mount, ft_free_t_data);
	} else {
		get_device_info(lst_mount, lst_arg);
		ft_lstiter(lst_arg, ft_stats_fs);
		//ft_lstiter(lst_arg, print_lst);
		ft_lsttoarray(env, lst_arg, data_display, &myArray);
		ft_lstdel(&lst_arg, ft_free_t_data);
	}
	return myArray;
}

napi_value Init(napi_env env, napi_value exports) {
	napi_status status;
	napi_value fn;

	ft_napi_env(&env);
	status = napi_create_function(env, NULL, 0, DiskList, NULL, &fn);
	if (status != napi_ok) {
		napi_throw_error(env, NULL, "Unable to wrap native function");
	}

	status = napi_set_named_property(env, exports, "list", fn);
	if (status != napi_ok) {
		napi_throw_error(env, NULL, "Unable to populate exports");
	}

	return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
