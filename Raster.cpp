#include "Raster.h"


Raster::Raster(unsigned int a_DimX, unsigned int a_DimY) : m_DimX(a_DimX), m_DimY(a_DimY)
    {
        if (m_DimX && m_DimY)
        {
            m_Raster.resize( (m_DimX*m_DimY-1)/8 + 1, 0);
        }
    }

 
int Raster::drawCircle (int radius){
        long radSq = radius * radius;
        int x, y;
         for (int i = 0; i < m_DimX; i++)
            {
                for (int j = 0; j < m_DimY; j++)
                     {
			x = i-radius;
                        y = j-radius;
                          //cout <<"\n i,j:"<<i<<","<<j<<"<x,y:"<<x<<","<<y<<"->";
                        if (x*x + y*y < radSq + radius){
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
}

void Raster::set(int x, int y){

	

}
