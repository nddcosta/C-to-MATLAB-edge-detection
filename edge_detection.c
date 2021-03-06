/*
  AUTH: Bill Green, Nathan Costa
  DESC: 2 3x3 Sobel masks for edge detection modified for matlab implementation
  DATE: 10/20/20
*/
#include "edge_detection.h"

extern void edge_detection(const double* image, const int* imsize, double* output)
{
   unsigned int		x, y;
   int			    i, j;
   long			    sumX, sumY;
   int			    SUM;
   int			    GX[3][3];
   int			    GY[3][3];
   
   const int cols = *(imsize);
   const int rows = *(imsize+1);

   /* 3x3 GX Sobel mask.  Ref: www.cee.hw.ac.uk/hipr/html/sobel.html */
   GX[0][0] = -1; GX[0][1] = 0; GX[0][2] = 1;
   GX[1][0] = -2; GX[1][1] = 0; GX[1][2] = 2;
   GX[2][0] = -1; GX[2][1] = 0; GX[2][2] = 1;

   /* 3x3 GY Sobel mask.  Ref: www.cee.hw.ac.uk/hipr/html/sobel.html */
   GY[0][0] =  1; GY[0][1] =  2; GY[0][2] =  1;
   GY[1][0] =  0; GY[1][1] =  0; GY[1][2] =  0;
   GY[2][0] = -1; GY[2][1] = -2; GY[2][2] = -1;
      
   /*---------------------------------------------------
		SOBEL ALGORITHM STARTS HERE
   ---------------------------------------------------*/
   for(y = 0; y <= (rows-1); y++){
        for(x = 0; x <= (cols-1); x++){
            sumX = 0;
            sumY = 0;
             /* image boundaries */
            if(y == 0 || y == rows-1)
                SUM = 0;
            else if(x ==0 || x == cols-1)
                SUM = 0;
            
	     /* Convolution starts here */
	     else{

            /*-------X GRADIENT APPROXIMATION------*/
            for(i=-1; i <= 1; i++)  {
            for(j=-1; j <= 1; j++)  {
                sumX = sumX + (int)( (*(image + x + i + 
                                (y + j)*cols)) * GX[i+1][j+1]);
            }
            }

            /*-------Y GRADIENT APPROXIMATION-------*/
             for(i=-1; i <= 1; i++)  {
             for(j=-1; j <= 1; j++)  {
                sumY = sumY + (int)( (*(image + x + i + 
                                (y + j)*cols)) * GY[i+1][j+1]);
             }
             }

            /*---GRADIENT MAGNITUDE APPROXIMATION----*/
            if(sumX < 0) sumX = -sumX;
            if(sumY < 0) sumY = -sumY;
            
            SUM = sumX + sumY;
          }

          if(SUM>255) SUM=255;
          if(SUM<0) SUM=0;
            
          *(output + x + y*cols) = (unsigned char)(SUM);
          }
      }
}



