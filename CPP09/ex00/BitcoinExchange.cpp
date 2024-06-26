/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:40:07 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/26 16:22:35 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange &other)
{
    this->btc = other.btc;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange &other)
{
    if (this != &other)
        this->btc = other.btc;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const std::string &db, const std::string &input)
{
    std::ifstream data, file;

    data.open(db.c_str());
    file.open(input.c_str());
    if (data.fail() || file.fail())
    { 
        std::cout << "[Error] File not found" << std::endl;
        exit (1);
    }
    this->processData(file, data);
}

static void saveDt(std::string &line, BitcoinExchange &bt)
{
    int i;
    i = line.find(",");
    
    std::string lineDate;
    lineDate = line.substr(0, i);

    double lineValue;
    lineValue = atof((line.substr(i + 1, line.length() - (i + 1))).c_str());
    
    bt.createNode(lineDate, lineValue);
}

static bool isValidDay(int month, int day, int year)
{
    if (day <= 0)
        return false;
    switch(month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (day > 31)
                return false;
            break ;
        case 4:
        case 6:
        case 9:
        case 11:
            if (day > 30)
                return false;
            break ;  
        case 2:
            if (year % 400 == 0 || (year % 4 == 0 && (year % 100 != 0)))
            {
				if (day > 29)
					return false;
            }
			else
				if (day > 28)
					return false;
			break ;
        default:
            return false;
            break ;
    }
    return true;
}

static void isValidDate(std::string &lineDate)
{
    int i, year, day, month;
    
    i = lineDate.find("-", 0);
    if (i != -1)
    {
        year = atoi(lineDate.substr(0, i).c_str());
        if (year < 2009)
            throw(BitcoinExchange::badDate());
        lineDate.erase(0, i + 1);
        i = lineDate.find("-", 0);
        if (i != -1)
        {
            month = atoi(lineDate.substr(0, i).c_str());
            if (month <= 0 || month > 12)
                throw(BitcoinExchange::badDate());
            lineDate.erase(0, i + 1);
            day = atoi(lineDate.c_str());
            if (!isValidDay(month, day, year))
                throw(BitcoinExchange::badDate());
        }
    }
}

static void	saveFileEntry(std::string &strToCheck, BitcoinExchange &btcEx)
{
	double		numValue;
	std::string dateStr;
	std::string valueStr;
	int			j;

	(void)btcEx;
	if (strToCheck == "date | value")
		return ;
	try
	{
		j = strToCheck.find(" | ", 0);
		if (j != -1)
		{
			dateStr = strToCheck.substr(0, j);
			valueStr = strToCheck.substr(j + 3);
			 std::cout << dateStr << std::endl;
			numValue = atof(valueStr.c_str());
			isValidDate(dateStr);
			if (numValue >= 1000 || (numValue == 0.0 && (valueStr != "0.0" || valueStr != "0")))
			{
				throw(BitcoinExchange::outOfRange());
			}
			if (numValue < 0.0)
				throw(BitcoinExchange::negativeValue());
			std::cout << dateStr << std::endl;
			btcEx.obtainDbValue(dateStr, numValue);
		}
		else
			throw(BitcoinExchange::badDate());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

void BitcoinExchange::processData(std::ifstream &file, std::ifstream &data)
{
    std::string line;

    (void)file;
    while (data.good())
    {
        std::getline(data, line);
        saveDt(line, *this);
        //std::cout << line << "\n"; //comprobacion de que guarda las lineas bien
    }
    while (file.good())
    {
        std::getline(file, line);
        saveFileEntry(line, *this);
    }
}

void BitcoinExchange::createNode(std::string &lineDate, double &lineValue)
{
    this->btc.insert(std::pair<std::string, double>(lineDate, lineValue));
}

void BitcoinExchange::obtainDbValue(std::string &lineDate, double &numericValue)
{
    std::map<std::string, double>::iterator it = this->btc.begin();
	try
	{
		if (lineDate < it->first)
			throw (BitcoinExchange::notFound());
		it = this->btc.lower_bound(lineDate);
		if (it != btc.begin())
		{
			if (it->first != lineDate)
				it--;
			std::cout << lineDate << " ==> " << numericValue;
	        std::cout << " = " << numericValue * it->second << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl; 
	}
}
