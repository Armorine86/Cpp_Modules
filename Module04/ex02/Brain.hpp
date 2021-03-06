/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:41:54 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/20 15:10:06 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>

#include <string>

#define N_IDEAS 100

class Brain
{
protected:
    std::string ideas[N_IDEAS];

public:
    Brain();
    Brain(const Brain& src);
    virtual ~Brain();

    Brain& operator=(const Brain& rhs);

    void        setIdea(int32_t index, std::string idea);
    std::string getIdea(int32_t index);
};
