/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LocationConf.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:21:54 by user              #+#    #+#             */
/*   Updated: 2023/07/21 19:58:37 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/LocationConf.hpp"
#include "../../include/SameportConf.hpp"

LocationConf::LocationConf():_server_tokens(1)
{

}

LocationConf::LocationConf(SameportConf const &some):_server_tokens(1)
{
	this->_port = some.get_port();
	this->_server_name = some.get_servername();
	this->_root = some.get_root();
	this->_indexpage_set = some.get_indexpage_set();
	this->_allowmethod_set = some.get_allowmethod_set();
	this->_maxBodySize = some.get_maxBodySize();
	this->_errorpage_set = some.get_errorpage_set();
	this->_chunked_transferencoding_allow = some.get_chunked_transferencoding_allow();
	this->_accesslog = some.get_accesslog();
	this->_errorlog = some.get_errorlog();
	this->_keepaliverequests = some.get_keepaliverequests();
	this->_keepalive_timeout = some.get_keepalive_timeout();
	this->_autoindex = some.get_autoindex();
	this->_client_body_buffer_size = some.get_client_body_buffer_size();
	this->_client_body_timeout = some.get_client_body_timeout();
	this->_client_header_buffer_size = some.get_client_body_buffer_size();
	this->_client_header_timeout = some.get_client_header_timeout();
	this->_client_maxbody_size = some.get_client_maxbody_size();
	this->_default_type = some.get_default_type();
}

LocationConf::~LocationConf()
{

}

// 　-＝ ∧ ∧　　setterだよ！　∧ ∧ ＝-
// -＝と( ･∀･)			   （･∀･ ) ＝-
// 　-＝/ と_ノ			     と_ノヾ ＝-
// -＝_/／⌒ｿ				   (_＞､＼ ＝-

void	LocationConf::set_port(std::string const &port){ this->_port = port; };
void	LocationConf::set_servername(std::vector<std::string> const &server_name){ this->_server_name = server_name; };
void	LocationConf::set_root(std::string const &root){ this->_root = root; };
void	LocationConf::set_indexpage_set(std::vector<std::string> const &_indexpage_set){ this->_indexpage_set = _indexpage_set; };
void	LocationConf::set_allowmethod_set(std::vector<std::string> const &_allowed_method){ this->_allowmethod_set = _allowed_method; };
void	LocationConf::set_locations(std::map<std::string, LocationConf> const &locations){ this->_locations = locations; };
void	LocationConf::set_maxBodySize(size_t const &maxBodySize){ this->_maxBodySize = maxBodySize; };
void	LocationConf::set_errorpage_set(std::map<std::string, std::string> const &errorpage_set){ this->_errorpage_set = errorpage_set; };
void	LocationConf::set_chunked_transferencoding_allow(bool const &allow_or_not){ this->_chunked_transferencoding_allow = allow_or_not; };
void	LocationConf::set_accesslog(std::string const &access_log){ this->_accesslog = access_log; };
void	LocationConf::set_errorlog(std::string const &error_log){ this->_errorlog = error_log; };
void	LocationConf::set_keepaliverequests(size_t const &max_requests){ this->_keepaliverequests = max_requests; };
void	LocationConf::set_keepalive_timeout(size_t const &timeout){ this->_keepalive_timeout = timeout; };
void	LocationConf::set_autoindex(bool const &on_off){ this->_autoindex = on_off; };
void	LocationConf::set_client_body_buffer_size(size_t const &buffersize){ this->_client_body_buffer_size = buffersize; };
void	LocationConf::set_client_body_timeout(size_t const &timeout){ this->_client_body_timeout = timeout; };
void	LocationConf::set_client_header_buffer_size(size_t const &buffersize){ this->_client_header_buffer_size = buffersize; };
void	LocationConf::set_client_header_timeout(size_t const &timeout){ this->_client_header_timeout = timeout; };
void	LocationConf::set_client_maxbody_size(size_t const &buffersize){ this->_client_maxbody_size = buffersize; };
void	LocationConf::set_default_type(std::string const &default_type){ this->_default_type = default_type; };
void	LocationConf::set_cgi_path(std::string const &cgi_path){ this->_cgi_path = cgi_path; };
void	LocationConf::set_alias(std::string const &alias){ this->_alias = alias; };
void	LocationConf::set_upload_path(std::string const &upload_path){ this->_upload_path = upload_path; };

//     ∩∩     getterだよ
//   （´･ω･）
//   ＿| ⊃／(＿＿_
//  ／ └-(＿＿＿_／ 
//  ￣￣￣￣￣￣￣

std::string								LocationConf::get_port(void) const { return (this->_port); };
std::vector<std::string>				LocationConf::get_servername(void) const { return (this->_server_name); };
std::string								LocationConf::get_root(void) const {return (this->_root); };
std::vector<std::string>				LocationConf::get_indexpage_set(void) const { return (this->_indexpage_set); };
std::vector<std::string>				LocationConf::get_allowmethod_set(void) const { return (this->_allowmethod_set); };
std::map<std::string, LocationConf>		LocationConf::get_locations(void) const { return (this->_locations); };
size_t									LocationConf::get_maxBodySize(void) const { return (this->_maxBodySize); };
std::map<std::string, std::string>		LocationConf::get_errorpage_set(void) const { return (this->_errorpage_set); };
bool									LocationConf::get_chunked_transferencoding_allow(void) { return (this->_chunked_transferencoding_allow); };
std::string								LocationConf::get_accesslog(void) { return (this->_accesslog); };
std::string								LocationConf::get_errorlog(void) {return (this->_errorlog); };
size_t									LocationConf::get_keepaliverequests(void) { return (this->_keepaliverequests); };
size_t									LocationConf::get_keepalive_timeout(void) { return (this->_keepalive_timeout); };
bool									LocationConf::get_autoindex(void) { return (this->_autoindex); };
size_t									LocationConf::get_client_body_buffer_size(void) { return (this->_client_body_buffer_size); };
size_t									LocationConf::get_client_body_timeout(void) { return (this->_client_body_timeout); };
size_t									LocationConf::get_client_header_buffer_size(void) { return (this->_client_header_buffer_size); };
size_t									LocationConf::get_client_header_timeout(void) { return (this->_client_header_timeout); };
size_t									LocationConf::get_client_maxbody_size(void) { return (this->_maxBodySize); };
std::string								LocationConf::get_default_type(void) { return (this->_default_type); };
int										LocationConf::get_version(void) { return (this->_server_tokens); };
std::string								LocationConf::get_cgi_path(void) { return (this->_cgi_path); };
std::string								LocationConf::get_alias(void) { return (this->_alias); };
std::string								LocationConf::get_upload_path(void) { return (this->_upload_path); };