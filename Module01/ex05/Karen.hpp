/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:16:00 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/12 09:07:20 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Karen {
	
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
	
	public:
	 	//* array of pointers to function of class Karen.
		void (Karen::*fncPtr[4])(void);
		void complain(std::string level);
};
