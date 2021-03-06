/**
 * \file Triangle.cpp
 * \brief Implémentation d'une classe représentant un Triangle
 * \author Zecchini.A Moreau.A Vieira Noro.K
 * \version 1.0
 * \date 23 Mars 2018
 *
 * Classe qui permet de représenter un Triangle.
 *
 */
#include <cmath>
#include "Triangle.hpp"
#include <MLV/MLV_all.h>
#include "Shapes.hpp"

using namespace enumShapes;

/**
 * Le triangle témoin est une variable de classe
 */
Triangle Triangle::temoin = Triangle(Point(0,0), Point(2,0), Point(1,1));

Point Triangle::getA() const
{
	return _A;
}

Point Triangle::getB() const
{
	return _B;
}

Point Triangle::getC() const
{
	return _C;
}

list<Point *> Triangle::getPoints() {
	return {&_A, &_B, &_C};
}

/**
 * Fonction virtuelle de copie
 */
shared_ptr<Shape> Triangle::copy() const
{
	return make_shared<Triangle>(*this);
}

void Triangle::drawMLV() const
{
    int vx [] = {_A.getX(), _B.getX(), _C.getX()}; 
    int vy [] = {_A.getY(), _B.getY(), _C.getY()}; 
     
    MLV_draw_polygon(vx, vy, 3, MLV_COLOR_BLUE); 		
}

/**
 * Calcul de la surface d'un triangle avec la formule d'Héron
 */
double Triangle::surface() const
{
	//Calcul des distances de chaque arrête du triangle
	double a = sqrt((_B.getX() - _A.getX()) * (_B.getX() - _A.getX())
					+ (_B.getY() - _A.getY()) * (_B.getY() - _A.getY()));
					
	double b = sqrt((_C.getX() - _A.getX()) * (_C.getX() - _A.getX())
					+ (_C.getY() - _A.getY()) * (_C.getY() - _A.getY()));
					
	double c = sqrt((_C.getX() - _B.getX()) * (_C.getX() - _B.getX())
					+ (_C.getY() - _B.getY()) * (_C.getY() - _B.getY()));
					
	//Calcul du périmètre
	double P = a + b + c; 
	
	//Calcul du demi-périmètre
	double p = P/2;
	
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

double Triangle::perimeter() const 
{
	double a = sqrt((_B.getX() - _A.getX()) * (_B.getX() - _A.getX())
					+ (_B.getY() - _A.getY()) * (_B.getY() - _A.getY()));
					
	double b = sqrt((_C.getX() - _A.getX()) * (_C.getX() - _A.getX())
					+ (_C.getY() - _A.getY()) * (_C.getY() - _A.getY()));
					
	double c = sqrt((_C.getX() - _B.getX()) * (_C.getX() - _B.getX())
					+ (_C.getY() - _B.getY()) * (_C.getY() - _B.getY()));
					
	return a + b + c;
}

double Triangle::origineDistance(const Point & p) const
{
	double distance = sqrt( (_A.getX() - p.getX()) * (_A.getX() - p.getX())
                            + (_A.getY() - p.getY()) * (_A.getY() - p.getY())); 
                            
    return distance;
}

void Triangle::print(ostream & os) const
{
    os << "triangle (" << _A << ", " << _B << ", " << _C << ")" << endl;
}

Shapes Triangle::getEnum() const 
{
	return Shapes::TRIANGLE;
}

Point Triangle::getOrigin () const {
	int x = (this->_A.getX() + this->_B.getX() + this->_C.getX())/3;
	int y = (this->_A.getY() + this->_B.getY() + this->_C.getY())/3;
	return Point(x, y);
}
