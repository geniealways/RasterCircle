#include <iostream>
#include <fstream> 
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "Raster.h"

using namespace std;

int main(int argc, char* argv[]) {

	if ((argc < 3) || ((strcmp(argv[1], "-radius") != 0) && (strcmp(argv[1], "-createtest") != 0) && (strcmp(argv[1], "-runtest") != 0)) || (strcmp(argv[1], "-help") == 0)){ 
		cout <<"STDIN input format: \n 1. To run a standalone input: ./main -radius <value>\n" 
			<<" 2. To generate a test: ./main -createtest -radius <value> \n"
			<<" 3. To run and verify a test case: ./main -runtest <filename>\n ";
		return 1;
	}

	else if ((strcmp(argv[1], "-radius") == 0)) { 

		int radius = atoi(argv[2]);
		if (radius > 16000) {// Adding this contraint to support int operations throughout and to avoid overflow 
			cout <<"Please enter a radius upto 16000\n";
			return 1;
		}
		Raster r (2*radius+1, 2*radius+1);
		r.initCircle (radius);
		r.drawCircle();
		return 0;
	}

	else if (strcmp(argv[1], "-createtest") == 0) {
		if ((argc < 4) || (strcmp(argv[2], "-radius") != 0)){
			cout <<"Please enter a radius value in the following format: ./main -createtest -radius <value>\n A test file will be generted with the bit vector dump of the result. \n ";
			return 1;
		}
		int radius = atoi(argv[3]);
		if (radius > 16000) {// Adding this contraint to support int operations throughout and to avoid overflow 
			cout <<"Please enter a radius upto 16000\n";
			return 1;
		}
		Raster r (2*radius+1, 2*radius+1);
		vector<unsigned char> result = r.initCircle (radius);
		string name = "radius" + to_string(radius) + ".test";
		ofstream file;
		file.open (name.c_str());
		if (!file.is_open()) {
			cout<< "Unable to open File:" << name <<":" << endl;
			return 1;

		}
		file << radius <<endl;
		for (int i = 0 ; i < result.size(); i++){ /*converting ascii to numeric representable format in the file*/
		file << result[i]-0 <<endl;
		}
		file.close();
		cout <<"Test file "<<name<<" created\n";
		return 0;
	}

	else if (strcmp(argv[1], "-runtest") == 0) {

		string fileName = argv[2];
		std::ifstream inFile;
		inFile.open(fileName);
		int radius;         
	        if (inFile.is_open()) {
			istream *in = &inFile;
			string line;
			getline (*in, line);
			radius = stoi(line);
			Raster r(2*radius+1, 2*radius+1); 
			vector<unsigned char> result = r.initCircle (radius);
			int i = 0;
			while (getline(*in, line)){
				if(stoi(line) != (result[i]-0)){ //comparing expected results to the generated results
					cout<< "Results don't match the expected values" << endl;
					return 1;

				}
				//cout<<line<<endl;
				i++;
			}
			r.drawCircle();
			cout <<"The test results match with the expected values\n";
			return 0;

	        }
		else{
			cout<< "Unable to open File:" << fileName <<":" << endl;
			return 1;
		}

		return 0;
	}

	else {
		cout <<"STDIN input format: \n 1. To run a standalone input: ./main -radius <value>\n" 
			<<" 2. To generate a test: ./main -createtest -radius <value> \n"
			<<" 3. To run and verify a test case: ./main -runtest <filename>\n ";
		return 1;
	}

	
}
