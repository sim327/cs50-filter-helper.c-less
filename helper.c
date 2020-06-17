#include "helpers.h"
#include<math.h>

int cap(int value);
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
   for(int i=0;i<height;i++){
      for(int j=0;j<width;j++) {
         int blue = image[i][j].rgbtBlue;
         int green = image[i][j].rgbtGreen;
         int red = image[i][j].rgbtRed;
         float average = (red + green + blue) /3;
         int grey =round(average);
         image[i][j].rgbtBlue= grey;
         image[i][j].rgbtGreen = grey;
         image[i][j].rgbtRed = grey;

      }
   }

}
int cap(int value)

{
    if (value ==255)
       return 255;
    else
         return value;
}
// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0;i<height;i++)
    {
       for(int j=0;j<width;j++)
       {
           int originalRed = image[i][j].rgbtRed;
           int originalBlue = image[i][j].rgbtBlue;
           int originalGreen = image[i][j].rgbtGreen;
           int sepiaRed = cap(round(0.393 * originalRed + 0.769 * originalGreen + .189 * originalBlue));
           int sepiaGreen =cap(round(0.349 * originalRed + .686 * originalGreen + .168 * originalBlue));
           int sepiaBlue = cap(round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue));
           image[i][j].rgbtRed= sepiaRed;
           image[i][j].rgbtBlue=sepiaBlue;
           image[i][j].rgbtGreen = sepiaGreen;



       }
    }

}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
   for(int i=0;i<height;i++)
   {
       for(int j=0;j<round(width/2);j++)
       {

                RGBTRIPLE temp = image[i][j];
                image[i][j] = image[i][width - j];
                image[i][width - j] = temp;




       }
   }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])

{

    { for(int i=0;i<height;i++)

            for(int j = 0; j<width;j++){
              if(i == 0 && j == 0)
             {
                image[i][j].rgbtRed = round((image[i][j].rgbtRed +image[i+1][j].rgbtRed
                + image[i][j+1].rgbtRed + image[i+1][j+1].rgbtRed) / 4.0);

                image[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i+1][j].rgbtGreen
                + image[i][j+1].rgbtGreen + image[i+1][j+1].rgbtGreen) / 4.0);

                image[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i+1][j].rgbtBlue
                + image[i][j+1].rgbtBlue + image[i+1][j+1].rgbtBlue) / 4.0);
            }
            else if (i == 0 && j == width - 1)
            {
                image[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i+1][j].rgbtRed
                + image[i][j-1].rgbtRed + image[i+1][j-1].rgbtRed) / 4.0);

                image[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i+1][j].rgbtGreen
                + image[i][j-1].rgbtGreen + image[i+1][j-1].rgbtGreen) / 4.0);

                image[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i+1][j].rgbtBlue
                + image[i][j-1].rgbtBlue + image[i+1][j-1].rgbtBlue) / 4.0);
            }
            else if (i == 0)
            {
                image[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i][j-1].rgbtRed + image[i][j+1].rgbtRed
                + image[i+1][j].rgbtRed + image[i+1][j-1].rgbtRed + image[i+1][j+1].rgbtRed) / 6.0);

                image[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j+1].rgbtGreen
                + image[i+1][j].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i+1][j+1].rgbtGreen) / 6.0);

                image[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j+1].rgbtBlue
                + image[i+1][j].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j+1].rgbtBlue) / 6.0);
            }
            else if (i == height - 1 && j == 0)
            {
                image[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i-1][j].rgbtRed
                + image[i][j+1].rgbtRed + image[i-1][j+1].rgbtRed) / 4.0);

                image[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i-1][j].rgbtGreen
                + image[i][j+1].rgbtGreen + image[i-1][j+1].rgbtGreen) / 4.0);

                image[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i-1][j].rgbtBlue
                + image[i][j+1].rgbtBlue + image[i-1][j+1].rgbtBlue) / 4.0);
            }
            else if (j == 0)
            {
                image[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i-1][j].rgbtRed + image[i+1][j].rgbtRed
                + image[i][j+1].rgbtRed + image[i-1][j+1].rgbtRed + image[i+1][j+1].rgbtRed) / 6.0);

                image[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i-1][j].rgbtGreen + image[i+1][j].rgbtGreen
                + image[i][j+1].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i+1][j+1].rgbtGreen) / 6.0);

                image[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i-1][j].rgbtBlue + image[i+1][j].rgbtBlue
                + image[i][j+1].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i+1][j+1].rgbtBlue) / 6.0);
            }
            else if (i == height - 1 && j == width - 1)
            {
                image[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i-1][j].rgbtRed
                + image[i][j-1].rgbtRed + image[i-1][j-1].rgbtRed) / 4.0);

                image[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i-1][j].rgbtGreen
                + image[i][j-1].rgbtGreen + image[i-1][j-1].rgbtGreen) / 4.0);

                image[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i-1][j].rgbtBlue
                + image[i][j-1].rgbtBlue + image[i-1][j-1].rgbtBlue) / 4.0);
            }
            else if (i == height - 1)
            {
                image[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i][j-1].rgbtRed + image[i][j+1].rgbtRed
                + image[i-1][j].rgbtRed + image[i-1][j-1].rgbtRed + image[i-1][j+1].rgbtRed) / 6.0);

                image[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j+1].rgbtGreen
                + image[i-1][j].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i-1][j+1].rgbtGreen) / 6.0);

                image[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j+1].rgbtBlue
                + image[i-1][j].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i-1][j+1].rgbtBlue) / 6.0);
            }
            else if (j == width - 1)
            {
                image[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i-1][j].rgbtRed + image[i+1][j].rgbtRed
                + image[i][j-1].rgbtRed + image[i-1][j-1].rgbtRed + image[i+1][j-1].rgbtRed) / 6.0);

                image[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i-1][j].rgbtGreen + image[i+1][j].rgbtGreen
                + image[i][j-1].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i+1][j-1].rgbtGreen) / 6.0);

                image[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i-1][j].rgbtBlue + image[i+1][j].rgbtBlue
                + image[i][j-1].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i+1][j-1].rgbtBlue) / 6.0);
            }
            else
            {
                image[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i][j-1].rgbtRed + image[i][j+1].rgbtRed
                + image[i-1][j].rgbtRed + image[i-1][j-1].rgbtRed + image[i-1][j+1].rgbtRed
                + image[i+1][j].rgbtRed + image[i+1][j-1].rgbtRed + image[i+1][j+1].rgbtRed) / 9.0);

                image[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j+1].rgbtGreen
                + image[i-1][j].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i-1][j+1].rgbtGreen
                + image[i+1][j].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i+1][j+1].rgbtGreen) / 9.0);

                image[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j+1].rgbtBlue
                + image[i-1][j].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i-1][j+1].rgbtBlue
                + image[i+1][j].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j+1].rgbtBlue) / 9.0);
            }




                }


    }return;
}
