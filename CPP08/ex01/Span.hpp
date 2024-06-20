/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:52:59 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/20 17:59:32 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>

class Span
{
    private:
        unsigned int N;
    public:
        Span();
        Span(unsigned int);
        Span(Span &);
        Span& operator=(Span &);
        ~Span();
        void addNumber(unsigned int);
        void shortestSpan();
        void longestSpan();
        class noSpan : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif
