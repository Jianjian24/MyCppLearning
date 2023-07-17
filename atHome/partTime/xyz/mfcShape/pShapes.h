#ifndef PSHAPES_H
#define PSHAPES_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace comsc {

	struct Shape {
		virtual void output(ostream&) const = 0;
		virtual ~Shape() {};

	};
	ostream& operator<<(ostream&, const Shape&);

	class Square : public Shape {
	protected:
		const double sideLength;

	public:
		Square(const vector<string>&);
		Square& operator=(const Square&);
		void output(ostream&) const;
	};

	class Rectangle : public Shape {
	protected:
		const double length, width;

	public:
		Rectangle(const vector<string>&);
		Rectangle& operator=(const Rectangle&);
		void output(ostream&) const;
	};

	class Circle : public Shape {
	protected:
		const double radius;

	public:
		Circle(const vector<string>&);
		Circle& operator=(const Circle&);
		void output(ostream&) const;
	};

	class Triangle : public Shape {
	protected:
		const double sideLength;

	public:
		Triangle(const vector<string>&);
		Triangle& operator=(const Triangle&);
		virtual void output(ostream&) const;
	};

	class Cube : public Square {
	public:
		Cube(const vector<string>&);
		Cube& operator=(const Cube&);
		void output(ostream&) const;
	};

	class Box : public Rectangle {
	private:
		const double height;

	public:
		Box(const vector<string>&);
		Box& operator=(const Box&);
		void output(ostream&) const;
	};

	class Cylinder : public Circle {
	private:
		const double height;

	public:
		Cylinder(const vector<string>&);
		Cylinder& operator=(const Cylinder&);
		void output(ostream&) const;
	};

	class Prism : public Triangle {
	private:
		const double height;

	public:
		Prism(const vector<string>&);
		Prism& operator=(const Prism&);
		void output(ostream&) const;
	};

}

#endif
