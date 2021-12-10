/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:04:08 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/09 20:55:33 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#pragma once

class Weapon {

	private:
		std::string wep_type;

	public:
		Weapon();
		Weapon(const std::string& type);
		void setType(const std::string type);
		const std::string& getType() const;
};
