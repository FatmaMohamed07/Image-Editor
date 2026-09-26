#include "Image_Class.h"
#include <iostream>
using namespace std;
void rotate_image(Image& image)
{
    int choice;
    cout << "Choose rotation: 90, 180, or 270: ";
    cin >> choice;

    Image rotated;    
    if(choice == 90)
    {
        rotated = Image(image.height, image.width);

        for(int y = 0; y < image.height; y++)
        {
            for(int x = 0; x < image.width; x++)
            {
                int newX = image.height - 1 - y;
                int newY = x;

                for(int c = 0; c < 3; c++)
                    rotated.setPixel(newX, newY, c, image.getPixel(x, y, c));
            }
        }
    }

    else if(choice == 180)
    {
        rotated = Image(image.width, image.height);

        for(int y = 0; y < image.height; y++)
        {
            for(int x = 0; x < image.width; x++)
            {
                int newX = image.width - 1 - x;
                int newY = image.height - 1 - y;

                for(int c = 0; c < 3; c++)
                    rotated.setPixel(newX, newY, c, image.getPixel(x, y, c));
            }
        }
    }

    else if(choice == 270)
    {
        rotated = Image(image.height, image.width);

        for(int y = 0; y < image.height; y++)
        {
            for(int x = 0; x < image.width; x++)
            {
                int newX = y;
                int newY = image.width - 1 - x;

                for(int c = 0; c < 3; c++)
                    rotated.setPixel(newX, newY, c, image.getPixel(x, y, c));
            }
        }
    }

    else
    {
        cout << "Invalid choice!" << endl;
        return;
    }

    image = rotated;    //NEW IMAGE
}

 int main()
{
    string inputFile, outputFile;

    cout << "Enter the image name: ";
    cin >> inputFile;

    Image image(inputFile);

    rotate_image(image);

    cout << "Enter the output image name: ";
    cin >> outputFile;

    image.saveImage(outputFile);

    cout << "Image saved successfully!" << "\n";

    return 0;
}   