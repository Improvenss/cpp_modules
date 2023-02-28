/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ALL.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 22:33:51 by gsever            #+#    #+#             */
/*   Updated: 2023/02/28 22:41:40 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ALL.cpp
 * @author Görkem SEVER (gsever)
 * @brief This file created ChatGPT Feb 13 Version.
 * @version 0.1
 * @date 2023-02-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>

class Shape {
public:
    virtual double area() = 0; // pure virtual function
    virtual double perimeter() = 0; // pure virtual function
    virtual void draw() {}; // virtual function with implementation
};

class Circle : public Shape {
public:
    double area() override { return radius * radius * 3.14; } // override virtual function
    double perimeter() override { return 2 * radius * 3.14; } // override virtual function
private:
    double radius;
};

class Rectangle : public Shape {
public:
    double area() override { return width * height; } // override virtual function
    double perimeter() override { return 2 * (width + height); } // override virtual function
private:
    double width;
    double height;
};

class Printable {
public:
    virtual void print() = 0; // pure virtual function
};

class PrintableCircle : public Circle, public Printable {
public:
    void print() override { std::cout << "Circle with radius " << radius << std::endl; } // override pure virtual function
};

/**
 * @brief 
 * 
		Abstract Class:
	An abstract class is a class that cannot be instantiated.
	It is used as a base class for other classes to inherit from.
	An abstract class typically contains at least one pure virtual function,
	 which is a virtual function that has no implementation in the base class.
	An abstract class can have both virtual and non-virtual functions with implementations.
	The main purpose of an abstract class is to provide an interface for
	 its derived classes.

		Virtual Functions:
	Virtual functions are functions that can be overridden in a derived class.
	A virtual function is declared in the base class with the keyword "virtual".
	When a virtual function is called on a derived class object,
	 the overridden function in the derived class is called
	 instead of the base class function.
	This allows for dynamic binding of functions at runtime.

		Pure Virtual Functions:
	A pure virtual function is a virtual function that has no implementation
	 in the base class.
	It is declared with the keyword "virtual" and "= 0".
	A pure virtual function must be overridden in any derived class that
	 instantiates the class.
	Pure virtual functions are used to create abstract classes.

		Interfaces:
	An interface is a class that contains only pure virtual functions.
	It is used to define a set of methods that must be implemented by any
	 class that inherits from the interface.
	In C++, an interface is created using an abstract class that contains
	 only pure virtual functions.
	Interfaces are used to achieve polymorphism, where a single function
	 can work with objects of multiple classes that implement the same interface.

	Here's an example code snippet to illustrate the use of these concepts in C++:
 * 
 * @return int 
 */
int main() {
    Shape* shapePtr = new Circle();
    std::cout << "Area: " << shapePtr->area() << std::endl;
    std::cout << "Perimeter: " << shapePtr->perimeter() << std::endl;
    shapePtr = new Rectangle();
    std::cout << "Area: " << shapePtr->area() << std::endl;
    std::cout << "Perimeter: " << shapePtr->perimeter() << std::endl;
    Printable* printablePtr = new PrintableCircle();
    printablePtr->print();
    return 0;
}

/**
 * @brief 
 * 
	In this example, the Shape class is an abstract class with
	 two pure virtual functions, area() and perimeter().
	The Circle and Rectangle classes inherit from Shape and override the
	 virtual functions with their own implementations.
	The Printable class is an interface with one pure virtual function, print().
	The `PrintableCircle.
 * 
 */