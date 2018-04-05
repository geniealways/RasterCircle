#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

class Raster

{
	vector<unsigned char> m_Raster;
	const unsigned int m_DimX;
	const unsigned int m_DimY;
	Raster& operator=(const Raster&); // Not defined elsewhere
	Raster(const Raster&); // Not defined elsewhere
 	void set(int x, int y); // please define
	int radius;
   public:
	Raster(unsigned int a_DimX, unsigned int a_DimY);
	int initCircle (int radius);
	
   
};
