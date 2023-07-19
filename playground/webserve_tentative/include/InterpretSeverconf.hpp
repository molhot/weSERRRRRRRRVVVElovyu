/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InterpretSeverconf.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 21:36:37 by user              #+#    #+#             */
/*   Updated: 2023/07/19 22:15:40 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef InterpretServerconf_HPP
#define InterpretServerconf_HPP

#include <iostream>
#include <string>
#include <set>

class InterpretServerconf
{
	private:
		static const std::set<std::string> server_keyset;

	public:
		static bool serverkeyword_ch(const std::string& word);
};

const std::set<std::string> InterpretServerconf::server_keyset = {
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

#endif InterpretLocationconf_HPP