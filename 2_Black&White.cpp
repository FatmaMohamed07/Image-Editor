#include "Image_Class.h"
#include <iostream>
using namespace std;
void black_and_white(Image& image)
{
    for(int y = 0; y < image.height; y++)
    {
        for(int x = 0; x < image.width; x++)
        {
            int R = image.getPixel(x, y, 0);
            int G = image.getPixel(x, y, 1);
            int B = image.getPixel(x, y, 2);

            int grayscale = 0.299 * R + 0.587 * G + 0.114 * B;
            if(grayscale < 128) 
            { 
                image.setPixel(x, y, 0, 0);
                image.setPixel(x, y, 1, 0);
                image.setPixel(x, y, 2, 0);
            }

            else
            {
                image.setPixel(x, y, 0, 255);
                image.setPixel(x, y, 1, 255);
                image.setPixel(x, y, 2, 255);
            }
        }
    }
}

int main()
{
    string inputFile, outputFile;

    cout << "Enter the image name: ";
    cin >> inputFile;

    Image image(inputFile);

    black_and_white(image);

    cout << "Enter the output image name: ";
    cin >> outputFile;

    image.saveImage(outputFile);

    cout << "Image saved successfully!" << "\n";

    return 0;
}