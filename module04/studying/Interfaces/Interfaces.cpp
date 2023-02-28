/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interfaces.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 21:47:19 by gsever            #+#    #+#             */
/*   Updated: 2023/02/28 21:58:07 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file Interfaces.cpp
 * @author Görkem SEVER (gsever)
 * @brief This file created ChatGPT Feb 13 Version.
 * @version 0.1
 * @date 2023-02-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>

/**
 * @brief 
 * 
	In C++, an interface is a class that contains only pure virtual functions,
	 with no implementation.
	A pure virtual function is a function declared with the virtual keyword
	 and set to 0.
	It's a way to specify a function in a base class that must be implemented
	 in any derived classes.
	Here's an example of how to declare an interface in C++:
 */
class Shape {
public:
    virtual double area() const = 0; // pure virtual function
    virtual double perimeter() const = 0; // pure virtual function
};

////////////////////////////////////////////////////////////////////////

/**
 * @brief 
 * 
 * In this example,
 * 	Shape is an interface with two pure virtual functions: area() and perimeter().
 * Any class that inherits from Shape must implement these functions,
 *  or else it will also be an abstract class.
 * 
 * 	Let's say we want to create a Rectangle class that inherits from Shape.
 * Here's an example implementation:
 * 
 */
class Rectangle : public Shape {
private:
    double length_;
    double width_;
public:
    Rectangle(double length, double width) : length_(length), width_(width) {}
    double area() const override { return length_ * width_; }
    double perimeter() const override { return 2 * (length_ + width_); }
};

////////////////////////////////////////////////////////////////////////

/**
 * @brief 
 * 
 * In this example, Rectangle inherits from Shape and provides
 *  implementations for both area() and perimeter().
 * We can now create instances of Rectangle and call the interface
 *  functions on them:
 * 
 */
int	main()
{
	Rectangle r(3, 4);
	std::cout << "Area: " << r.area() << std::endl; // prints "Area: 12"
	std::cout << "Perimeter: " << r.perimeter() << std::endl; // prints "Perimeter: 14"
}

/**
 * @brief 
	Using interfaces like this can be useful for creating a consistent
	 interface across different classes.
	For example, we could create other classes that inherit from Shape,
	 like Circle or Triangle, and use them interchangeably in functions
	  that expect a Shape object.
 */