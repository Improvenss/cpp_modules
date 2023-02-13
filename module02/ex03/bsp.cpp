/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:48:59 by gsever            #+#    #+#             */
/*   Updated: 2023/02/13 18:09:30 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// static Fixed	abs(Fixed num)
// {
// 	if (num < 0)
// 		return (num = num * -1);
// 	return (num);
// }

bool	bsp( Point const a, Point const b, Point const c, Point const point )
{
	Fixed	bx(b.getPointX() - a.getPointX());
	Fixed	by(b.getPointY() - a.getPointY());
	Fixed	cx(c.getPointX() - a.getPointX());
	Fixed	cy(c.getPointY() - a.getPointY());
	Fixed	x(point.getPointX() - a.getPointX());
	Fixed	y(point.getPointY() - a.getPointY());
	Fixed	d(bx * cy - cx * by);

	Fixed	WA = (x * (by - cy) + y * (cx - bx) + bx * cy - cx * by) / d;
	Fixed	WB = (x * cy - y * cx) / d;
	Fixed	WC = (y * bx - x * by) / d;

	std::cout << "bx: " << bx << std::flush << std::endl;
	std::cout << "by: " << by << std::flush << std::endl;
	std::cout << "cx: " << cx << std::flush << std::endl;
	std::cout << "cx: " << cx << std::flush << std::endl;
	std::cout << "x: " << x << std::flush << std::endl;
	std::cout << "y: " << y << std::flush << std::endl;
	std::cout << "d: " << d << std::flush << std::endl;
	std::cout << "WA: " << WA << std::flush << std::endl;
	std::cout << "WB: " << WB << std::flush << std::endl;
	std::cout << "WC: " << WC << std::flush << std::endl;

	if (!(WA.toFloat() >= 0.0 && WA.toFloat() <= 1.0))
		return (false);
	else if (!(WB.toFloat() >= 0.0 && WB.toFloat() <= 1.0))
		return (false);
	else if (!(WC.toFloat() >= 0.0 && WC.toFloat() <= 1.0))
		return (false);
	return (true);
}
/*
double bx = Bx-Ax,
by = By-Ay,
cx = Cx-Ax,
cy = Cy-Ay,
x = Px-Ax,
y = Py-Ay;

d = bx * cy - cx * by;
double WA = (x * (by-cy) + y*(cx-bx) + bx * cy - cx * by) / d;
double WB = (x * cy - y* cx) / d;
double WC = (y * bx - x * by) / d;
*/

/* -> Different type.

static Fixed   abs(Fixed x) {
    if (x < 0)
        return x * -1;
    return x;
}

static Fixed   area( Point const a, Point const b, Point const c ) {
    return ( ( ( a.getX() * ( b.getY() - c.getY() ) ) +
             ( b.getX() * ( c.getY() - a.getY() ) ) +
             ( c.getX() * ( a.getY() - b.getY() ) ) ) / 2 );
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
    Fixed   abcArea = abs(area( a, b, c ));
    Fixed   pabArea = abs(area( point, a, b ));
    Fixed   pbcArea = abs(area( point, b, c ));
    Fixed   pcaArea = abs(area( point, c, a ));

    return  ( abcArea == pabArea + pbcArea + pcaArea );
}

*/