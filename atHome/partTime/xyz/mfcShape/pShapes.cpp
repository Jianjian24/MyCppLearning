#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <vector>
#include <iomanip> 
#include <cmath>
#include <cstring>
#include "pch.h"
#include "pShapes.h"
using namespace std;
using namespace comsc;

#define M_PI 3.1415927 

Square::Square(const vector<string> &tokens) : sideLength(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0) {}
Rectangle::Rectangle(const vector<string> &tokens) : length(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0),
	width(tokens.size() > 2 ? atof(tokens[2].c_str()) : 0) {}
Circle::Circle(const vector<string> &tokens) : radius(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0) {}
Triangle::Triangle(const vector<string> &tokens) : sideLength(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0) {}
Cube::Cube(const vector<string> &tokens) : Square(tokens) {}
Box::Box(const vector<string> &tokens) : Rectangle(tokens), height(tokens.size() > 3 ? atof(tokens[3].c_str()) : 0) {}
Cylinder::Cylinder(const vector<string> &tokens) : Circle(tokens), height(tokens.size() > 2 ? atof(tokens[2].c_str()) : 0) {}
Prism::Prism(const vector<string> &tokens) : Triangle(tokens),
	height(tokens.size() > 2 ? atof(tokens[2].c_str()) : 0) {}

Square& Square::operator=(const Square& copyThis) {
	Square& host = *this;
	if (this != &copyThis) {
		const_cast<double&>(host.sideLength) = copyThis.sideLength;
	}
	return host; //returns a self-reference
}

comsc::Rectangle& comsc::Rectangle::operator=(const comsc::Rectangle& copyThis) {
	comsc::Rectangle& host = *this;
	if (this != &copyThis) {
		const_cast<double&>(host.length) = copyThis.length;
		const_cast<double&>(host.width) = copyThis.width;
	}
	return host; //returns a self-reference
}

Circle& Circle::operator=(const Circle& copyThis) {
	Circle& host = *this;
	if (this != &copyThis) {
		const_cast<double&>(host.radius) = copyThis.radius;
	}
	return host; //returns a self-reference
}

Triangle& Triangle::operator=(const Triangle& copyThis) {
	Triangle& host = *this;
	if (this != &copyThis) {
		const_cast<double&>(host.sideLength) = copyThis.sideLength;
	}
	return host; //returns a self-reference
}

Cube& Cube::operator=(const Cube& copyThis) {
	Cube& host = *this;
	if (this != &copyThis) {
		const_cast<double&>(host.sideLength) = copyThis.sideLength;
	}
	return host;
}

Box& Box::operator=(const Box& copyThis) {
	Box& host = *this;
	if (this != &copyThis) {
		const_cast<double&>(host.length) = copyThis.length;
		const_cast<double&>(host.width) = copyThis.width;
		const_cast<double&>(host.height) = copyThis.height;
	}
	return host;
}

Cylinder& Cylinder::operator=(const Cylinder& copyThis) {
	Cylinder& host = *this;
	if (this != &copyThis) {
		const_cast<double&>(host.radius) = copyThis.radius;
		const_cast<double&>(host.height) = copyThis.height;
	}
	return host; 
}

Prism& Prism::operator=(const Prism& copyThis) {
	Prism& host = *this;
	if (this != &copyThis) {
		const_cast<double&>(host.sideLength) = copyThis.sideLength;
		const_cast<double&>(host.height) = copyThis.height;
	}
	return host;
}

ostream& operator<<(ostream& out, const Shape& aShape) {
	aShape.output(out);
	return out;
}

//Mainpulator functions
ostream& precisionTwoDecimals(ostream& out) {
	out.setf(ios::fixed);
	out.precision(2); // 2 decimal digits
	return out;
}

ostream& turnOffFloatingPoint(ostream& out) {
	out.unsetf(ios::fixed);
	out.precision(6); // the C++ default
	return out;
}

void Square::output(ostream& out) const {

	double area, perimeter;
	area = (this->sideLength * this->sideLength);
	perimeter = this->sideLength * 4;
	out << turnOffFloatingPoint;
	out << "SQUARE side=" << this->sideLength << " area=" << precisionTwoDecimals << area << " perimeter=" << perimeter << "\n";
	turnOffFloatingPoint;
}

void Rectangle::output(ostream& out) const {

	double area, perimeter;
	area = this->length * this->width;
	perimeter = (2 * this->length) + (2 * this->width);
	out << turnOffFloatingPoint;
	out << "RECTANGLE length=" << this->length << " width=" << this->width << " area=" << precisionTwoDecimals << area << " perimeter=" << perimeter << "\n";
	turnOffFloatingPoint;
}

void Circle::output(ostream& out) const {

	double area, circumference;
	area = M_PI * (this->radius) * (this->radius);
	circumference = M_PI * (2 * (this->radius));
	out << turnOffFloatingPoint;
	out << "CIRCLE radius=" << this->radius << " area=" << precisionTwoDecimals << area << " perimeter=" << circumference << "\n";
	turnOffFloatingPoint;
}

void Triangle::output(ostream& out) const {

	double area, perimeter;
	perimeter = this->sideLength * 3;
	area = (sqrt(3)/4) * this->sideLength * this->sideLength;
	out << turnOffFloatingPoint;
	out << "TRIANGLE side=" << this->sideLength << " area=" << precisionTwoDecimals << area << " perimeter=" << perimeter << "\n";
	turnOffFloatingPoint;
}

void Cube::output(ostream& out) const {
	double area, volume;
	volume = this->sideLength * this->sideLength * this->sideLength;
	area = (6 * this->sideLength * this->sideLength);
	out << turnOffFloatingPoint;
	out << "CUBE side=" << this->sideLength << " surface area=" << precisionTwoDecimals << area << " volume=" << volume << "\n";
	turnOffFloatingPoint;
}

void Box::output(ostream& out) const {

	double area, volume;
	volume = this->length * this->width * this->height;
	area = (2 * this->length * this->width) + (2 * this->width * this->height) + (2 * this->length * this->height);
	out << turnOffFloatingPoint;
	out << "BOX length=" << this->length << " width=" << this->width << " height=" << this->height << " surface area=" << precisionTwoDecimals << area << " volume=" << volume << "\n";
	turnOffFloatingPoint;
}

void Prism::output(ostream& out) const {

	double area, volume;
	volume = this->sideLength * this->sideLength * this->height;
	area = 2 * (this->sideLength * this->sideLength) + ((this->sideLength * 4) + this->height);
	out << turnOffFloatingPoint;
	out << "PRISM side=" << this->sideLength << " height=" << this->height << " surface area=" << precisionTwoDecimals << area << " volume=" << volume << "\n";
	turnOffFloatingPoint;
}

void Cylinder::output(ostream& out) const {
	double area, volume;
	area = (2 * M_PI * this->radius * this->height) + (2 * M_PI * this->radius * this->radius);
	volume = (M_PI * (this->radius * this->radius) * this->height);
	out << turnOffFloatingPoint;
	out << "CYLINDER radius=" << this->radius << " height=" << this->height << " surface area=" << precisionTwoDecimals << area << " volume=" << volume << "\n";
	turnOffFloatingPoint;
}
