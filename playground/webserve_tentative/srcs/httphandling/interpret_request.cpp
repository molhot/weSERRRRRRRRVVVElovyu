/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_request.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 01:25:30 by user              #+#    #+#             */
/*   Updated: 2023/07/23 20:39:30 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Request.hpp"

void	Request::split_path()
{
	std::string	path_all = this->_allpath;
	this->_querypath = path_all.substr(path_all.find("?") + 1);

	std::string	key;
	std::string	val;

	std::string	query_string;
	size_t pos;
    while ((pos = query_string.find("&")) != std::string::npos)
    {
        std::string param = query_string.substr(0, pos);
        size_t equal_pos = param.find("=");
        std::string key = param.substr(0, equal_pos);
        std::string val = param.substr(equal_pos + 1);//query_combi
		this->query_combi[key] = val;
        query_string.erase(0, pos + 1);
    }

    size_t last_equal_pos = query_string.find("=");
    std::string last_key = query_string.substr(0, last_equal_pos);
    std::string last_val = query_string.substr(last_equal_pos + 1);
	this->query_combi[last_key] = last_val;
}

Request::Request(std::string const &mes)
{
	std::istringstream	splited_msg(mes);
	std::string			request_line;

	getline(splited_msg, request_line);
	std::string	method;
	std::string	path;
	std::string	version;

	splited_msg >> this->_method >> this->_allpath >> this->_version;
	split_path();
	
}

Request::~Request()
{
	
}