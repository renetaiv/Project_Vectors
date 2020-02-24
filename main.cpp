#include<iostream>
#include "Element.h"
#include "Point.h"
#include "Vector.h"
#include "VectorLengthException.h"
#include "Triangle.h"
#include "EqualPointException.h"
#include "Line.h"
#include "Segment.h"
#include "Tetrahedron.h"
#include <fstream>

using namespace std;

int main() {
	ofstream myfile;
	myfile.open("myFile.txt", ios::out);

	if (!myfile) {
		cerr << "File could not be opened!\n";
		return 1;
	}


	setlocale(LC_ALL, "Bulgarian");
	Point p1;
	Point p2;
	
	unsigned menu;
	cout << "Please select a geometric object: \n"
		<< "1 – Point \n"
		<< "2 – Vector \n"
		<< "3 – Line \n"
		<< "4 – Segment \n"
		<< "5 – Triange \n"
		<< "6 - Tetrahedron \n";

	myfile << "Please select a geometric object: \n"
		<< "1 – Point \n"
		<< "2 – Vector \n"
		<< "3 – Line \n"
		<< "4 – Segment \n"
		<< "5 – Triange \n"
		<< "6 - Tetrahedron \n";

	Vector a;
	Vector b;
	Vector c;
	Vector g;
	
	Triangle y;

	Line line1(Point(3,3,3), Vector(1,2,3));
	
	Line line2(Point(3,3,3), Vector(5,8,2));

	Line line3(Point(19, 24, 29), Point(31, 36, 41));
	Point point(19, 24, 29);

	//cout << "a " << boolalpha << line3 + point;
	//cout << "b " << boolalpha << line1 | line2;
	//cout << "c " << boolalpha << line1 || line2;

	//Segment segm(Point(7,12,2), Vector(2,9,4), Point(0,0,0), Point(1,1,1));

	Tetrahedron tetr;

	char ch;
	do {
		cin >> menu;
		switch (menu) {
		case 1: 
			cin >> p1;
			cout << endl;

			myfile << p1 << endl;
			cin >> p2;
			myfile << p2 << endl;

			cout << boolalpha << (p1 == p2) << endl;
			myfile << boolalpha << (p1 == p2) << endl;
			break;
		case 2: unsigned menu2;
			cin >> a;
			myfile << a << endl;
			cout << "Please select an operation for the object: \n"
				<< "1 - vector length calculation \n"
				<< "2 - vector direction calculation \n"
				<< "3 - projection of a vector onto another vector \n"
				<< "4 - zero vector check \n"
				<< "5 - check for parallelism of two vectors \n"
				<< "6 - check for perpendicularity of two vectors \n"
				<< "7 - addition of two vectors \n"
				<< "8 - multiplication of a vector by a real number \n"
				<< "9 - dot product of two vectors \n"
				<< "10 - cross product of two vectors \n"
				<< "11 - mixed product of three vectors \n";
			
			myfile << "Please select an operation for the object: \n"
				<< "1 - vector length calculation \n"
				<< "2 - vector direction calculation \n"
				<< "3 - projection of a vector onto another vector \n"
				<< "4 - zero vector check \n"
				<< "5 - check for parallelism of two vectors \n"
				<< "6 - check for perpendicularity of two vectors \n"
				<< "7 - addition of two vectors \n"
				<< "8 - multiplication of a vector by a real number \n"
				<< "9 - dot product of two vectors \n"
				<< "10 - cross product of two vectors \n"
				<< "11 - mixed product of three vectors \n";
			char ch2;
			do {
				cin >> menu2;
				switch (menu2) {
				case 1: cout << "Length = " << a.lengthOfVec() << endl;
					myfile << "Length = " << a.lengthOfVec() << endl;
					break;
				case 2: cout << "Direction = " << a.dirOfVec() << endl; 
					myfile << "Direction = " << a.dirOfVec() << endl;
					break;
				case 3: cin >> b;
					myfile << b << endl;
					cout << "Projection = " << a.proj(b) << endl;
					myfile << "Projection = " << a.proj(b) << endl;
					break;
				case 4:
					cout << "Zero vector check -> " << boolalpha << a.checkIfNull() << endl;
					myfile << "Zero vector check -> " << boolalpha << a.checkIfNull() << endl;
					break;
				case 5: cin >> b;
					myfile << b << endl;
					cout << "Check for parallelism: " << boolalpha << a.checkifParallel(b) << endl;
					myfile << "Check for parallelism: " << boolalpha << a.checkifParallel(b) << endl;
					break;
				case 6: cin >> b;
					myfile << b << endl;
					cout << "Check for perpendicularity: " << boolalpha << a.checkIfPerpend(b) << endl;
					myfile << "Check for perpendicularity: " << boolalpha << a.checkIfPerpend(b) << endl;
					break;
				case 7: cin >> b;
					myfile << b << endl;
					cout << "Result of addition: " << a + b << endl;
					myfile << "Result of addition: " << a + b << endl;
					break;
				case 8: int num;
					cout << "Enter a real number: ";
					cin >> num;
					myfile << num << endl;
					cout << "Result of multiplication: " << a * num << endl;
					myfile << "Result of multiplication: " << a * num << endl;
					break;
				case 9: cin >> b;
					myfile << b << endl;
					cout << "Dot product result: " << a * b << endl;
					myfile << "Dot product result: " << a * b << endl;
					break;
				case 10: cin >> b;
					myfile << b << endl;
					g = a ^ b;
					cout << "Cross product result: " << g << endl;
					myfile << "Cross product result: " << g << endl;
					break;
				case 11: cin >> b;
					myfile << b << endl;
					
					cin >> c;
					myfile << c << endl;
					cout << "Mixed product: " << a(b,c) << endl;
					myfile << "Mixed product: " << a(b,c) << endl;
					break;
				}
				cout << "Do you want to select a new operation (y/n)?";
				myfile << "Do you want to select a new operation (y/n)?";
				cin >> ch2;
				myfile << ch2 << endl;
			} while (ch2 != 'n');
			break;
		case 3: unsigned menu3;
			cout << "Please select an operation for the object: \n"
				<< "1 - to find the direction of the line - returns a vector parallel to the line \n"
				<< "2 - to find a normal vector - returns a vector perpendicular to the line \n"
				<< "3 - to find the angle between two lines - returns the value of the angle in radians \n";
			
			myfile << "Please select an operation for the object: \n"
				<< "1 - to find the direction of the line - returns a vector parallel to the line \n"
				<< "2 - to find a normal vector - returns a vector perpendicular to the line \n"
				<< "3 - to find the angle between two lines - returns the value of the angle in radians \n";
			char ch3;
			do {
				cin >> menu3;
				myfile << menu3 << endl;
				switch (menu3) {
				case 1:
					cout << "Direction of the line = ";
					a = line1.getDirection();
					cout << a;
					cout << endl;
					//myfile << "Direction of the line = "  << line1.getDirection() << endl;
					break;
				case 2:
					a = line1.normalVector();
					cout << "Normal vector = " << a << endl;
					myfile << "Normal vector = " << a << endl;
					break;
				case 3:
					cout << "The angle between two lines =  " << line1.getAngle(line2) << endl;
					myfile << "The angle between two lines =  " << line1.getAngle(line2) << endl;
					break;
				}
				cout << "Do you want to select a new operation (y/n)?";
				myfile << "Do you want to select a new operation (y/n)?";
				cin >> ch3;
				myfile << ch3 << endl;;
			} while (ch3 != 'n');
			break;
		case 4: unsigned menu4;
			cout << "Please select an operation for the object: \n"
				<< "1 - to find the length of a segment that returns a positive real number \n"
				<< "2 - to find the middle of a segment  that returns a point with coordinates \n";
			myfile << "Please select an operation for the object: \n"
				<< "1 - to find the length of a segment that returns a positive real number \n"
				<< "2 - to find the middle of a segment  that returns a point with coordinates \n";
			char ch4;
			do {
				cin >> menu4;
				myfile << menu4;
				switch (menu4) {
				case 1:
					cout << "The length of a segment = ";//<< segm.getLengthOfSegm() << endl;
					break;
				case 2:
					cout << "The middle of a segment = ";// << segm.getMiddleOfSegm() << endl;
					break;
				}
				cout << "Do you want to select a new operation (y/n)?";
				myfile << "Do you want to select a new operation (y/n)?";
				cin >> ch4;
				myfile << ch4 << endl;
			} while (ch4 != 'n');
			break;
		case 5: unsigned menu5;
			
			cout << "Please select an operation for the object: \n"
				<< "1 - determine the type of triangle \n"
				<< "2 - determine the area of triangle \n"
				<< "3 - determine the perimeter of triangle \n"
				<< "4 - finding the medicenter of the triangle by returning a Point object \n";

			myfile << "Please select an operation for the object: \n"
				<< "1 - determine the type of triangle \n"
				<< "2 - determine the area of triangle \n"
				<< "3 - determine the perimeter of triangle \n"
				<< "4 - finding the medicenter of the triangle by returning a Point object \n";
			char ch5;
			
			do {
				cin >> menu5;
				myfile << menu5 << endl;
			switch (menu5) {
			case 1: 
				cin >> y;
				myfile << y << endl;
				y.kindOfTriangle();
				break;
			case 2:
				cin >> y;
				myfile << y << endl;
				myfile << "Area = " << y.area() << endl;
				cout << "Area = " << y.area() << endl;
				break;
			case 3: 
				cin >> y;
				myfile << y << endl;
				cout << "Perimeter =  " << y.perimeter() << endl;
				myfile << "Perimeter =  " << y.perimeter() << endl;
				break;
			case 4:
				cin >> y;
				myfile << y << endl;
				cout << "Medicenter =  " << y.medicenter() << endl;
				myfile << "Medicenter =  " << y.medicenter() << endl;
				break;
				}
			cout << "Do you want to select a new operation (y/n)?";
			myfile << "Do you want to select a new operation (y/n)?";
			cin >> ch5;
			myfile << ch5 << endl;
			} while (ch5 != 'n');
			break;
		case 6: unsigned menu6;
			cout << "Please select an operation for the object: \n"
				<< "1 - to check that it is regular (all edges are equal) \n"
				<< "2 - to check that it is orthogonal (every two opposite edges are perpendicular) \n"
				<< "3 - to find the surrounding surface \n"
				<< "4 - to find volume \n";
			myfile << "Please select an operation for the object: \n"
				<< "1 - to check that it is regular (all edges are equal) \n"
				<< "2 - to check that it is orthogonal (every two opposite edges are perpendicular) \n"
				<< "3 - to find the surrounding surface \n"
				<< "4 - to find volume \n";
			char ch6;
			do {
				cin >> menu6;
				myfile << menu6 << endl;
				switch (menu6) {
				case 1:
					cin >> tetr; 
					myfile << tetr << endl;
					cout << "Is the tetrahedron regular? " << boolalpha << tetr.pravilen() << endl;
					myfile << "Is the tetrahedron regular? " << boolalpha << tetr.pravilen() << endl;
					break;
				case 2:
					cin >> tetr;
					myfile << tetr << endl;
					cout << "Is the tetrahedron orthogonal? " << boolalpha << tetr.ortogonalen() << endl;
					myfile << "Is the tetrahedron orthogonal? " << boolalpha << tetr.ortogonalen() << endl;
					break;
				case 3:
					cin >> tetr;
					myfile << tetr << endl;
					cout << "Surrounding surface = " << tetr.surroundingArea() << endl;
					break;
				case 4:
					cin >> tetr;
					myfile << tetr << endl;
					cout << "Volume = " << tetr.capacity() << endl;
					myfile << "Volume = " << tetr.capacity() << endl;
					break;
				}
				cout << "Do you want to select a new operation (y/n)?";
				myfile << "Do you want to select a new operation (y/n)?";
				cin >> ch6;
				myfile << ch6 << endl;
			} while (ch6 != 'n');
			break;
		}
		cout << "Do you want to select a new geometric object(y/n)?";
		myfile << "Do you want to select a new geometric object(y/n)?";
		cin >> ch;
		myfile << ch << endl;
	} while (ch != 'n');

	myfile.close();
	return 0;
}