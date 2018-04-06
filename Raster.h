#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

class Raster

{
	vector<unsigned char> m_Raster;
	const unsigned int m_DimX;
	const unsigned int m_DimY;
 	void set(int x, int y); 
	int radius;
   public:
	Raster(unsigned int a_DimX, unsigned int a_DimY);
	vector<unsigned char> initCircle(int radius);
	void drawCircle();	
   
};
