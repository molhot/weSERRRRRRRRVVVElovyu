/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InterpretServerconf.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:41:30 by user              #+#    #+#             */
/*   Updated: 2023/07/20 11:13:36 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/InterpretServerconf.hpp"

static const std::set<std::string> InterpretServerconf::server_keyset = {
    "listen", "servername", "root", "index", "allow_methods", "error_page", "types",
    "chunked_transfer_encoding", "access_log", "error_log", "keepalive_requests",
    "keepalive_timeout", "server_tokens", "autoindex", "rewrite", "return", "client_body_buffer_size",
    "client_body_timeout", "client_header_buffer_size", "client_header_timeout",
    "client_max_body_size", "default_type"
};

bool InterpretServerconf::serverkeyword_ch(const std::string& word)
{
    if (server_keyset.count(word) > 0)
        return false;
    return true;
}

