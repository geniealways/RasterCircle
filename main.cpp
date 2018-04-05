#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "Raster.h"

using namespace std;

int main(int argc, char* argv[]) {
	if (argc <= 1){
		cout <<"STDIN input use format: ./main -radius <value>\n";
		return 0;
	}
	/*For stdin inputs*/
	else {
		if ((argc < 3) || (strcmp(argv[1], "-radius") != 0)){
			cout <<"STDIN input use format: ./main -radius <value>\n";
			return 0;
		}
		int radius = atoi(argv[2]);
		Raster r (2*radius+1, 2*radius+1);
		return r.drawCircle (radius);

	}
	return 1;
}
