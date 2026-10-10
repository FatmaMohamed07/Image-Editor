/*
====================================================
        CS213 - Assignment 1 - Part 1
        Image Processing - Console Application
====================================================

Section: S15, S16 (Monday at 11.15 am)

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
#include <cstdlib>
#include <ctime>
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

void InvertImage(Image& image) {
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < 3; k++) {
                image(i, j, k) = 255 - image(i, j, k);
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

void detect_image(Image& image){
    black_and_white(image);

    Image result(image.width, image.height);
    for (int y = 0; y < image.height - 1; y++){
        for (int x = 0; x < image.width - 1; x++){
            int current = image.getPixel(x, y, 0);
            int right = image.getPixel(x + 1, y, 0);
            int bottom = image.getPixel(x, y + 1, 0);

            if (current != right || current != bottom){
                result.setPixel(x, y, 0, 0);
                result.setPixel(x, y, 1, 0);
                result.setPixel(x, y, 2, 0);
            }

            else{
                result.setPixel(x, y, 0, 255);
                result.setPixel(x, y, 1, 255);
                result.setPixel(x, y, 2, 255);
            }
        }
    }

    image = result;
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

void bluur() {
    Image f12("fruit.bmp");
    Image blur(f12.width,f12.height) ;
    int m[13][13];
    for (int i = 0; i < f12.height; i++) {
        for (int j = 0; j < f12.width; j++) {
            for (int k = 0; k < 3; k++) {
                int sum = 0;
                for (int x = -1; x <= 11; x++) {
                    for (int y = -1; y <= 11; y++) {
                        if (x+i>=0 && x+i < f12.height && y+j < f12.width && y+j >=0 ) {
                            sum += f12.getPixel(j+y,i+x,k);
                        }
                    }
                }
                int average = sum / 169 ;
                blur.getPixel(j,i,k) = average;
            }
        }
    }
    blur.saveImage("oooooo.bmp");

}

void old_tv_effect(Image& image){
    srand(time(0));

    for (int y = 0; y < image.height; y++){
        for (int x = 0; x < image.width; x++){
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

            if (y % 2 == 0){
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

void PurpleFilterImage(Image& img) {
    for (int i=0;i<img.width;i++) {
        for (int j=0;j<img.height;j++) {
            img(i,j,0)=min(255,(int)(img(i,j,0)*1.05));
            img (i,j,1)=min(255,(int)(img(i,j,1)*0.82));
            img(i,j,2)=min(255,(int)(img(i,j,2)*1.12));
        }
    }
}

void samurai_red(){
    Image f16("samurai.jpg");
    for (int i=0;i<f16.width;i++) {
        for (int j=0;j<f16.height;j++) {
            int r = f16(i , j , 0);
            int g = f16(i , j , 1);
            int b = f16(i , j , 2);
            int blackcol = ((r+g+b)/3) ;

            int newr = 255;          //max(0, min(255,(int)(blackcol * 1.2) + 60));
            int newg = 255-blackcol; //max(0, min(255,(int)(blackcol * 1.1)+10 ));
            int newb = 255-blackcol; //max(0, min(255,(int)(blackcol * 0.5)-20 ));

            f16(i, j, 0) = newr;
            f16(i, j, 1) = newg;
            f16(i,j,2) = newb;

        }
    }
    f16.saveImage("samurai_f16.jpg");

}

void skew_image(Image& image)
{
    double angle;

    cout << "Enter skew angle: ";
    cin >> angle;

    double rad = angle * 3.14159265359 / 180.0;

    int maxShift = abs((int)(image.height * tan(rad)));

    int newWidth = image.width + maxShift;

    Image skewed(newWidth, image.height);

    for (int y = 0; y < skewed.height; y++)
    {
        for (int x = 0; x < skewed.width; x++)
        {
            skewed.setPixel(x, y, 0, 255);
            skewed.setPixel(x, y, 1, 255);
            skewed.setPixel(x, y, 2, 255);
        }
    }

    for (int y = 0; y < image.height; y++)
    {
        int shift = (int)((image.height - 1 - y) * tan(rad));

        for (int x = 0; x < image.width; x++)
        {
            int newX = x + shift;

            if (newX >= 0 && newX < skewed.width)
            {
                for (int c = 0; c < 3; c++)
                {
                    skewed.setPixel(
                        newX,
                        y,
                        c,
                        image.getPixel(x, y, c)
                    );
                }
            }
        }
    }

    image = skewed;
}

Image newimage;
void oilpainting(const Image&image) {
    int matrix[7][7];

    newimage = Image(image.width, image.height);
    for (int i = 0 ; i < image.width-7 ; i++) {
        for (int j = 0 ; j < image.height-7; j++) {
            int frequency[256]={0};

                for (int x = 0 ; x < 7 ; x++) {
                    for (int y = 0 ; y < 7; y++ ) {

                        int row = i + x ;
                        int col = j + y ;
                        int r =image(row ,col,0);
                        int g =image(row,col ,1);
                        int b =image(row ,col ,2);
                        int intesity =(r+g+b)/3;
                        matrix[x][y] = intesity;
                        frequency[intesity]++;
                    }
                }

                int maxfreq = 0;
                int d = 0;
                for (int t = 0 ; t < 256;t++) {
                    if (frequency[t] > maxfreq) {
                        maxfreq = frequency[t];
                        d = t ;
                    }
                }
                int newr = 0 , newg = 0 , newb = 0;
                for (int x = 0 ; x < 7 ; x++) {
                    for (int y = 0 ; y < 7; y++ ) {
                        int row = i + x ;
                        int col = j + y ;

                        int r =image(row ,col ,0);
                        int g =image(row, col,1);
                        int b =image(row ,col ,2);
                        int intesity =(r+g+b)/3;

                        if (intesity == d ) {
                            newr = r ;
                            newg = g ;
                            newb = b ;
                        }

                    }
                }

                newimage(i+1,j+1,0)= newr;
                newimage(i+1,j+1,1)= newg;
                newimage(i+1,j+1,2)= newb;
            }
        }
}

void loadImage(Image &image, string &filename) {

    cout << "Enter image name: ";
    cin >> filename;

    if (image.loadNewImage(filename)) {
        cout<<"Image successfully loaded"<<endl;
    }
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



int main() 
{
    string filename;

    Image image;

    loadImage(image, filename);

    while (true) 
    {
        cout<<" <<<<< Filters >>>>> "<<endl;
        cout<<"enter,your filter"<<endl;

        cout<<"1. GrayScale"<<endl;
        cout<<"2. Black_and_White"<<endl;
        cout<<"3. Invert Image"<< endl;
        cout<<"4.Frame"<<endl;
        cout<<"5. Flip"<<endl;
        cout<<"6. Rotate"<<endl;
        cout<<"7. Darken and Lighten"<<endl;
        cout<<"8. Resize"<<endl;
        cout<<"10. Detect Image Edges"<< endl;
        cout<<"11. Crop Image"<<endl;
        cout<<"12. Blur Images"<<endl;
        cout<<"14. Old TV Effect"<<endl;
        cout<<"15. Purple Filter"<<endl;
        cout<<"16. Samurai Red"<<endl;
        cout<<"17. Image Skewing"<<endl;
        cout<<"18. Oil Painting" <<endl;
        cout<<"19. save"<<endl;
        cout<<"20. Exit "<<endl;

        int choice;
        cin>>choice;

        switch (choice) 
        {
            case 1:
                grayScale(image);

                break;

            case 5: 
            {
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

            case 3:
                InvertImage(image);
                break;

            case 4:
                frame(image);
                break;

            case 6:
                rotate_image(image);
                break;

            case 7: 
            {
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

            case 10:
                detect_image(image);
                break;

            case 11:
                CropImage(image);
                break;

            case 12:
                bluur();
                break;

            case 14:
                old_tv_effect(image);
                break;    

            case 15:
                PurpleFilterImage(image);
                break;    

            case 16:
                samurai_red();
                break;

            case 17:
                skew_image(image);
                break;

            case 18:
                oilpainting(image);
                image = newimage;
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