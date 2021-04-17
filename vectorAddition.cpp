/*
By John Nguyen, April 15, 2021
Meant to be used with the DeltaMath.com problemset "Add Vectors In Magnitude & Direction Form (Guided)"
*/

#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

void calcDegrees(float mag1, float dir1, float mag2, float dir2) {
	float degreesToRad = 1/57.2957795;
	if (dir1 < 360 && dir2 < 360 && dir1 >= 0 && dir2 >= 0) {
		// Generates components of vectors and prints them
		float x1 = mag1 * cos(dir1 * degreesToRad);
		float y1 = mag1 * sin(dir1 * degreesToRad);
		float x2 = mag2 * cos(dir2 * degreesToRad);
		float y2 = mag2 * sin(dir2 * degreesToRad);
		cout << "Vector 1: < " << x1 << ", " << y1 << " >";
		cout << "\nVector 2: < " << x2 << ", " << y2 << " >";
		// Generates components of resultant vector
		float x3 = x1 + x2;
		float y3 = y1 + y2;
		cout << "\n\nResultant Vector (Component Form): < " << x3 << ", " << y3 << " >";
		// Generates magnitude and direction of resultant vector
		float mag3 = sqrt(pow(x3, 2) + pow(y3, 2));
		float dir3 = atan(abs(y3) / abs(x3)) / degreesToRad;
		dir3 = (x3 >= 0) ? (y3 >= 0) ? dir3 : 360 - dir3 : (y3 >= 0) ? 180 - dir3 : 270 - dir3;
		cout << "\n       (Magnitude/Direction Form): " << mag3 << " < cos(" << dir3 << "), sin(" << dir3 << ") >";
	} else
	cout << "One or both angles is out of range! Required range is 0 <= angle < 360";
}

void printHelp() {
	cout << "This program is designed to aid with the addition of 2D vectors.\n" << 
				"Options: \n"<<
				"    -h                      - Display this help prompt\n"<<
				"    -md <m1> <d1> <m2> <d2> - Add 2 vectors, inputting direction in degrees\n"<<
				"    -mr <m1> <d1> <m2> <d2> - Add 2 vectors, inputting direction in radians\n"<<
				"    -c <x1> <y1> <x2> <y2>  - Add 2 vectors, in component form\n";
}

int main( int argc, char *argv[] ) {
	if (argc == 1) {
		printHelp();
	} else if (argc == 2) {
		std::string option = std::string(argv[1]); // Converts into string class so we can compare it to strings
		if (option == "help" || option == "h" || option == "-h" || option == "--help") {
			printHelp();
		} else if (option == "-md") {
			cout << "5 arguments expected, 1 provided: -md <magnitude1> <direction1> <magnitude2> <direction2>\n";
		} else if (option == "-mr") {
			cout << "5 arguments expected, 1 provided: -mr <magnitude1> <direction1> <magnitude2> <direction2>\n";
		} else if (option == "-c") {
			cout << "5 arguments expected, 1 provided: -c <x1> <y1> <x2> <y2>\n";
		} else {
			cout << "Unknown argument " << option << ".";
		}
	} else if (argc == 3 || argc == 4 || argc == 5) {
		cout << "Incorrect number of arguments.";
		printHelp();
	} else if (argc == 6) {
		if (std::string(argv[1]) == "-md") {
			calcDegrees(std::atof(argv[2]), std::atof(argv[3]), std::atof(argv[4]), std::atof(argv[4]));
		}
	}
	
	return 0;
}