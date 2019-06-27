/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   volume_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:33:03 by gtorresa          #+#    #+#             */
/*   Updated: 2019/06/28 08:31:07 by gtorresa         ###   ########.fr       */
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
								ft_napi_set_object_uint32(data->size));

	ft_napi_set_object_property(Object, "used",
								ft_napi_set_object_uint32(data->used));

	ft_napi_set_object_property(Object, "free",
								ft_napi_set_object_uint32(data->free));

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
	printf("data->free = %zu\n", data->free);
	printf("data->size = %zu\n", data->size);
	printf("data->used = %zu\n\n", data->used);
}

napi_value DiskList(napi_env env, napi_callback_info info) {
	napi_status status;
	napi_value myArray;
	t_list *lst;

	status = napi_create_array(env, &myArray);
	if (status != napi_ok) {
		napi_throw_error(env, NULL, "Unable to create myArray value");
	}

	lst = ft_napi_get_array_arg(info);
	if (lst == NULL)
		lst = ft_mounted_fs();
	ft_lstiter(lst, ft_stats_fs);
	//ft_lstiter(lst, print_lst);
	ft_lsttoarray(env, lst, data_display, &myArray);
	ft_lstdel(&lst, ft_free_t_data);
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
