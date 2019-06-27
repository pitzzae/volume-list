/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_napi_get_array_arg.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:28:51 by gtorresa          #+#    #+#             */
/*   Updated: 2019/06/13 13:30:47 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libnapi.h"

char *parse_array(napi_value *argv, uint32_t i) {
	napi_valuetype type;
	napi_status status;
	napi_value e;
	char *res;
	size_t len;

	res = malloc(sizeof(char) * 1024);
	status = napi_get_element(ft_napi_env(NULL), argv[0], i, &e);
	if (status != napi_ok)
		napi_throw_error(ft_napi_env(NULL), NULL, "Failed to parse array");
	status = napi_typeof(ft_napi_env(NULL), e, &type);
	if (status != napi_ok)
		napi_throw_error(ft_napi_env(NULL), NULL,
						 "Failed to get arguments type");
	if (type != napi_string)
		napi_throw_error(ft_napi_env(NULL), NULL, "Wrong argument type");
	status = napi_get_value_string_utf8(ft_napi_env(NULL), e, res, 1024, &len);
	if (status != napi_ok)
		napi_throw_error(ft_napi_env(NULL), NULL, "Error on string parse");
	return res;
}

t_list *ft_napi_get_array_arg(napi_callback_info info) {
	napi_status status;
	size_t argc = 1;
	napi_value argv[1];
	napi_valuetype type;
	napi_value ret;
	uint32_t i, length;
	t_list *lst;
	char *str;

	lst = NULL;
	length = 0;
	status = napi_get_cb_info(ft_napi_env(NULL), info, &argc, argv, NULL, NULL);

	if (status != napi_ok)
		napi_throw_error(ft_napi_env(NULL), NULL, "Failed to parse arguments");

	status = napi_typeof(ft_napi_env(NULL), argv[0], &type);
	if (status != napi_ok)
		napi_throw_error(ft_napi_env(NULL), NULL,
						 "Failed to get arguments type");

	if (type == napi_object) {
		status = napi_create_array(ft_napi_env(NULL), &ret);
		if (status != napi_ok)
			napi_throw_error(ft_napi_env(NULL), NULL,
							 "Failed to create array arguments");

		status = napi_get_array_length(ft_napi_env(NULL), argv[0], &length);
		if (status != napi_ok)
			napi_throw_error(ft_napi_env(NULL), NULL,
							 "Failed to get array length");

		i = 0;
		if (length > 0) {
			str = parse_array(&argv[0], i++);
			lst = ft_lstnew(ft_mounted_fs_content(str, NULL, NULL, NULL),
							sizeof(t_data));
			free(str);
		}
		while (i < length) {
			str = parse_array(&argv[0], i++);
			ft_lstadd(&lst,
					  ft_lstnew(ft_mounted_fs_content(str, NULL, NULL, NULL),
								sizeof(t_data)));
			free(str);
		}
		return lst;
	} else if (type == napi_undefined || type == napi_null)
		return NULL;
	else
		napi_throw_error(ft_napi_env(NULL), NULL, "Wrong argument type");
	return NULL;
}