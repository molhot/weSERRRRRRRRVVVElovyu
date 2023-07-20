/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SameportConf.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 23:08:03 by user              #+#    #+#             */
/*   Updated: 2023/07/20 11:01:38 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/SameportConf.hpp"

SameportConf::SameportConf():_server_tokens(1)
{

}

SameportConf::~SameportConf()
{

}

// 　-＝ ∧ ∧　　setterだよ！　∧ ∧ ＝-
// -＝と( ･∀･)			   （･∀･ ) ＝-
// 　-＝/ と_ノ			     と_ノヾ ＝-
// -＝_/／⌒ｿ				   (_＞､＼ ＝-

void	SameportConf::set_port(std::string const &port){ this->_port = port; }
void	SameportConf::set_servername(std::vector<std::string> const &server_name){ this->_server_name = server_name; }
void	SameportConf::set_root(std::string const &root){ this->_root = root; }
void	SameportConf::set_indexpage_set(std::vector<std::string> const &_indexpage_set){ this->_indexpage_set = _indexpage_set; };
void	SameportConf::set_allowmethod_set(std::vector<std::string> const &_allowed_method){ this->_allowmethod_set = _allowed_method; };
void	SameportConf::set_locations(std::map<std::string, LocationConf> const &locations){ this->_locations = locations; };
void	SameportConf::set_maxBodySize(size_t const &maxBodySize){ this->_maxBodySize = maxBodySize; };
void	SameportConf::set_errorpage_set(std::map<std::string, std::string> const &errorpage_set){ this->_errorpage_set = errorpage_set; };
void	SameportConf::set_chunked_transferencoding_allow(bool const &allow_or_not){ this->_chunked_transferencoding_allow = allow_or_not; };
void	SameportConf::set_accesslog(std::string const &access_log){ this->_accesslog = access_log; };
void	SameportConf::set_errorlog(std::string const &error_log){ this->_errorlog = error_log; };
void	SameportConf::set_keepaliverequests(size_t const &max_requests){ this->_keepaliverequests = max_requests; };
void	SameportConf::set_keepalive_timeout(size_t const &timeout){ this->_keepalive_timeout = timeout; };
void	SameportConf::set_autoindex(std::string const &on_off){ this->_autoindex = on_off; };
void	SameportConf::set_client_body_buffer_size(size_t const &buffersize){ this->_client_body_buffer_size = buffersize; };
void	SameportConf::set_client_body_timeout(size_t const &timeout){ this->_client_body_timeout = timeout; };
void	SameportConf::set_client_header_buffer_size(size_t const &buffersize){ this->_client_header_buffer_size = buffersize; };
void	SameportConf::set_client_header_timeout(size_t const &timeout){ this->_client_header_timeout = timeout; };
void	SameportConf::set_client_maxbody_size(size_t const &buffersize){ this->_client_maxbody_size = buffersize; };
void	SameportConf::set_default_type(std::string const &default_type){ this->_default_type = default_type; };
