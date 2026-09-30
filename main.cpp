/*
====================================================
        CS213 - Assignment 1 - Part 1
        Image Processing - Console Application
====================================================

Section: S15, S16 (Monday at 11.15 am)*

Team Members:
1. Rana Amr Mohamed Ismail Elgendy        - ID: 20250231
2. Fatma Mohamed Hassan Salama            - ID: 20250464
3. Menna talla Khaled Said                - ID: 20250672
4. Menna Hosam Shahat Farag               - ID: 20251433

Filters:
1. Filter 1  - Grayscale Conversion                  - Rana Amr Mohamed Ismail Elgendy
2. Filter 2  - Black and White                       - Fatma Mohamed Hassan Salama
3. Filter 4  - Adding a Frame to the Picture         - Menna Hosam Shahat Farag
4. Filter 5  - Flip Image                            - Rana Amr Mohamed Ismail Elgendy
5. Filter 6  - Rotate Image                          - Fatma Mohamed Hassan Salama
6. Filter 7  - Darken and Lighten Image              - Menna talla Khaled Said
7. Filter 8  - Resizing Images                       - Menna Hosam Shahat Farag
8. Filter 11 - Crop Images                           - Menna talla Khaled Said

Description:
This program is a console-based image processing application.
It allows the user to load an image, apply different filters,
save the modified image, load another image, and exit the program.
====================================================
*/

#include <cstdlib>
#include <complex.h>
#include <iostream>
#include "Image_Class.h"
using namespace std;

void grayScale(Image &image) {
    for (int i=0 ; i < image.width ; i++) {
        for (int j=0 ; j < image.height ; j++) {
            unsigned int avg = 0;
            for (int k=0 ; k < image.channels ; k++) {
                avg += image(i,j,k);
            }
            avg = avg/3;
            for (int k=0 ; k < image.channels ; k++) {
                image(i,j,k) = avg;
            }
        }
    }
}

void flipHorizontal(Image &image) {
    for (int i=0 ; i < image.width/2 ; i++) {
        for (int j=0 ; j < image.height ; j++) {
            for (int k=0 ; k < image.channels ; k++) {
                int temp = image(i,j,k);
                image(i,j,k)= image(image.width - 1 - i,j,k);
                image(image.width - 1 -i ,j,k)=temp;
            }
        }
    }
}

void flipVertical(Image &image) {
    for (int i=0 ; i < image.width ; i++) {
        for (int j=0 ; j < image.height/2 ; j++) {
            for (int k=0 ; k < image.channels ; k++) {
                int temp = image(i,j,k);
                image(i,j,k)= image(i,image.height-1-j,k);
                image(i,image.height-1-j,k)=temp;
            }
        }
    }
}

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

void frame(Image &image) {

    int n = 40;
    int width = image.width;
    int height = image.height;
    int newhieght = 2*n + height;
    int newwidth  = 2*n + width;

    cout << "Choose frame style:\n";
    cout << " 1. color\n";
    cout << " 2. Double frame\n";
    cout << "Your style: ";
    int style;
    cin >> style;

    int r = 0, g = 0, b = 0;

        cout << "Choose a color for the frame:\n";
        cout << " 1. Red\n 2. Green\n 3. Blue\n";
        cout << " 4. Yellow\n 5. White\n 6. Black\n 7.Custom (RGB)\n";
        cout << "Your choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {r = 255; g = 0;   b = 0;
        }
        else if (choice == 2) { r = 0;   g = 255; b = 0;   }
        else if (choice == 3) { r = 0;   g = 0;   b = 255; }
        else if (choice == 4) { r = 255; g = 255; b = 0;   }
        else if (choice == 5) { r = 255; g = 255; b = 255; }
        else if (choice == 6) { r = 0;   g = 0;   b = 0;   }
        else {
            cout << "Enter Red   (0-255): "; cin >> r;
            cout << "Enter Green (0-255): "; cin >> g;
            cout << "Enter Blue  (0-255): "; cin >> b;
        }


    Image f4(newwidth, newhieght);
    for (int i = 0; i < newhieght; ++i) {
        for (int j = 0; j < newwidth; ++j) {

            if (i < n || i >= height + n || j < n || j >= width + n) {
                int R = r, G = g, B = b;
                int size = 5;
                int d = min(min(i, newhieght - 1 - i), min(j, newwidth - 1 - j));


                 if (style == 2) {
                    if (d >= 2*n/3)      { R = 255 - r; G = 255 - g; B = 255 - b; }
                    else if (d >= n/3)   { R = 255;     G = 255;     B = 255;     }
                }

                f4(j, i, 0) = R;
                f4(j, i, 1) = G;
                f4(j, i, 2) = B;
            }
            else {
                for (int k = 0; k < 3; ++k)
                    f4(j, i, k) = image(j - n, i - n, k);
            }
        }
    }
    image = f4;
}

