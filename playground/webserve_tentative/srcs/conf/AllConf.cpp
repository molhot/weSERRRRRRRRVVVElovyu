/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AllConf.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 21:32:19 by user              #+#    #+#             */
/*   Updated: 2023/07/21 15:17:48 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/AllConf.hpp"

AllConf::AllConf(std::string const &config_file):_confready(false)
{
	conf_check(config_file);
}

AllConf::~AllConf()
{
	
}

bool AllConf::get_confready()
{
	return (this->_confready);
}

bool	AllConf::locationkeyword(std::string const &line, LocationConf& locationconf)
{
	(void)line;
	(void)locationconf;
	// std::istringstream	splited_woeds(line);
	// std::string			key_word;
	// std::string			val;

	// splited_woeds >> key_word >> val;
	// if (key_word == "" && val == "")
	// {
	// 	std::cout << "there is all emp" << std::endl;
	// 	return (true);
	// }
	// if (InterpretServerconf::serverkeyword_ch(key_word) == false)
	// 	return (false);
	// if (key_word == "listen")
	// 	port_conf.set_port(val);
	// else if (key_word == "cgi_extension")//何するかわかってない
	// 	;
	// else if (key_word == "server_name")
	// 	port_conf.set_servername(HandringString::inputargtomap_withoutfirst(line));
	// else if (key_word == "root")
	// 	port_conf.set_root(val);
	// else if (key_word == "index")
	// 	port_conf.set_root(val);
	// else if (key_word == "allow_methods")
	// 	port_conf.set_allowmethod_set(HandringString::inputargtomap_withoutfirst(line));
	// else if (key_word == "error_page")
	// 	port_conf.set_errorlog(val);
	// else if (key_word == "chunked_transfer_encoding")
	// {
	// 	if (val != "on" && val != "off")
	// 		return (false);
	// 	port_conf.set_chunked_transferencoding_allow(HandringString::return_matchpattern("on", "off", val));
	// }
	// else if (key_word == "access_log")
	// 	port_conf.set_accesslog(val);
	// else if (key_word == "error_log")
	// 	port_conf.set_errorlog(val);
	// else if (key_word == "keepalive_requests")
	// {
	// 	if (HandringString::ch_under_intmax(val) == false)
	// 		return (false);
	// 	port_conf.set_keepaliverequests(HandringString::str_to_int(HandringString::skip_lastsemicoron(val)));
	// }
	// else if (key_word == "keepalive_timeout")//timeoutの実装がC++98のみでは難しい、Cでも許可された関数にない
	// {
	// 	if (HandringString::ch_under_intmax(val) == false)
	// 		return (false);
	// 	port_conf.set_keepalive_timeout(HandringString::str_to_int(HandringString::skip_lastsemicoron(val)));
	// }
	// else if (key_word == "server_tokens")
	// 	;
	// else if (key_word == "autoindex")
	// {
	// 	if (val != "on" && val != "off")
	// 		return (false);
	// 	port_conf.set_chunked_transferencoding_allow(HandringString::return_matchpattern("on", "off", val));
	// }
	// else if (key_word == "rewrite")//何するのかわからん
	// 	;
	// else if (key_word == "return")//何するのかわからん
	// 	;
	// else if (key_word == "client_body_buffer_size")//単位付きで入ってくる場合に対応する必要性、簡単のために単位なしに一旦する
	// {
	// 	if (HandringString::ch_under_intmax(val) == false)
	// 		return (false);
	// 	port_conf.set_client_body_buffer_size(HandringString::str_to_int(HandringString::skip_lastsemicoron(val)));
	// }
	// else if (key_word == "client_body_timeout")
	// {
	// 	if (HandringString::ch_under_intmax(val) == false)
	// 		return (false);
	// 	port_conf.set_client_body_timeout(HandringString::str_to_int(HandringString::skip_lastsemicoron(val)));
	// }
	// else if (key_word == "client_header_buffer_size")
	// {
	// 	if (HandringString::ch_under_intmax(val) == false)
	// 		return (false);
	// 	port_conf.set_client_header_buffer_size(HandringString::str_to_int(HandringString::skip_lastsemicoron(val)));
	// }
	// else if (key_word == "client_header_timeout")
	// {
	// 	if (HandringString::ch_under_intmax(val) == false)
	// 		return (false);
	// 	port_conf.set_client_header_timeout(HandringString::str_to_int(HandringString::skip_lastsemicoron(val)));
	// }
	// else if (key_word == "client_max_body_size")
	// {
	// 	if (HandringString::ch_under_intmax(val) == false)
	// 		return (false);
	// 	port_conf.set_client_maxbody_size(HandringString::str_to_int(HandringString::skip_lastsemicoron(val)));
	// }
	// else if (key_word == "default_type")
	// 	port_conf.set_default_type(val);
	// else
	// 	return (false);
	// return (true);
	return (true);
}

bool	AllConf::location_dhirect_ch(std::string const &line)
{
	std::istringstream	splited_words(line);
	std::string			keyword;
	std::string			nextwd;
	std::string			thirdwd;
	std::string			forthwd;

	splited_words >> keyword >> nextwd >> thirdwd >> forthwd;
	if (keyword == "location" && thirdwd == "{" && forthwd == "")
		return (true);
	return (false);
}

bool	AllConf::serverkeyword(std::string const &line, SameportConf& port_conf)
{
	std::istringstream	splited_woeds(line);
	std::string			key_word;
	std::string			val;

	splited_woeds >> key_word >> val;
	if (key_word == "" && val == "")
	{
		std::cout << "there is all emp" << std::endl;
		return (true);
	}
	if (InterpretServerconf::serverkeyword_ch(key_word) == false)
		return (false);
	if (key_word == "listen")
		port_conf.set_port(val);
	else if (key_word == "cgi_extension")//何するかわかってない
		;
	else if (key_word == "server_name")
		port_conf.set_servername(HandringString::inputargtomap_withoutfirst(line));
	else if (key_word == "root")
		port_conf.set_root(val);
	else if (key_word == "index")
		port_conf.set_root(val);
	else if (key_word == "allow_methods")
		port_conf.set_allowmethod_set(HandringString::inputargtomap_withoutfirst(line));
	else if (key_word == "error_page")
		port_conf.set_errorlog(val);
	else if (key_word == "chunked_transfer_encoding")
	{
		if (val != "on" && val != "off")
			return (false);
		port_conf.set_chunked_transferencoding_allow(HandringString::return_matchpattern("on", "off", val));
	}
	else if (key_word == "access_log")
		port_conf.set_accesslog(val);
	else if (key_word == "error_log")
		port_conf.set_errorlog(val);
	else if (key_word == "keepalive_requests")
	{
		if (HandringString::ch_under_intmax(val) == false)
			return (false);
		port_conf.set_keepaliverequests(HandringString::str_to_int(HandringString::skip_lastsemicoron(val)));
	}
	else if (key_word == "keepalive_timeout")//timeoutの実装がC++98のみでは難しい、Cでも許可された関数にない
	{
		if (HandringString::ch_under_intmax(val) == false)
			return (false);
		port_conf.set_keepalive_timeout(HandringString::str_to_int(HandringString::skip_lastsemicoron(val)));
	}
	else if (key_word == "server_tokens")
		;
	else if (key_word == "autoindex")
	{
		if (val != "on" && val != "off")
			return (false);
		port_conf.set_autoindex(HandringString::return_matchpattern("on", "off", val));
	}
	else if (key_word == "rewrite")//何するのかわからん
		;
	else if (key_word == "return")//何するのかわからん
		;
	else if (key_word == "client_body_buffer_size")//単位付きで入ってくる場合に対応する必要性、簡単のために単位なしに一旦する
	{
		if (HandringString::ch_under_intmax(val) == false)
			return (false);
		port_conf.set_client_body_buffer_size(HandringString::str_to_int(HandringString::skip_lastsemicoron(val)));
	}
	else if (key_word == "client_body_timeout")
	{
		if (HandringString::ch_under_intmax(val) == false)
			return (false);
		port_conf.set_client_body_timeout(HandringString::str_to_int(HandringString::skip_lastsemicoron(val)));
	}
	else if (key_word == "client_header_buffer_size")
	{
		if (HandringString::ch_under_intmax(val) == false)
			return (false);
		port_conf.set_client_header_buffer_size(HandringString::str_to_int(HandringString::skip_lastsemicoron(val)));
	}
	else if (key_word == "client_header_timeout")
	{
		if (HandringString::ch_under_intmax(val) == false)
			return (false);
		port_conf.set_client_header_timeout(HandringString::str_to_int(HandringString::skip_lastsemicoron(val)));
	}
	else if (key_word == "client_max_body_size")
	{
		if (HandringString::ch_under_intmax(val) == false)
			return (false);
		port_conf.set_client_maxbody_size(HandringString::str_to_int(HandringString::skip_lastsemicoron(val)));
	}
	else if (key_word == "default_type")
		port_conf.set_default_type(val);
	else
		return (false);
	return (true);
}

bool	AllConf::server_directive_ch(std::string const &line, bool *in_serverdhirect, bool *in_allocationdhirect, SameportConf& port_conf, LocationConf& locationconf)
{
	bool				conf_correct = true;
	std::istringstream	splited_woeds(line);
	std::string			key_word;

	splited_woeds >> key_word;
	if (key_word == "location{" || key_word == "location")
	{
		if (location_dhirect_ch(line) == false)
			return (false);
		else
		{
			*in_allocationdhirect = true;
			return (true);
		}
	}
	else if (*in_allocationdhirect == false && key_word == "}")
	{
		*in_serverdhirect = false;
		return (true);
	}
	else if (*in_allocationdhirect == false)
		conf_correct = serverkeyword(line, port_conf);
	else if (*in_allocationdhirect == true && key_word == "}")
	{
		*in_allocationdhirect = false;
		return (true);
	}
	else if (*in_allocationdhirect == true)
		conf_correct = locationkeyword(line, locationconf);
	return (conf_correct);
}

bool	AllConf::serverstr_contain(std::string const &line)
{
	size_t	pos;

	pos = 0;
	while (line[pos] != '\0')
	{
		if (line[pos] == 's')
		{
			if (line[pos + 1] == 'e' && line[pos + 2] == 'r' && line[pos + 3] == 'v' && line[pos + 4] == 'e' && line[pos + 5] == 'r')
			{
				pos = pos + 6;
				while (line[pos] != '\0' && line[pos] != '{')
				{
					if (line[pos] != ' ' || line[pos] == '\t')
						return (false);
					pos++;
				}
				return (true);
			}
		}
		else if (line[pos] == ' ' || line[pos] == '\t')
			pos++;
		else
			return (false);
	}
	return (false);
}

// bool	AllConf::contentch(std::string const &config_file)
// {
// 	std::ifstream	conf_file(config_file);
// 	std::string		line;
// 	std::string		splited_line;
// 	SameportConf	port_conf;
// 	LocationConf	location_conf;
// 	bool			in_serverdhirect = false;
// 	bool			in_allocationdhirect = false;

// 	conf_file.is_open();
// 	while (std::getline(conf_file, line))
// 	{
// 		std::cout << "line is |" << line << "|" << std::endl;
// 		splited_line = line;
// 		std::string			first_wd;
// 		std::istringstream	splited_words(splited_line);
// 		splited_words >> first_wd;
// 		if (first_wd == "" || line[0] == '#' || line == "\n" || first_wd[0] == '#' || first_wd == "\n")
// 			continue;
//     	else if (in_serverdhirect == false && serverstr_contain(line) == false)
// 			return (false);
// 		else if (in_serverdhirect == false && serverstr_contain(line) == true)
// 			in_serverdhirect = true;
// 		else if (in_serverdhirect == true)
// 		{
// 			if (server_directive_ch(line, &in_serverdhirect, &in_allocationdhirect, port_conf, location_conf) == false)
// 				return (false);
// 		}
// 		if (in_serverdhirect == false && in_allocationdhirect == false)
// 			std::cout << "not in dhirective" << std::endl;
// 		else if (in_serverdhirect == true && in_allocationdhirect == false)
// 			std::cout << "in server dhirective" << std::endl;
// 		else if (in_serverdhirect == true && in_allocationdhirect == true)
// 			std::cout << "in allocation dhirective" << std::endl;
// 		else if (in_serverdhirect == false && in_allocationdhirect == true)
// 			std::cout << "??" << std::endl;
//     }
// 	return (true);
// }

size_t	AllConf::count_semicoron(std::string const &line)
{
	size_t	semicolon_num = 0;
	size_t	pos = 0;

	while (line[pos] != '\0')
	{
		if (line[pos] == ';')
			semicolon_num++;
		pos++;
	}
	return (semicolon_num);
}

bool	AllConf::location_ch(std::string const &line)
{
	size_t	pos;

	pos = 0;
	while (line[pos] != '\0')
	{
		if (line[pos] == 'l')
		{
			if (line[pos + 1] == 'o' && line[pos + 2] == 'c' && line[pos + 3] == 'a' && line[pos + 4] == 't' && line[pos + 5] == 'i' && line[pos + 6] == 'o' && line[pos + 7] == 'n')
			{
				if (line[pos + 8] != ' ')
				{
					return (false);
				}
				return (true);
			}
			else
				return (false);
		}
		else if (line[pos] == ' ' || line[pos] == '\t')
			pos++;
		else
		{
			return (false);
		}
	}
	return (false);
}

bool	AllConf::content_containnotrequiredword(std::string const &config_file)
{
	std::ifstream	conf_file(config_file);
	std::string		line;
	std::string		skip_emp;
	bool			in_server= false;
	bool			in_location = false;
	size_t			pos = 1;
	SameportConf	portconf;

	conf_file.is_open();
	while (std::getline(conf_file, line))
	{
		skip_emp = HandringString::skipping_emptywd(line);
		std::cout << "emp is " << skip_emp << std::endl;
		if (in_location == true && in_server == true)// locationの中 locationの中だからserverの中
		{
			if (skip_emp == "}")
				in_location = false;
		}
		else
		{
			if (in_server == true)//locationの外　serverの中
			{
				if (location_ch(line) == true)
					in_location = true;
				else if (skip_emp == "}")
				{
					if (portconf.get_port() == "")
					{
						std::cout << "conf must contain port!!" << std::endl;
						return (false);
					}
					this->all_conf[portconf.get_port()].push_back(portconf);
					portconf.reset_contents();
					in_server = false;
				}
				else if (skip_emp[0] == '#')
					;
				else if (serverkeyword(line, portconf) == false)
				{
					HandringString::error_show(skip_emp, pos);
					return (false);
				}
			}
			else//完全に外
			{
				if (serverstr_contain(skip_emp) == true)
					in_server = true;
				else if (skip_emp == "" || skip_emp[0] == '#')
					;
				else
				{
					HandringString::error_show(skip_emp, pos);
					return (false);
				}
			}
		}
		pos++;
	}
	return (true);
}

bool	AllConf::contentch(std::string const &config_file)
{
	if (content_containnotrequiredword(config_file) == false)
		return (false);
	return (true);
}

void	AllConf::conf_check(std::string const &config_file)
{
	std::ifstream conf_file(config_file);
	if (conf_file.is_open() == false)
		return ;
	else
		this->_confready = contentch(config_file);
	if (this->_confready == false)
		return ;
	
}