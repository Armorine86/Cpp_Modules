/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 09:42:11 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/01 09:43:37 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Data {

public:
	Data();
	Data(Data& src);
	~Data() {}
	Data& operator=(Data& rhs);

	int Integer;
	char c;
	double Double;
};
