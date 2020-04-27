#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Shape {
protected:
	double width;
	double height;

public:
	Shape() {
		cout << "Shape() constructor" << endl;
	};
	Shape(double width, double height) : width(width), height(height) {
		cout << "Shape(double width, double height) constructor" << endl;
	};

	virtual ~Shape() {
		cout << "~Shape() destructor" << endl;
	};

    virtual double area() const { // virtual = dinamikus kötés
		return -1;
	}
};

class Triangle : public Shape {
public:
	int triangleMember;

	Triangle(double width, double height) : Shape(width, height) {
		cout << "Triangle(double width, double height) constructor" << endl;
	}

	~Triangle() {
		cout << "~Triangle() destructor" << endl;
	}

	double area() const {
		return width * height / 2;
	}
};

class Rectangle : public Shape {
public:

	Rectangle(double width, double height) : Shape(width, height) {
		cout << "Rectangle(double width, double height) constructor" << endl;
	}

	~Rectangle() {
		cout << "~Rectangle() destructor" << endl;
	}

	double area() const {
		return width * height;
	}
};

int main() {
	/*{
		Triangle *t = new Triangle(3, 5);

        delete t;
		// memory leak
	}*/

	/*cout << endl << endl;

	{
		Shape *t = new Triangle(3, 5);

		cout << t->area() << endl;

		delete t;
	}


	cout << endl << endl;

	{
		unique_ptr<Shape> t{ new Triangle(3, 5) };

		cout << t->area() << endl;

		// unique_ptr<Triangle> t2 = t; // nem másolható, mert unique

		// t megszűnik, a smart pointer destruktora felszabadítja a memóriát
	}


	cout << endl << endl;

	{
		shared_ptr<Shape> t2;

		{
			shared_ptr<Shape> t{ new Triangle(3, 5) };

			cout << t->area() << endl;

			t2 = t; // másolható, referenciaszámlálást végez a smartpointer

			// t megszűnik, a smart pointer destruktora nem szabadítja fel a memóriát, mert számolja, hogy még egy mutató mutat rá
		}

		// t2 megszűnik, destruktora látja, hogy ő az utolsó pointer, felszabadítja a memóriát
	}

	{
		vector<unique_ptr<Shape>> v;
		v.push_back(unique_ptr<Shape>(new Triangle(4, 5)));
		v.push_back(unique_ptr<Shape>(new Shape(4, 5)));

		cout << v[0]->area() << endl;
		cout << v[1]->area() << endl;
	}*/

        Triangle *t = new Triangle(3, 5);
        cout << t->area() << endl;

        delete t;
        vector<Shape*> v2;

        Triangle a(4,5);
        Triangle* b = &a;
		v2.push_back(new Triangle(4, 5));
		//v2.push_back(new Shape(4, 5));
		v2.push_back(new Rectangle(4, 5));
		v2.push_back(b);
/*
		v2.push_back(Triangle(4, 5));
		v2.push_back(Shape(4, 5));
		v2.push_back(Rectangle(4, 5));

		cout << v2[0].area() << endl;
		cout << v2[1].area() << endl;
		cout << v2[2].area() << endl;*/

		cout << v2[0]->area() << endl;
		cout << v2[1]->area() << endl;
		cout << v2[1]->area() << endl;

	return 0;
}
