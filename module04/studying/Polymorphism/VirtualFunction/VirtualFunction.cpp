/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VirtualFunction.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 22:25:39 by gsever            #+#    #+#             */
/*   Updated: 2023/02/28 22:42:34 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file VirtualFunction.cpp
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

class Shape {
    protected:
        double width, height;

    public:
        Shape(double w = 0, double h = 0) {
            width = w;
            height = h;
        }

        virtual double area() {
            cout << "Parent class area :" << endl;
            return 0;
        }
};

class Rectangle: public Shape {
    public:
        Rectangle(double w = 0, double h = 0): Shape(w, h) { }

        double area() {
            cout << "Rectangle class area :" << endl;
            return (width * height);
        }
};

class Triangle: public Shape {
    public:
        Triangle(double w = 0, double h = 0): Shape(w, h) { }

        double area() {
            cout << "Triangle class area :" << endl;
            return (width * height / 2);
        }
};

/**
 * @brief 
 * 
	Virtual functions are functions that are declared in the base class and
	 can be redefined in the derived class.
	The derived class provides its own implementation of the
	 virtual function, which overrides the implementation in the base class.
 * 
 * @return int 
 */
int main() {
    Shape* shape;
    Rectangle rec(10, 7);
    Triangle tri(10, 5);

    shape = &rec;
    shape->area();

    shape = &tri;
    shape->area();

    return 0;
}

/**
 * @brief 
 * 
	In the above code, we have defined a base class "Shape" and
	 two derived classes "Rectangle" and "Triangle".
	The base class has a virtual function "area", which is overridden
	 in the derived classes.
	The main function creates objects of the derived classes and
	 assigns their addresses to a pointer of the base class.
	The virtual function is called through the pointer, which results
	 in the appropriate derived class function being called based on
	 the object pointed to.
	This is an example of dynamic polymorphism because the decision
	 of which function to call is made at runtime based on the type
	 of the object pointed to.
 * 
 */