/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InterpretLocationconf.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:06:02 by user              #+#    #+#             */
/*   Updated: 2023/07/19 21:42:07 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef InterpretLocationconf_HPP
#define InterpretLocationconf_HPP

#include <iostream>
#include <string>
#include <set>

class InterpretLocationconf
{
	private:
		static const std::set<std::string> location_keyset;

	public:
		static bool locationkeyword_ch(const std::string& word);
};

const std::set<std::string> InterpretLocationconf::location_keyset = {
    "root", "index", "error_page", "areas",
    "chunked_transfer_encoding", "access_log", "error_log", "keepalive_requests",
    "keepalive_timeout", "server_tokens", "autoindex", "rewrite", "return", "client_body_buffer_size",
    "client_body_timeout", "client_header_buffer_size", "client_header_timeout",
    "client_max_body_size", "default_type", "log_not_found"
};

bool InterpretLocationconf::locationkeyword_ch(const std::string& word)
{
    if (location_keyset.count(word) > 0)
        return false;
    return true;
}

#endif InterpretLocationconf_HPP