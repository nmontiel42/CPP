/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:28:28 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/26 16:05:21 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <map>
# include <exception>
# include <cstdlib>
# include <vector>

class BitcoinExchange
{
    private:
        std::map<std::string, double> btc;
    public:
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange &);
        BitcoinExchange(const std::string &, const std::string &);
        BitcoinExchange& operator=(BitcoinExchange &);
        ~BitcoinExchange();
        void processData(std::ifstream &, std::ifstream &);
        void createNode(std::string &, double &);
        void obtainDbValue(std::string &, double &);
        class badDate : public std::exception
        {
            const char* what() const throw() {
                return ("Bad date input");
            }
        };
        class outOfRange : public std::exception
        {
            const char* what() const throw() {
                return ("Value out of range");
            }
        };
        class negativeValue : public std::exception
        {
            const char* what() const throw() {
                return ("Negative value");
            }
        };
        class notFound : public std::exception
        {
            const char* what() const throw() {
                return ("Data not found");
            }
        };
};

#endif