/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 08:44:38 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/08 10:58:51 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <stdint.h>
#include <stdbool.h>

class Contact {
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
		int32_t	contact_index;
		bool	is_active;

	public:
		Contact();
		std::string& GetField(std::string field);
		std::string TruncateStr(std::string field);
		void	SetField(std::string input, std::string field);
		void	SetContactIndex(int32_t index);
		void	SetActive();
		bool	IsActive();
};

#endif