/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InterpretLocationonf.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:44:01 by user              #+#    #+#             */
/*   Updated: 2023/07/21 19:56:35 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/InterpretLocationconf.hpp"

bool InterpretLocationconf::locationkeyword_ch(const std::string& word)
{
	const std::string server_keyset_arr[] = {
        "root", "index", "error_page", "areas", "allow_methods",
		"chunked_transfer_encoding", "access_log", "error_log", "keepalive_requests",
		"keepalive_timeout", "server_tokens", "autoindex", "rewrite", "return", "client_body_buffer_size",
		"client_body_timeout", "client_header_buffer_size", "client_header_timeout",
		"client_max_body_size", "default_type", "log_not_found", "cgi_path", "alias", "upload_path"
    };

    const std::set<std::string> location_keyset
    (
        server_keyset_arr,
        server_keyset_arr + sizeof(server_keyset_arr) / sizeof(server_keyset_arr[0])
    );

    if (location_keyset.count(word) > 0)
        return true;
    return false;
}