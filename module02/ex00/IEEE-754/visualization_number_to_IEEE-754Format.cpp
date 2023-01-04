/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:34:44 by gsever            #+#    #+#             */
/*   Updated: 2023/01/04 14:43:55 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//This area for learning how it's working IEEE-754 Fixed Point Number's working.

// C++ program to convert a real value
// to IEEE 754 floating point representation
// #include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
using namespace std;

void printBinary(int n, int i)
{

	// Prints the binary representation
	// of a number n up to i-bits.
	int k;
	for (k = i - 1; k >= 0; k--) {

		if ((n >> k) & 1)
			cout << "1";
		else
			cout << "0";
	}
}

typedef union {

	float f;
	struct
	{

		// Order is important.
		// Here the members of the union data structure
		// use the same memory (32 bits).
		// The ordering is taken
		// from the LSB to the MSB.
		unsigned int mantissa : 23;
		unsigned int exponent : 8;
		unsigned int sign : 1;

	} raw;
} myfloat;

// Function to convert real value
// to IEEE floating point representation
void printIEEE(myfloat var)
{

	// Prints the IEEE 754 representation
	// of a float value (32 bits)

	cout << var.raw.sign << " | ";
	printBinary(var.raw.exponent, 8);
	cout << " | ";
	printBinary(var.raw.mantissa, 23);
	cout << "\n";
}

// Driver Code
int main()
{

	// Instantiate the union
	myfloat var;

	// Get the real value
	var.f = -2.25;

	// Get the IEEE floating point representation
	cout << "IEEE 754 representation of ";
	cout << fixed << setprecision(6) << var.f << " is : " << endl;//precision -> kesinlik demek.
	printIEEE(var);

	return 0;
}
