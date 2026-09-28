#include "Image_Class.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void old_tv_effect(Image& image)
{
    srand(time(0));

    for (int y = 0; y < image.height; y++)
    {
        for (int x = 0; x < image.width; x++)
        {
            int R = image.getPixel(x, y, 0);
            int G = image.getPixel(x, y, 1);
            int B = image.getPixel(x, y, 2);

            R = R * 80 / 100;
            G = G * 80 / 100;
            B = B * 80 / 100;

            int noise = rand() % 21 - 10;

            R += noise;
            G += noise;
            B += noise;

            if (y % 2 == 0)
            {
                R = R * 70 / 100;
                G = G * 70 / 100;
                B = B * 70 / 100;
            }

            if (R < 0) R = 0;
            if (R > 255) R = 255;

            if (G < 0) G = 0;
            if (G > 255) G = 255;

            if (B < 0) B = 0;
            if (B > 255) B = 255;

            image.setPixel(x, y, 0, R);
            image.setPixel(x, y, 1, G);
            image.setPixel(x, y, 2, B);
        }
    }
}

int main()
{
    string inputFile, outputFile;

    cout << "Enter the image name: ";
    cin >> inputFile;

    Image image(inputFile);

    old_tv_effect(image);

    cout << "Enter the output image name: ";
    cin >> outputFile;

    image.saveImage(outputFile);

    cout << "Image saved successfully!" << "\n";

    return 0;
}