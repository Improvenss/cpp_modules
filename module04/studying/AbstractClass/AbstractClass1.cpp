/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractClass1.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 22:14:14 by gsever            #+#    #+#             */
/*   Updated: 2023/02/28 22:42:10 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file AbstractClass1.cpp
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
	In C++, an abstract class is a class that cannot be instantiated.
	Instead, it is designed to be used as a base class for other classes
	 that will inherit from it. The purpose of an abstract class is to
	 define a common interface for a set of classes, without implementing
	 the functionality for that interface.
	The derived classes that inherit from the abstract class will then
	 provide their own implementation for the interface.

	To define an abstract class in C++, you use the "virtual" keyword
	 to declare a method that does not have an implementation.
	This method is called a pure virtual function, and it is denoted
	 by placing "= 0" after the function declaration.

	Here is an example of an abstract class in C++:
 * 
 */
class Shape {
  public:
    virtual void draw() = 0;
    virtual double area() = 0;
};

/**
 * @brief 
 * 
	In this example, the Shape class is an abstract class that defines two
	 pure virtual functions: "draw" and "area".
	These functions do not have an implementation in the Shape class, but
	 any derived class that inherits from Shape must implement them.

	Now let's look at an example of a derived class that inherits from
	 the Shape abstract class and provides its own implementation for
	 the "draw" and "area" functions:
 * 
 */
class Circle : public Shape {
  public:
    Circle(double r) : radius(r) {}
    void draw() {
        // implementation for drawing a circle
    }
    double area() {
        return 3.14 * radius * radius;
    }
  private:
    double radius;
};

/**
 * @brief 
 * 
	In this example, the Circle class inherits from the Shape class using
	 the "public" access specifier.
	It provides its own implementation for the "draw" function, which will
	 draw a circle, and the "area" function, which calculates
	 the area of a circle.

	Notice that the Circle class provides implementations for both of
	 the pure virtual functions defined in the Shape class.
	This is necessary, because any class that inherits from an abstract
	 class must implement all of the pure virtual functions defined in
	 the base class.

	By defining an abstract class in this way, you can create a hierarchy
	 of classes that share a common interface, but have different
	 implementations for that interface.
	This can be useful for organizing and simplifying your code, and
	 for making it more modular and reusable.
 * 
 * @return int 
 */
int	main()
{

}