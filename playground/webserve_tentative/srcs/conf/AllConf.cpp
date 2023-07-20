/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AllConf.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 21:32:19 by user              #+#    #+#             */
/*   Updated: 2023/07/20 11:58:58 by user             ###   ########.fr       */
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

bool	AllConf::locationkeyword(std::string const &line, SameportConf port_conf){ (void)line; (void)port_conf; return (true);}

bool	AllConf::location_dhirect_ch(std::string const &line)
{
	std::istringstream	splited_words(line);
	std::string			keyword;
	size_t				pos = 0;

	splited_words >> keyword;
	if (keyword == "location{")
	{
		std::istringstream	splited_words_cp(line);
		while (splited_words_cp >> keyword)
			pos++;
		if (pos != 1)
			return (false);
	}
	else
	{
		std::istringstream	splited_words_cp(line);
		while (splited_words_cp >> keyword)
			pos++;
		if (pos != 2)
			return (false);
	}
	return (true);
}

bool	AllConf::serverkeyword(std::string const &line, SameportConf port_conf)
{
	std::istringstream	splited_woeds(line);
	std::string			key_word;
	std::string			val;

	splited_woeds >> key_word >> val;
	if (InterpretServerconf::serverkeyword_ch(key_word) == false)
		return (false);
	if (key_word == "listen")
		port_conf.set_port(val); 
	else if (key_word == "server")
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
	// else if 

	return (true);
}

bool	AllConf::server_directive_ch(std::string const &line, bool *in_serverdhirect, bool *in_allocationdhirect)
{
	bool				conf_correct = true;
	std::istringstream	splited_woeds(line);
	std::string			key_word;
	SameportConf		port_conf;

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
				while (line[pos] != '\0' || line[pos] == '{')
				{
					if (line[pos] != ' ' || line[pos] == '\t')
						return (false);
					pos++;
				}
				return (true);
			}
		}
	}
	return (false);
}

bool	AllConf::contentch(std::string const &config_file)
{
	std::ifstream	conf_file(config_file);
	std::string		line;
	bool			in_serverdhirect = false;
	bool			in_allocationdhirect = false;

	conf_file.is_open();
	while (std::getline(conf_file, line))
	{
		if (line[0] == '#' || line[0] == '\n')
			continue;
    	else if (in_serverdhirect == false && serverstr_contain(line) == false)
			return (false);
		else if (in_serverdhirect == false && serverstr_contain(line) == true)
			in_serverdhirect = true;
		else if (in_serverdhirect == true)
		{
			if (server_directive_ch(line, &in_serverdhirect, &in_allocationdhirect) == false)
				return (false);
		}
    }
}

void	AllConf::conf_check(std::string const &config_file)
{
	std::ifstream conf_file(config_file);
	if (conf_file.is_open() == false)
		return ;
	else
		this->_confready = contentch(config_file);
}