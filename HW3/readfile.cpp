#include "stdafx.h"
#include "readfile.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

std::string readfile(const char* filename)
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

				if (cmd == "output") {
					s >> fname;
					if (s.fail()) {
						std::cout << "Failed reading value filename";
					}
				}
				else {
					std::cout << "Command not found: " << cmd;
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