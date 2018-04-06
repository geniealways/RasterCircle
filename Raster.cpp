#include "Raster.h"


Raster::Raster(unsigned int a_DimX, unsigned int a_DimY) : m_DimX(a_DimX), m_DimY(a_DimY){
	if (m_DimX && m_DimY)
        { 
		m_Raster.resize( (m_DimX*m_DimY-1)/8 + 1, 0);
        }
}

 
vector<unsigned char> Raster::initCircle (int r){
	radius = r;
        int radSq = radius * radius;
        for (int x = 0; x < m_DimX; x++){  //this goes from 0 to 2r+1. In set function we will adjust the value by sustracting r from it for it to go from -r to r
        	for (int y = 0; y < m_DimY; y++){
			set (x, y);
		}
        }
	return m_Raster;
}

void Raster::set(int x, int y){
	
	int i = x - radius;
	int j = y - radius;

	/* We run following check to determine if a point in a part of the circle. 
	OverallBitIndex- Thease are overall index of a certain 2-d point(x,y) converted in a 1-d bit index that starts from 0. 
	We will then calculate Byte offset(m_RasterByteOffset) in the byte vector m_Raster
	and bit offsets(m_RasterBitIndex) in that byte. 
	To set a particular byte we perform a logical or on existing byte value and the value of this point's x,y bit. (that is calculated by right shifting 128 (binary 10000000) by the RasterBitIndex).
	Each byte is interpreted left to right with starting index 0 
	*/
	if(i*i + j*j < radius*radius + radius){ 

		unsigned char c = 128; 
		int overallBitIndex = m_DimX * x + y; 
		int m_RasterByteOffset = overallBitIndex/8;
		int m_RasterBitIndex =  overallBitIndex % 8;
		c = c >> m_RasterBitIndex;
		m_Raster[m_RasterByteOffset] = m_Raster[m_RasterByteOffset] | c;
         	
	}

}

 void Raster::drawCircle(){
	int byteOffset = 0;
	unsigned char c = m_Raster[byteOffset];
	int count = 8;
         for (int x = 0; x < m_DimX; x++){  
                for (int y = 0; y < m_DimY; y++){
			if (count == 0){
				byteOffset++;
				c = m_Raster[byteOffset];
				count = 8;

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


