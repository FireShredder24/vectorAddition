/*
By John Nguyen, April 15, 2021
Meant to be used with the DeltaMath.com problemset "Add Vectors In Magnitude & Direction Form (Guided)"
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	float degreesToRad = 1/57.2957795;
	cout << "Input magnitudes in the distance unit of your choice and directions in degrees.";
	cout << "\nInput magnitude of 1st vector: ";
	float mag1;
	cin >> mag1;
	cout << "Input direction of 1st vector: ";
	float dir1;
	cin >> dir1;
	cout << "Input magnitude of 2nd vector: ";
	float mag2;
	cin >> mag2;
	cout << "Input direction of 2nd vector: ";
	float dir2;
	cin >> dir2;
	if (dir1 < 360 && dir2 < 360 && dir1 >= 0 && dir2 >= 0) {
		// Generates components of vectors and prints them
		float x1 = mag1 * cos(dir1 * degreesToRad);
		float y1 = mag1 * sin(dir1 * degreesToRad);
		float x2 = mag2 * cos(dir2 * degreesToRad);
		float y2 = mag2 * sin(dir2 * degreesToRad);
		cout << "\nVector 1: <" << x1 << ", " << y1 << ">";
		cout << "\nVector 2: <" << x2 << ", " << y2 << ">";
		// Generates components of resultant vector
		float x3 = x1 + x2;
		float y3 = y1 + y2;
		cout << "\nResultant Vector: <" << x3 << ", " << y3 << ">";
		// Generates magnitude and direction of resultant vector
		float mag3 = sqrt(pow(x3, 2) + pow(y3, 2));
		float dir3 = atan(abs(y3) / abs(x3)) / degreesToRad;
		dir3 = (x3 >= 0) ? (y3 >= 0) ? dir3 : 360 - dir3 : (y3 >= 0) ? 180 - dir3 : 270 - dir3;
		cout << "\nor: " << mag3 << "<cos(" << dir3 << "), sin(" << dir3 << ")>";
	} else
	cout << "One or both angles is out of range!";
	return 0;
}