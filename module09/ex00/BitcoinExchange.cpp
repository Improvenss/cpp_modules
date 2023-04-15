/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:15:43 by gsever            #+#    #+#             */
/*   Updated: 2023/04/12 21:02:24 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( void )
{
}

/**
 * @brief Construct a new Bitcoin Exchange:: Bitcoin Exchange object
 * 
 * @note Trying to open inputFilePath, if opening successfully;
 *  Initializing BitcoinExchange class's member variables(readFile, data, etc.).
 * 
 * @note inputFile still open! Don't forget.
 * 
 * @param inputFilePath 
 */
BitcoinExchange::BitcoinExchange( char *inputFilePath )
{
	try
	{
		this->checkFileInput(inputFilePath);
		if (this->checkFileData()) // Checking data.csv are okay.
			this->setFileData(); // Setting data.csv's values to _data.
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << END\
			<< std::flush << std::endl;
	}
	
}

BitcoinExchange::~BitcoinExchange( void )
{
}
/* _________________________ MAIN FUCTION ___________________________________ */

/**
 * @brief Main calculating and printing func().
 * 
 * @note std::istringstream
 * @link https://cplusplus.com/reference/sstream/istringstream/istringstream/
 * 
 */
void	BitcoinExchange::runBTCExchange( void )
{
	try
	{
		std::string	dateStr;
		std::string	valueStr;

		this->setFileSeperator(this->_fileInput, this->_fileSeperatorInput);
		std::cout << "Seperator (input): " << this->_fileSeperatorInput\
			<< std::flush << std::endl;
		std::getline(this->_fileInput, this->_lineReaded);
		while (std::getline(this->_fileInput, this->_lineReaded)) // input.txt'nin icindeki veriyi satir satir aliyoruz.
		{
			std::stringstream	ss(this->_lineReaded);
			std::getline(ss, dateStr, this->_fileSeperatorInput);
			if (!std::getline(ss, valueStr))
			{
				std::cerr << "Error: bad input => " << dateStr\
					<< std::flush << std::endl;
				continue;
			}
			dateStr.pop_back(); // Deleting last character ' ' (space).
			valueStr.erase(valueStr.begin()); // Deleting first character ' ' (space).
			// std::cout << "Str: [" << dateStr << "] [" << valueStr << "]"\
			// 	<< std::flush << std::endl;
			if (this->checkFileInputValues(dateStr, valueStr))
				this->printEvaluatedInput(dateStr);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << RED "Error: " << e.what() << END\
			<< std::flush << std::endl;
	}
}
/* -------------------------------------------------------------------------- */
/* _________________________ SET/GET FUNCTIONS ______________________________ */

/**
 * @brief Readed FILE_DATA_BTC file's inside, writed std::map<> array.
 * 
 * @note How can i add std::map<> inside value?
 * @link https://www.geeksforgeeks.org/map-insert-in-c-stl/
 * 
 */
void	BitcoinExchange::setFileData( void )
{
	try
	{
		std::string	dateStr;
		std::string	rateStr;

		this->setFileSeperator(this->_fileData, this->_fileSeperatorData);
		std::cout << "Seperator (data): " << this->_fileSeperatorData\
			<< std::flush << std::endl;
		while (std::getline(this->_fileData, this->_lineReaded))
		{
			std::stringstream	ss(this->_lineReaded);
			std::getline(ss, dateStr, this->_fileSeperatorData);
			std::getline(ss, rateStr);
			this->_data[dateStr] = std::stof(rateStr);
		}
		// this->printArray();
		// BitcoinExchange::printArray();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED "Error: " << e.what() << END\
			<< std::flush << std::endl;
	}
}

/**
 * @brief Getting parameter's inside file seperator.
 * 
 * @param file&: Searching file.
 * @param seperator&: Setted found seperator.
 */
void	BitcoinExchange::setFileSeperator( std::fstream &file, char &seperator )
{
	// std::getline(file, this->_lineReaded);
	// std::cout << "Seperator Line: " << this->_lineReaded\
	// 	<< std::flush << std::endl;
	if (std::getline(file, this->_lineReaded))
	{
		std::cout << "Seperator Line: " << this->_lineReaded\
			<< std::flush << std::endl;
		if (this->_lineReaded.find(',') != std::string::npos)
			seperator = ',';
		else if (this->_lineReaded.find('|') != std::string::npos)
			seperator = '|';
		else if (this->_lineReaded.find(';') != std::string::npos)
			seperator = ';';
		else
			throw (std::string("Error: Seperator not found!"));
	}
	this->_fileInput.seekg(0, this->_fileInput.beg); // Setting last readed location to first location.
}
/* -------------------------------------------------------------------------- */
/* _________________________ CHECK FUNCTIONS ________________________________ */

/**
 * @brief Checking data.csv's can open!
 * 
 * @return void;
 */
bool	BitcoinExchange::checkFileData( void )
{
	this->_fileData.open(FILE_DATA_BTC, std::fstream::in | std::fstream::out);
	if (this->_fileData.fail())
		throw (std::ios_base::failure("Error: could not open file["\
			FILE_DATA_BTC "]"));
	else if (this->_fileData.is_open())
	{
		std::cout << B_GREEN FILE_DATA_BTC " checked, file open. OK!" END\
			<< std::flush << std::endl;
		return (true);
	}
	return (false);
}

/**
 * @brief Checking input.txt's can open!
 * 
 * @param inputFilePath 
 * @return true 
 * @return false 
 */
bool	BitcoinExchange::checkFileInput( char *inputFilePath )
{
	this->_fileInput.open(inputFilePath, std::fstream::in | std::fstream::out); // Checking input.txt are okay.
	if (this->_fileInput.fail())
		throw (std::ios_base::failure("Error: could not open file["\
			+ (std::string)inputFilePath + "]."));
	else if (this->_fileInput.is_open())
	{
		std::cout << B_GREEN << (std::string)inputFilePath\
			+ " checked, file open. OK!" END << std::flush << std::endl;
		return (true);
	}
	return (false);
}

/**
 * @brief Checking values are okay.
 * 
 * @param dataStr 
 * @param valueStr 
 * @return true 
 * @return false 
 */
bool	BitcoinExchange::checkFileInputValues( std::string dataStr,
	std::string valueStr )
{
	try
	{
		(void)dataStr;
		this->_fileInputValue = std::stof(valueStr);
		if (this->_fileInputValue < 0)
		{
			std::cerr << "Error: not a positive number."\
				<< std::flush << std::endl;
			return (false);
		}
		else if (this->_fileInputValue > 1000)
		{
			std::cerr << "Error: too large a number."\
				<< std::flush << std::endl;
			return (false);
		}
		return (true);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::flush << std::endl;
	}
	return (true);
}
/* -------------------------------------------------------------------------- */
/* _________________________ PRINT FUCTIONS _________________________________ */

/**
 * @brief Printing created std::map's all values.
 */
void	BitcoinExchange::printArray( void )
{
	std::map<std::string, float>::iterator	it = this->_data.begin();
	// std::map<std::string, float>::iterator	itFirst = this->_data.lower_bound();
	for (; it != this->_data.end(); it++) // printing setted data from data.csv
	{
		std::cout << "SET: itFirst: " << it->first << "\titSecond: "\
			<< it->second << std::flush << std::endl;
	}
}

/**
 * @brief Evaluating input.txt's current value.
 * 
 * @param dateStr 
 * 
 * @fn std::map::lower_bound(): Getting lower bound this date.
 * @note Since C++98.
 * @link https://en.cppreference.com/w/cpp/container/map/lower_bound
 */
void	BitcoinExchange::printEvaluatedInput( std::string dateStr )
{
	// std::map<std::string, float>::iterator	it = this->_data.begin();
	std::map<std::string, float>::iterator	it = this->_data.lower_bound(dateStr);

	if (it == this->_data.end()) // Date is after the last date in this->_data.
		--it;
	else if (it == this->_data.begin() && dateStr < it->first) // Date is before the earliest date in this->_data.
	{
		std::cerr << "Error: date " << dateStr\
			<< " is prior to the creation of Bitcoin"\
			<< std::flush << std::endl;
		return ;
	}
	else if (dateStr < it->first) // Date is between two dates in this->_data.
		--it;
	// Date is in this->_data.
	std::cout << dateStr << " => " << this->_fileInputValue << " = " // This dateStr -> it->first but we need to see output like input.txt.
		<< it->second * this->_fileInputValue << std::flush << std::endl;
}
/* -------------------------------------------------------------------------- */