void rotate_image(Image& image){

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

    image = rotated;
}

void Lighten(Image& image) {

    for (int i=0;i<image.width;i++) {
        for (int j=0;j<image.height;j++) {
            for (int k=0;k<3;k++) {
                image(i,j,k)=min(255,(int)(image(i,j,k)*1.5));
            }
        }
    }
}

void Darken(Image& image) {

    for (int i=0;i<image.width;i++) {
        for (int j=0;j<image.height;j++) {
            for (int k=0;k<3;k++) {
                image(i,j,k)=max(0,(int)(image(i,j,k)*0.5));
            }
        }
    }
}

void resize(Image& image) {

    int newheight , newwidth;

    cout<<"Enter height: ";
    cin >> newheight;

    cout<<"Enter width: ";
    cin >> newwidth;

    if (newheight <= 0 || newwidth <= 0) {
        cout << "Invalid dimensions!" << endl;
        return;
    }

    Image newf8(newwidth,newheight);

    for (int x = 0; x < newwidth; x++) {
        for (int y = 0; y < newheight; y++) {

            int oldx = x * image.width/newwidth;
            int oldy = y * image.height/newheight;

            for (int c = 0; c < 3; c++) {
                newf8(x,y,c)=image(oldx,oldy,c);
            }
        }
    }

    image = newf8;
}

void CropImage(Image &image) {

    int x, y, w, h;

    cout << "Enter x ,y ,width, height: ";
    cin >> x >> y >> w >> h;

    if (w <= 0 || h <= 0) {
        cout << "Error" << endl;
        return;
    }
    if (!(x >= 0 && y >= 0 &&
          x + w <= image.width &&
          y + h <= image.height)) {
        cout << "Error" << endl;
        return;
    }

    Image cutted(w, h);

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            for (int k = 0; k < 3; k++) {
                cutted(i, j, k) = image(x + i, y + j, k);}
        }
    }

    image = cutted;
}

bool saveImage(Image &image, string &filename) {

    int choice;

    cout << "1. Save with same filename" << endl;
    cout << "2. Save with new filename" << endl;
    cin >> choice;

    if (choice == 1) {

        image.saveImage(filename);
        cout << "Image saved!" << endl;
        return true;
    }
    else if (choice == 2) {

        string newName;

        cout << "Enter new filename: ";
        cin >> newName;

        image.saveImage(newName);
        filename = newName;

        cout << "Image saved!" << endl;
        return true;
    }

    return false;
}

void loadImage(Image &image, string &filename) {

    cout << "Enter image name: ";
    cin >> filename;

    if (image.loadNewImage(filename)) {
        cout<<"Image successfully loaded"<<endl;
    }
}



int main() {

    string filename;

    Image image;

    loadImage(image, filename);

    while (true) {

        cout<<" <<<<< Filters >>>>> "<<endl;
        cout<<"enter,your filter"<<endl;

        cout<<"1. GrayScale"<<endl;
        cout<<"2. Black_and_White"<<endl;
        cout<<"4.Frame"<<endl;
        cout<<"5. Flip"<<endl;
        cout<<"6. Rotate"<<endl;
        cout<<"7. Darken and Lighten"<<endl;
        cout<<"8. Resize"<<endl;
        cout<<"11. Crop Image"<<endl;
        cout<<"19. save"<<endl;
        cout<<"20. Exit "<<endl;

        int choice;
        cin>>choice;

        switch (choice) {

            case 1:
                grayScale(image);

                break;

            case 5: {
                cout<<"1. Vertical"<<endl;
                cout<<"2. Horizontal"<<endl;

                int flipChoice;
                cin>>flipChoice;

                if (flipChoice == 1) {
                    flipVertical(image);
                }
                else if (flipChoice == 2) {
                    flipHorizontal(image);
                }
                else {
                    cout << "Invalid choice!" << endl;
                }

                break;
            }

            case 2:
                black_and_white(image);
                break;

            case 4:
                frame(image);
                break;

            case 6:
                rotate_image(image);
                break;

            case 7: {

                cout<<"1. lighten"<<endl;
                cout<<"2. darken"<<endl;
                cout<<"choose 1 or 2"<<endl;

                int x;
                cin>>x;

                if (x==1)
                    Lighten(image);
                else if (x==2)
                    Darken(image);
                else
                    cout << "Invalid choice!" << endl;

                break;
            }

            case 8:
                resize(image);
                break;

            case 11:
                CropImage(image);
                break;

            case 19:
                saveImage(image,filename);
                break;

            case 20:
                exit(0);

            default:
                cout<<"invalid Choice"<<endl;
        }
    }
    return 0;
}
