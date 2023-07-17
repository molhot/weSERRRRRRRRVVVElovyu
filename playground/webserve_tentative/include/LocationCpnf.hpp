/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LocationCpnf.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 21:47:46 by user              #+#    #+#             */
/*   Updated: 2023/07/17 23:05:48 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LocationConf_HPP
#define LocationConf_HPP

class LocationConf
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
		bool									_autoindex;
		std::map<std::string, std::string>				_return_redirect;
	public:
	
};

#endif