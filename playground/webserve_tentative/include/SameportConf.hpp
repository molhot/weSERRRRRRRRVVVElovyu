/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SameportConf.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 21:23:41 by user              #+#    #+#             */
/*   Updated: 2023/07/19 00:01:37 by user             ###   ########.fr       */
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
		std::map<std::string, std::string> 		_errorpage_set;//これめっちゃおかしい使い方できる　error_page 403 404 500 503 =404 /custom_404.html;
		bool									_chunked_transferencoding_allow;
		std::string								_accesslog;
		std::string								_errorlog;
		size_t									_keepaliverequests;
		size_t									_keepalive_timeout;
		const int								_server_tokens = 1;
		std::string								_autoindex;
		size_t									_client_body_buffer_size;
		size_t									_client_body_timeout;
		size_t									_client_header_buffer_size;
		size_t									_client_header_timeout;
		size_t									_client_maxbody_size;
		std::string								_default_type;

	public:
		SameportConf();
		~SameportConf();

		void									set_port(std::string const &port);
		void									set_servername(std::string const &server_name);
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
		void									set_autoindex(std::string const &on_off);
		void									set_client_body_buffer_size(size_t const &buffersize);
		void									set_client_body_timeout(size_t const &timeout);
		void									set_client_header_buffer_size(size_t const &buffersize);
		void									set_client_header_timeout(size_t const &timeout);
		void									set_client_maxbody_size(size_t const &buffersize);
		void									set__default_type(std::string const &default_type);

		std::string								get_port(void) const;
		std::string								get_servername(void) const;
		std::string								get_root(void) const;
		std::vector<std::string>				get_indexpage_set(void) const;
		std::vector<std::string>				get_allowmethod_set(void) const;
		std::map<std::string, LocationConf>		get_locations(void) const;
		size_t									get_maxBodySize(void) const;
		std::map<std::string, std::string>		get_errorpage_set(void) const;
		bool									get_chunked_transferencoding_allow(bool const &allow_or_not);
		std::string								get_accesslog(std::string const &access_log);
		std::string								get_errorlog(std::string const &access_log);
		size_t									get_keepaliverequests(size_t const &max_requests);
		size_t									get_keepalive_timeout(size_t const &timeout);
		std::string								get_autoindex(std::string const &on_off);
		size_t									get_client_body_buffer_size(size_t const &buffersize);
		size_t									get_client_body_timeout(size_t const &timeout);
		size_t									get_client_header_buffer_size(size_t const &buffersize);
		size_t									get_client_header_timeout(size_t const &timeout);
		size_t									get_client_maxbody_size(size_t const &buffersize);
		std::string								get__default_type(std::string const &default_type);
};

#endif