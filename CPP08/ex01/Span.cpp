/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:59:33 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/20 17:59:45 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
    this->N = 10;
}

Span::Span(unsigned int number)
{
    this->N = number;
}

Span::Span(Span &other)
{
    this->N = other.N;
}

Span& Span::operator=(Span &other)
{
    if (this != &other)
        this->N = other.N;
    return *this;
}

Span::~Span()
{
}

const char* Span::noSpan::what() const throw()
{
    return ("There are not numbers/Only one number found");
}
