/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:01:57 by gsever            #+#    #+#             */
/*   Updated: 2023/03/19 22:27:21 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

void	checkLeaks( void )
{
	std::cout << B_GREEN "Leaks: " << std::flush;
	system("leaks Array | grep 'leaked bytes'");
	std::cout << END << std::flush;
}

template<typename ehe>
void	templateArrayTest( ehe &typeTemplate, std::string typeString)
{
	if (typeString == "Char")
		for (unsigned int i = 0; i < typeTemplate.getSize(); i++)
			typeTemplate[i] = i + 65;
	else if (typeString == "Float")
		for (unsigned int i = 0; i < typeTemplate.getSize(); i++)
			typeTemplate[i] = i + 65.2f;
	else if (typeString == "Double")
		for (unsigned int i = 0; i < typeTemplate.getSize(); i++)
			typeTemplate[i] = i + 65.5;
	else
		for (unsigned int i = 0; i < typeTemplate.getSize(); i++)
			typeTemplate[i] = i;
	// else if (typeString == "Str")
	// 	for (unsigned int i = 0; i < typeTemplate.getSize(); i++)
	// 		typeTemplate[i] = typeString;
	std::cout << "array" + typeString + "(" << typeTemplate.getSize() << ")	: "\
		<< END << typeTemplate << std::flush << std::endl;
}

int	main()
{
	// Array<>	arrayTest;
	// Array<char>			arrayTest;
	Array<int>			arrayInt(7);
	Array<char>			arrayChar(5);
	Array<float>		arrayFloat(3);
	Array<double>		arrayDouble(5);
	Array<std::string>	arrayString(4);
	// Array<char*>		arrayStr(4); // This is not working, why idk?

	std::cout << B_BLUE "------------ Arrays Created! --------------" END\
		<< std::flush << std::endl;
	// checkLeaks();

	// templateArrayTest(arrayTest, "");
	templateArrayTest(arrayInt, "Int");
	// checkLeaks();
	templateArrayTest(arrayChar, "Char");
	// checkLeaks();
	templateArrayTest(arrayFloat, "Float");
	// checkLeaks();
	templateArrayTest(arrayDouble, "Double");
	// checkLeaks();
	templateArrayTest(arrayString, "String");
	// checkLeaks();
	// templateArrayTest(arrayStr, "Str");

	try
	{
		std::cout << "Accessing element's a valid index: " << arrayInt[5]\
			<< std::flush << std::endl;
		std::cout << "Accessing element's an invalid index: " << arrayInt[234]\
			<< std::flush << std::endl;
		std::cout << "Accessing element's a valid index: " << arrayInt[6]\
			<< std::flush << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	// for (unsigned int i = 0; i < arrayInt.getSize(); i++)
	// 	arrayInt[i] = i;
	// std::cout << "arrayInt(7): " << arrayInt << std::flush << std::endl;

	// for (unsigned int i = 0; i < arrayChar.getSize(); i++)
	// 	arrayChar[i] = i + 65;
	// std::cout << "arrayChar(5): " << arrayChar << std::flush << std::endl;

	// for (unsigned int i = 0; i < arrayDouble.getSize(); i++)
	// 	arrayDouble[i] = i + 65.5;
	// std::cout << "arrayDouble(5): " << arrayDouble << std::flush << std::endl;
	std::cout << B_BLUE "------------ Arrays Clearing !-------------" END\
		<< std::flush << std::endl;
	// checkLeaks();
	return (0);
}