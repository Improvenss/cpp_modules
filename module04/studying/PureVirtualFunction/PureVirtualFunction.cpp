/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PureVirtualFunction.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 21:59:24 by gsever            #+#    #+#             */
/*   Updated: 2023/02/28 22:04:27 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file PureVirtualFunction.cpp
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
	In C++, a pure virtual function is a virtual function that is declared
	 in a base class, but has no implementation in that base class.
	Instead, it's up to the derived classes to provide an implementation of
	 the pure virtual function.
	A class with one or more pure virtual functions is called an
	 abstract class, and you can't create an object of an abstract class.
	Instead, you can create objects of derived classes that implement
	 the pure virtual functions.

	Here's an example of a simple abstract class that defines a
	 pure virtual function:
 * 
 */
class Shape {
public:
    virtual double area() const = 0;  // pure virtual function
};

/**
 * @brief 
 * 
	In this example, the Shape class has a pure virtual function called area().
	This function has no implementation in the Shape class, so any class that
	 derives from Shape must provide an implementation of area().

	Here's an example of a derived class that implements the Shape class:
 * 
 */
class Rectangle : public Shape {
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const { return width * height; }

private:
    double width;
    double height;
};

/**
 * @brief 
 * 
	In this example, the Rectangle class derives from Shape and provides
	 an implementation of the area() function.
	The implementation simply calculates the area of the rectangle using
	 its width and height.

	Here's an example of how you might use these classes:
 * 
 * @return int 
 */
int main() {
    // This won't compile, because Shape is an abstract class and can't be instantiated
    // Shape s;

    // This works fine, because Rectangle is a concrete class that provides an implementation of area()
    Rectangle r(3.0, 4.0);
    std::cout << "The area of the rectangle is " << r.area() << std::endl;

    return 0;
}

/**
 * @brief 
 * 
	In this example, we try to create an object of type Shape,
	 which won't compile because Shape is an abstract class.
	We then create an object of type Rectangle, which is a concrete
	 class that provides an implementation of the area() function.
	We can then call the area() function on the Rectangle object to
	 calculate its area.

	I hope this explanation helps you understand how pure virtual functions
	 work in C++. Let me know if you have any further questions!
 * 
 */