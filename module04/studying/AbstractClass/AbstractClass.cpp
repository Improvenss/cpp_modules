/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractClass.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:23:20 by gsever            #+#    #+#             */
/*   Updated: 2023/02/24 20:25:45 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file AbstractClass.cpp
 * @author Görkem SEVER (gsever)
 * @brief 
 * @link https://www.educative.io/answers/what-is-a-cpp-abstract-class
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>

using namespace std;

class Shape {
   public:
      virtual int Area() = 0; // Pure virtual function is declared as follows.
      // Function to set width.
      void setWidth(int w) {
         width = w;
      }
      // Function to set height.
      void setHeight(int h) {
         height = h;
      }
   
   protected:
      int width;
      int height;
};

// A rectangle is a shape; it inherits shape.
class Rectangle: public Shape {
   public:
      // The implementation for Area is specific to a rectangle.
      int Area() { 
         return (width * height); 
      }
};
// A triangle is a shape too; it inherits shape.
class Triangle: public Shape {
   public:
      // Triangle uses the same Area function but implements it to
      // return the area of a triangle.
      int Area() { 
         return (width * height)/2; 
      }
};

/**
 * @brief 
 * 
 * @note Not working in 42's mac.
 * @return int 
 */
int main() {
  Rectangle R;
  Triangle T;

  R.setWidth(5);
  R.setHeight(10);

  T.setWidth(20);
  T.setHeight(8);

  cout << "The area of the rectangle is: " << R.Area() << endl;
  cout << "The area of the triangle is: " << T.Area() << endl;
}