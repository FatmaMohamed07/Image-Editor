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

void detect_image(Image& image)
{
    black_and_white(image);

    Image result(image.width, image.height);
    for (int y = 0; y < image.height - 1; y++)
    {
        for (int x = 0; x < image.width - 1; x++)
        {
            int current = image.getPixel(x, y, 0);
            int right = image.getPixel(x + 1, y, 0);
            int bottom = image.getPixel(x, y + 1, 0);

            if (current != right || current != bottom)
            {
                result.setPixel(x, y, 0, 0);
                result.setPixel(x, y, 1, 0);
                result.setPixel(x, y, 2, 0);
            }

            else
            {
                result.setPixel(x, y, 0, 255);
                result.setPixel(x, y, 1, 255);
                result.setPixel(x, y, 2, 255);
            }
        }
    }

    image = result;
}

int main()
{
    string inputFile, outputFile;

    cout << "Enter the image name: ";
    cin >> inputFile;

    Image image(inputFile);

    detect_image(image);

    cout << "Enter the output image name: ";
    cin >> outputFile;

    image.saveImage(outputFile);

    cout << "Image saved successfully!" << "\n";

    return 0;
}