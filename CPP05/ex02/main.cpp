/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nekane <nekane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:54:59 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/12 14:06:27 by nekane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	Bureaucrat nose("nosw", 12);
	Bureaucrat nose2("nose2", 12);
	ShrubberyCreationForm prueba1("prueba");
	RobotomyRequestForm prueba2("prueba2");

	std::cout << prueba1;
	std::cout << prueba2;

	//prueba1.execute(nose);
	prueba2.execute(nose);
	prueba2.execute(nose2);

	return 0;

}