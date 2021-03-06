/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:41:59 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/16 07:52:44 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Contact.hpp"

Contact::Contact() {
	contact_index = 0;
	is_active = false;
	first_name = "";
	last_name = "";
	nickname = "";
	phone_number = "";
	darkest_secret = "";
}

//* Setter method to access the Contact class private member
void Contact::SetContactIndex(int32_t index) 
{
	contact_index = index;
}

void Contact::SetActive() 
{
	is_active = true;
}

bool Contact::IsActive() 
{
	return (is_active);
}

void Contact::SetField(std::string input, std::string field) 
{
	if (field == "first_name")
		first_name = input;
	else if (field == "last_name")
		last_name = input;
	else if (field == "nickname")
		nickname = input;
	else if (field == "phone_number")
		phone_number = input;
	darkest_secret = input;
}

//* Getter method to retrieve the value of the Contact class private member
std::string& Contact::GetField(std::string const field) 
{
	if (field == "first_name")
		return (first_name);
	else if (field == "last_name")
		return (last_name);
	else if (field == "nickname")
		return (nickname);
	else if (field == "phone_number")
		return (phone_number);
	return (darkest_secret);
}

//* Truncates the string to a maximum of 10 characters replacing the last char with a "."
std::string Contact::TruncateStr(std::string field) 
{
	if (field.length() > 10)
		return (field.substr(0, 9) + ".");
	else
		return field;
}

int32_t Contact::GetContactIndex() 
{
	return (contact_index);
}
