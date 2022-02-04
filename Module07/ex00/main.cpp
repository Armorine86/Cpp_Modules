/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 18:49:48 by mmondell          #+#    #+#             */
/*   Updated: 2022/02/04 13:44:09 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main(void)
{
    {    
        int a = 1;
        int b = 10;
        
        std::cout << "a = " << a << "\nb = " << b << std::endl;
        swap(a, b);
        std::cout << "\na = " << a << "\nb = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
        std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    }

    std::cout << std::endl;
    
    {   
        std::string c = "13";
        std::string d = "12";

        std::cout << "c = " << c << "\nd = " << d << std::endl;
        swap(c, d);
        std::cout << "\nc = " << c << "\nd = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
        std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
    }

    std::cout << std::endl;
    
    {
        float a = 4.2f;
        float b = 8.7f;
        
        std::cout << "a = " << a << "\nb = " << b << std::endl;
        swap(a, b);
        std::cout << "\na = " << a << "\nb = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
        std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    }
    return 0;
}
