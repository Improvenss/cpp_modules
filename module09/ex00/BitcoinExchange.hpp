/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:10:35 by gsever            #+#    #+#             */
/*   Updated: 2023/04/12 20:30:27 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <map> /* We are using std::map container, because we need to good
 algorithm for search/find. */
# include "Colors.hpp"

# define FILE_DATA_BTC "data.csv"
// # define FILE_DATA_BTC "data-small.csv"
// # define FILE_DATA_BTC "data-wrong-data-file.csv"
// # define FILE_DATA_BTC "market-price.csv"
// # define FILE_INPUT_BTC // this is argv[1].

/**
 * @brief 
 * 
 * @param _data: BTC's 'map'(container) daily values array.
 * @param _fileInput: Opening ./btc input.txt file.
 * @param _lineReaded: Keeps a readed line from input.txt in memory.
 * 
 * FUNCTIONS:
 * 	MAIN:
 * @fn runBTCExchange(): Main func(), all calculate operations in here.
 * 	CHECK:
 * @fn checkFileInput(): Checking data.csv's inside parameters are correct.
 * 
 */
class BitcoinExchange
{
	private:
		std::map<std::string, float>	_data;
		std::fstream					_fileInput;
		std::fstream					_fileData;
		std::string						_lineReaded;
		char							_fileSeperatorInput;
		char							_fileSeperatorData;
		float							_fileInputValue;
	public:
		BitcoinExchange( void ); // Default Constructor. (We are not using this.)
		BitcoinExchange( char *inputFilePath ); // File Path Constructor.
		~BitcoinExchange( void ); // Destructor.

/* _________________________ MAIN FUCTION ___________________________________ */

		void	runBTCExchange( void );
/* -------------------------------------------------------------------------- */
/* _________________________ SET/GET FUNCTIONS ______________________________ */

		void	setFileData( void );
		void	setFileSeperator( std::fstream &file, char &seperator );
/* -------------------------------------------------------------------------- */
/* _________________________ IF FUNCTIONS ___________________________________ */

/* -------------------------------------------------------------------------- */
/* _________________________ CHECK FUNCTIONS ________________________________ */

		bool	checkFileData( void );
		bool	checkFileInput( char *inputFilePath );
		bool	checkFileInputValues( std::string dateStr,\
			std::string valueStr );
/* -------------------------------------------------------------------------- */
/* _________________________ PRINT FUCTIONS _________________________________ */

		void	printArray( void );
		void	printEvaluatedInput( std::string dateStr );
/* -------------------------------------------------------------------------- */

};

#endif // BITCOINEXCHANGE_HPP