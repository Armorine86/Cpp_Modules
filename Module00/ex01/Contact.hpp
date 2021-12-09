/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 08:44:38 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/09 16:00:53 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <stdint.h>
#include <stdbool.h>

//* Class definition
class Contact {
	
	//* By default access to members of a C++ class is private.
	//* The private members are not accessible outside the class 
	//* they can be accessed only through methods of the class.
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
		int32_t	contact_index;
		bool	is_active;

	public:
		//* Methods are functions that belongs to the class.
		//* They can access private members and can be called
		//* from any objects from the same Class.
		
		//* Constructor are called everytime an object is instanciated.
		//* You can have several Constructor which each takes a different amount of parameters (to avoid conflicts) 
		Contact(); //* Constructor
		std::string& GetField(std::string field);
		std::string TruncateStr(std::string field);

		//* The meaning of Encapsulation, is to make sure that "sensitive" data is hidden from users.
		//* you must declare class variables/attributes as private (cannot be accessed from outside the class).
		//* If you want others to read or modify the value of a private member, you can provide public get and set methods.
		int32_t	GetContactIndex();
		void	SetField(std::string input, std::string field);
		void	SetContactIndex(int32_t index);
		void	SetActive();
		bool	IsActive();
};

#endif
