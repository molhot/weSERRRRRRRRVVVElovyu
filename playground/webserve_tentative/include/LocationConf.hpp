/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LocationConf.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 21:47:46 by user              #+#    #+#             */
/*   Updated: 2023/07/21 19:57:40 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LocationConf_HPP
#define LocationConf_HPP

#include <string>
#include <map>
#include <vector>

#include "SameportConf.hpp"

class SameportConf;

class LocationConf
{
	private:
		std::string								_port;
		std::vector<std::string>				_server_name;
		std::string								_root;
		std::string								_alias;
		std::vector<std::string>				_indexpage_set;
		std::vector<std::string>				_allowmethod_set;
		std::map<std::string, LocationConf>		_locations;
		size_t 									_maxBodySize;
		std::map<std::string, std::string> 		_errorpage_set;//これめっちゃおかしい使い方できる　error_page 403 404 500 503 =404 /custom_404.html;
		bool									_chunked_transferencoding_allow;
		std::string								_accesslog;
		std::string								_errorlog;
		size_t									_keepaliverequests;
		size_t									_keepalive_timeout;
		const int								_server_tokens;
		bool									_autoindex;
		size_t									_client_body_buffer_size;
		size_t									_client_body_timeout;
		size_t									_client_header_buffer_size;
		size_t									_client_header_timeout;
		size_t									_client_maxbody_size;
		std::string								_default_type;
		std::string								_cgi_path;
		std::string								_upload_path;

	public:
		LocationConf();
		LocationConf(SameportConf const &some);
		~LocationConf();

		void									set_port(std::string const &port);
		void									set_servername(std::vector<std::string> const &server_name);
		void									set_root(std::string const &root);
		void									set_indexpage_set(std::vector<std::string> const &root);
		void									set_allowmethod_set(std::vector<std::string> const &root);
		void									set_locations(std::map<std::string, LocationConf> const &root);
		void									set_maxBodySize(size_t const &root);
		void									set_errorpage_set(std::map<std::string, std::string> const &root);
		void									set_chunked_transferencoding_allow(bool const &allow_or_not);
		void									set_accesslog(std::string const &access_log);
		void									set_errorlog(std::string const &access_log);
		void									set_keepaliverequests(size_t const &max_requests);
		void									set_keepalive_timeout(size_t const &timeout);
		void									set_autoindex(bool const &on_off);
		void									set_client_body_buffer_size(size_t const &buffersize);
		void									set_client_body_timeout(size_t const &timeout);
		void									set_client_header_buffer_size(size_t const &buffersize);
		void									set_client_header_timeout(size_t const &timeout);
		void									set_client_maxbody_size(size_t const &buffersize);
		void									set_default_type(std::string const &default_type);
		void									set_cgi_path(std::string const &default_type);
		void									set_alias(std::string const &alias);
		void									set_upload_path(std::string const &upload_path);


		std::string								get_port(void) const;
		std::vector<std::string>				get_servername(void) const;
		std::string								get_root(void) const;
		std::vector<std::string>				get_indexpage_set(void) const;
		std::vector<std::string>				get_allowmethod_set(void) const;
		std::map<std::string, LocationConf>		get_locations(void) const;
		size_t									get_maxBodySize(void) const;
		std::map<std::string, std::string>		get_errorpage_set(void) const;
		bool									get_chunked_transferencoding_allow(void);
		std::string								get_accesslog(void);
		std::string								get_errorlog(void);
		size_t									get_keepaliverequests(void);
		size_t									get_keepalive_timeout(void);
		bool									get_autoindex(void);
		size_t									get_client_body_buffer_size(void);
		size_t									get_client_body_timeout(void);
		size_t									get_client_header_buffer_size(void);
		size_t									get_client_header_timeout(void);
		size_t									get_client_maxbody_size(void);
		std::string								get_default_type(void);
		int										get_version(void);
		std::string								get_cgi_path(void);
		std::string								get_alias(void);
		std::string								get_upload_path(void);
};

#endif