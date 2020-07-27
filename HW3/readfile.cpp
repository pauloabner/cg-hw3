#include "stdafx.h"
#include "variables.h"
#include "readfile.h"

using namespace std;

bool readvals(stringstream &s, const int numvals, float* values)
{
	for (int i = 0; i < numvals; i++) {
		s >> values[i];
		if (s.fail()) {
			cout << "Failed reading value " << i << " will skip\n";
			return false;
		}
	}
	return true;
}

string readfile(const char* filename)
{
	std::string str, cmd, fname;
	std::ifstream in;
	in.open(filename);
	if (in.is_open()) {
		getline(in, str);
		while (in) {
			if ((str.find_first_not_of(" \t\r\n") != std::string::npos) && (str[0] != '#')) {
				std::stringstream s(str);
				s >> cmd;

				float values[10];
				bool validinput;

				if (cmd == "output") {
					s >> fname;
					if (s.fail()) {
						std::cout << "Failed reading value filename";
					}
					else {
						std::cout << "Outputfile: " << fname << "\n";
					}
				}
				else if (cmd == "size") {
					validinput = readvals(s, 2, values);
					if (validinput) {
						w = (int)values[0]; h = (int)values[1];
						std::cout << "Size: " << values[0] << " x " << values[1] << "\n";
					}
				}
				else {
					std::cout << "Command not found: " << cmd << "\n";
				}
			}
			getline(in, str);
		}
	}
	else {
		std::cerr << "Unable to Open Input Data File " << filename << "\n";
		throw 2;
	}
	return fname;
}