#include "Raster.h"


Raster::Raster(unsigned int a_DimX, unsigned int a_DimY) : m_DimX(a_DimX), m_DimY(a_DimY)
    {
        if (m_DimX && m_DimY)
        {
            m_Raster.resize( (m_DimX*m_DimY-1)/8 + 1, 0);
	    std::fill(m_Raster.begin(), m_Raster.end(), 0);
        }
	cout <<"m_DimX: "<<m_DimX<<" m_DimY: "<<m_DimY<<endl;
    }

 
void Raster::initCircle (int rad){
	radius = rad;
        long radSq = radius * radius;
         for (int x = 0; x < m_DimX; x++){  //this goes from 0 to 2r+1. In set function we will adjust the value by sustracting r from it for it to go from -r to r
                for (int y = 0; y < m_DimY; y++){
		  set (x, y);
		}

        }
}
void Raster::set(int x, int y){
	
	int i = x - radius;
	int j = y - radius;
	//cout <<"\n i,j:"<<i<<","<<j<<"<x,y:"<<x<<","<<y<<">>>>>>>";

       	if(i*i + j*j <= radius*radius){
	//if(i*i + j*j < radius*radius + radius){

		unsigned char c = 128; //binary 10000000
		int overallBitIndex = m_DimX * x + y; // index starts from 0 
		int m_RasterByteOffset = overallBitIndex/8;
		int m_RasterBitIndex =  overallBitIndex % 8;
		c = c >> m_RasterBitIndex;
		m_Raster[m_RasterByteOffset] = 	 m_Raster[m_RasterByteOffset] | c;
         	//cout<<"m_RasterByteOffset."<<m_RasterByteOffset <<" m_RasterBitIndex:"<<m_RasterBitIndex <<" AND m_Raster[m_RasterByteOffset] "<<m_Raster[m_RasterByteOffset] <<endl;
        }

	//else not found
}

 void Raster::drawCircle(){
	int byteOffset = 0;
	unsigned char c = m_Raster[byteOffset];
	int count = 8;
         for (int x = 0; x < m_DimX; x++){  //this goes from 0 to 2r+1. In set function we will adjust the value by sustracting r from it for it to go from -r to r
                for (int y = 0; y < m_DimY; y++){
			if (count == 0){
				byteOffset++;
				c = m_Raster[byteOffset];
				count = 8;
				//cout<<"Result: "<<x<<","<<y<<": from offset:"<<byteOffset<<" ="<<c-0<<" IS";

			}
			if (c & 128){
				cout<<".";
			}
			else {
				cout<<" ";
			}
			c = c << 1;
			count--;
		}

              cout<<"\n";

        }
}

/*void Raster::printRasterValues(){ //for testing purpose

	for (int i = 0 ; i < m_Raster.size(); i++){
		cout <<"index: "<<i<<" Value: "<<m_Raster[i]-0<<endl;
	}
}*/
