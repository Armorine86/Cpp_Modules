/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:08:30 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/08 11:07:37 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include <stdint.h>

#include "Contact.hpp"

#define N_CONTACT 8

class Phonebook {
	private:
		Contact contact[N_CONTACT];
		int32_t	count;

	public:
		Phonebook();
		int32_t	GetCount();
		bool VerifyInput(std::string input);
		void ExpandContact(int32_t index);
		void add_contact();
		void list_contact();
};

#endif
