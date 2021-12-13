/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:16:00 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/12 20:02:28 by mmondell         ###   ########.fr       */
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
	 	std::string levels[4];
	
	public:
		Karen();
		void complain(std::string level);
};
