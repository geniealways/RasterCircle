#include "Raster.h"


Raster::Raster(unsigned int a_DimX, unsigned int a_DimY) : m_DimX(a_DimX), m_DimY(a_DimY)
    {
        if (m_DimX && m_DimY)
        {
            m_Raster.resize( (m_DimX*m_DimY-1)/8 + 1, 0);
        }
    }

 
/*int Raster::initCircle (int radius){
        long radSq = radius * radius;
        int x, y;
         for (int i = -radius; i <= radius; i++)
            {
                for (int j = -radius; j <= radius; j++)
                     {
			//x = i-radius;
                        //y = j-radius;
                        //cout <<"\n i,j:"<<i<<","<<j<<"<x,y:"<<x<<","<<y<<"->";
			cout <<"\n i,j:"<<i<<","<<j<<"  ->";
			//if(x*x + y*y < radSq + radius){
			if(i*i + j*j < radSq + radius){

                            	cout<<".";
			    	set (i,j);
                        }
                        else {
                            cout<<" ";
                        }
                }
                cout<<"\n";
        }
return 1;
}*/
int Raster::initCircle (int rad){
	radius = rad;
        long radSq = radius * radius;
         for (int x = 0; x < m_DimX; x++){  //this goes from 0 to 2r+1. In set function we will adjust the value by sustracting r from it for it to go from -r to r
                for (int y = 0; y < m_DimY; y++){
		  set (x, y);
		}
              cout<<"\n";

        }
return 1;
}
void Raster::set(int x, int y){
	int i = x - radius;
	int j = y - radius;
       	if(i*i + j*j < radius*radius + radius){
		unsigned char c = 128; //binary 10000000
	        //cout <<"\n i,j:"<<i<<","<<j<<"<x,y:"<<x<<","<<y<<"->";
		int overallBitIndex = m_DimX * x + y; // index starts from 0 
		int m_RasterByteOffset = overallBitIndex/8;
		int m_RasterBitIndex =  overallBitIndex % 8;
		c = c >> m_RasterBitIndex;
		m_Raster[m_RasterByteOffset] = 	m_Raster[m_RasterByteOffset] | c;
         	//cout<<".";
        }
 	/*else {
                cout<<" ";
        }*/

}


