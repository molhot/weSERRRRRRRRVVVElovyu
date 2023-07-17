/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SameportConf.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 21:23:41 by user              #+#    #+#             */
/*   Updated: 2023/07/17 23:00:10 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SameportConf_HPP
#define SameportConf_HPP

#include <string>
#include <vector>
#include <map>

#include "LocationCpnf.hpp"

class SameportConf
{
	private:
		std::string								_port;
		std::string								_server_name;
		std::string								_root;
		std::vector<std::string>				_indexpage_set;
		std::vector<std::string>				_allowmethod_set;
		std::map<std::string, LocationConf>		_locations;
		size_t 									_maxBodySize;
		std::map<std::string, std::string> 		_errorpage_set;
	public:
};

#endif