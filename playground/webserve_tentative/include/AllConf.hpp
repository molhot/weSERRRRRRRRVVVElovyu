/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AllConf.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 21:18:13 by user              #+#    #+#             */
/*   Updated: 2023/07/22 15:38:31 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AllConf_HPP
#define AllConf_HPP

#include <iostream>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "InterpretLocationconf.hpp"
#include "InterpretServerconf.hpp"
#include "HandlingString.hpp"
#include "SameportConf.hpp"
#include "Socket.hpp"

class AllConf
{
	private:
		std::map<int, std::string>							conf_rank;
		std::map<std::string, SameportConf >				all_conf;//port(listen) その中の各情報（ポートに紐づく情報は一つと限らない）
		bool												_confready;
		static struct timeval								_timeout;
		std::map<int, std::vector<SameportConf> >			_sockets;
		int													_allFD;
		std::vector<int>									_acceptedFD;
		
		size_t												count_semicoron(std::string const &line);
		void												conf_check(std::string const &config_file);
		bool												contentch(std::string const &config_file);
		bool												serverstr_contain(std::string const &one_line);
		bool												server_directive_ch(std::string const &line, bool *in_serverdhirect, bool *in_allocationdhirect, SameportConf &portconf, LocationConf &locationconf);
		bool												location_dhirect_ch(std::string const &line);
		bool												location_ch(std::string const &line);
		bool												content_containnotrequiredword(std::string const& config_file);
		std::string											obtain_locationpath(std::string const &line);
	
	public:
		AllConf(std::string const &config_file);
		~AllConf();

		bool												get_confready();
		std::map<std::string, SameportConf >				get_all_conf();
		std::map<int, std::string>							get_conf_rank();

		bool												serverkeyword(std::string const &line, SameportConf& port_conf);
		bool												locationkeyword(std::string const &line, LocationConf& locationconf);
		bool												allocationch(std::string const &config_file);

		void												makeServersockets(void);
};

#endif
