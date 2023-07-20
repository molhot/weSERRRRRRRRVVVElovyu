/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AllConf.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 21:32:19 by user              #+#    #+#             */
/*   Updated: 2023/07/21 00:45:38 by user             ###   ########.fr       */
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

bool	AllConf::locationkeyword(std::string const &line, SameportConf port_conf)
{ 
	(void)line; 
	(void)port_conf; 
	std::cout << "in" << std::endl;
	
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

bool	AllConf::serverkeyword(std::string const &line, SameportConf port_conf)
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
	else if (key_word == "keepalive_timeout")
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
		port_conf.set_chunked_transferencoding_allow(HandringString::return_matchpattern("on", "off", val));
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

bool	AllConf::server_directive_ch(std::string const &line, bool *in_serverdhirect, bool *in_allocationdhirect, SameportConf& port_conf)
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
		conf_correct = locationkeyword(line, port_conf);
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
			if (line[pos + 1] == 'e' || line[pos + 2] == 'r' || line[pos + 3] == 'v' || line[pos + 4] == 'e' || line[pos + 5] == 'r')
			{
				pos = pos + 6;
				while (line[pos] != '\0' && line[pos] == '{')
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

bool	AllConf::contentch(std::string const &config_file)
{
	std::ifstream	conf_file(config_file);
	std::string		line;
	std::string		splited_line;
	SameportConf	port_conf;
	LocationConf	location_conf;
	bool			in_serverdhirect = false;
	bool			in_allocationdhirect = false;

	conf_file.is_open();
	while (std::getline(conf_file, line))
	{
		std::cout << "line is |" << line << "|" << std::endl;;
		splited_line = line;
		std::string			first_wd;
		std::istringstream	splited_words(splited_line);
		splited_words >> first_wd;
		if (first_wd == "" || line[0] == '#' || line == "\n" || first_wd[0] == '#' || first_wd == "\n")
			continue;
    	else if (in_serverdhirect == false && serverstr_contain(line) == false)
			return (false);
		else if (in_serverdhirect == false && serverstr_contain(line) == true)
			in_serverdhirect = true;
		else if (in_serverdhirect == true)
		{
			if (server_directive_ch(line, &in_serverdhirect, &in_allocationdhirect, port_conf) == false)
				return (false);
		}
		if (in_serverdhirect == false && in_allocationdhirect == false)
			std::cout << "not in dhirective" << std::endl;
		else if (in_serverdhirect == true && in_allocationdhirect == false)
			std::cout << "in server dhirective" << std::endl;
		else if (in_serverdhirect == true && in_allocationdhirect == true)
			std::cout << "in allocation dhirective" << std::endl;
		else if (in_serverdhirect == false && in_allocationdhirect == true)
			std::cout << "??" << std::endl;
    }
	return (true);
}

void	AllConf::conf_check(std::string const &config_file)
{
	std::ifstream conf_file(config_file);
	if (conf_file.is_open() == false)
		return ;
	else
		this->_confready = contentch(config_file);
}