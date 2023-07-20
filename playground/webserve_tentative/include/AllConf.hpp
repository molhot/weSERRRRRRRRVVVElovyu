/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AllConf.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 21:18:13 by user              #+#    #+#             */
/*   Updated: 2023/07/20 11:59:04 by user             ###   ########.fr       */
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

class AllConf
{
	private:
		std::map<std::string, std::vector <SameportConf> >	all_conf;//port(listen) その中の各情報（ポートに紐づく情報は一つと限らない）
		bool												_confready;
		void												conf_check(std::string const &config_file);
		bool												contentch(std::string const &config_file);
		bool												serverstr_contain(std::string const &one_line);
		bool												server_directive_ch(std::string const &line, bool *in_serverdhirect, bool *in_allocationdhirect);
		bool												location_dhirect_ch(std::string const &line);
	
	public:
		AllConf(std::string const &config_file);
		~AllConf();
		bool												serverkeyword(std::string const &line, SameportConf port_conf);
		bool												locationkeyword(std::string const &line, SameportConf port_conf);
};

#endif
