/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libnapi.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:33:03 by gtorresa          #+#    #+#             */
/*   Updated: 2019/06/13 13:30:47 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBNAPI_H
# define FT_LIBNAPI_H

#include <node_api.h>
#include "../../libft/include/libft.h"
#include "../../include/ft_volume_list.h"

napi_env ft_napi_env(napi_env *env);

napi_value ft_napi_create_object(void);

void
ft_napi_set_object_property(napi_value Object, char *name, napi_value Value);

napi_value ft_napi_set_object_number(unsigned long value);

napi_value ft_napi_set_object_string(char *value);

t_list *ft_napi_get_array_arg(napi_callback_info info);

#endif