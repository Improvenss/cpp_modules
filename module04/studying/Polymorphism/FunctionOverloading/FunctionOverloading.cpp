/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FunctionOverloading.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 22:22:26 by gsever            #+#    #+#             */
/*   Updated: 2023/02/28 22:42:25 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file FunctionOverloading.cpp
 * @author Görkem SEVER (gsever)
 * @brief This file created ChatGPT Feb 13 Version.
 * @version 0.1
 * @date 2023-02-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>

using namespace std;

void print(int i) {
    cout << "Printing integer: " << i << endl;
}

void print(double f) {
    cout << "Printing float: " << f << endl;
}

void print(string s) {
    cout << "Printing string: " << s << endl;
}

/**
 * @brief Function Overloading
 * 
	Function overloading is the ability to define multiple functions with
	 the same name but different parameters.
	The compiler determines which function to call based on the
	 number, types, and order of the arguments.
 * 
 * @return int 
 */
int main() {
    int a = 5;
    double b = 5.5;
    string c = "Hello, world!";

    print(a);
    print(b);
    print(c);

    return 0;
}

/**
 * @brief 
 * 
	In the above code, we have defined three functions with
	 the same name "print", but different parameters.
	Depending on the data type of the argument passed to the function,
	 the corresponding function is called.
	This is an example of function overloading, which is a form of
	 static polymorphism because the decision of which function to call
	 is made at compile-time.
 * 
 */