/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SameportConf.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 21:23:41 by user              #+#    #+#             */
/*   Updated: 2023/07/21 23:38:26 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SameportConf_HPP
#define SameportConf_HPP

#include <string>
#include <vector>
#include <map>

#include "LocationConf.hpp"

class LocationConf;

class SameportConf
{
	private:
		std::string								_port;
		std::vector<std::string>				_server_name;
		std::string								_root;
		std::vector<std::string>				_indexpage_set;
		std::vector<std::string>				_allowmethod_set;
		std::map<int, std::string>				_location_rank;
		std::map<std::string, LocationConf>		_locations;
		size_t 									_maxBodySize;
		std::map<std::string, std::string> 		_errorpage_set;//これめっちゃおかしい使い方できる　error_page 403 404 500 503 =404 /custom_404.html;
		bool									_chunked_transferencoding_allow;
		std::string								_accesslog;
		std::string								_errorlog;
		size_t									_keepaliverequests;
		size_t									_keepalive_timeout;
		int										_server_tokens;
		bool									_autoindex;
		size_t									_client_body_buffer_size;
		size_t									_client_body_timeout;
		size_t									_client_header_buffer_size;
		size_t									_client_header_timeout;
		size_t									_client_maxbody_size;
		std::string								_default_type;

	public:
		SameportConf();
		~SameportConf();

		void									reset_contents();

		void									set_port(std::string const &port);
		void									set_servername(std::vector<std::string> const &server_name);
		void									set_root(std::string const &root);
		void									set_indexpage_set(std::vector<std::string> const &root);
		void									set_allowmethod_set(std::vector<std::string> const &root);
		void									set_locations(std::string const &key, LocationConf const &locationconf);
		void									set_location_rank(int const &rank, std::string const &str);
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

		std::string								get_port(void) const;
		std::vector<std::string>				get_servername(void) const;
		std::string								get_root(void) const;
		std::vector<std::string>				get_indexpage_set(void) const;
		std::vector<std::string>				get_allowmethod_set(void) const;
		std::map<std::string, LocationConf>		get_locations(void) const;
		std::map<int, std::string>				get_location_rank(void) const;
		size_t									get_maxBodySize(void) const;
		std::map<std::string, std::string>		get_errorpage_set(void) const;
		bool									get_chunked_transferencoding_allow(void) const;
		std::string								get_accesslog(void) const;
		std::string								get_errorlog(void) const;
		size_t									get_keepaliverequests(void) const;
		size_t									get_keepalive_timeout(void) const;
		bool									get_autoindex(void) const;
		size_t									get_client_body_buffer_size(void) const;
		size_t									get_client_body_timeout(void) const;
		size_t									get_client_header_buffer_size(void) const;
		size_t									get_client_header_timeout(void) const;
		size_t									get_client_maxbody_size(void) const;
		std::string								get_default_type(void) const;
		int										get_version(void) const;
};

#endif