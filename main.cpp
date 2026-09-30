#include <complex.h>
#include <filesystem>
#include <iostream>
#include "stb_image.h"
#include "Image_Class.h"
#include <algorithm>
using namespace std;



void resize() {
     Image ref8("img.png");

     int newheight , newwidth;
     cout<<"Enter height: ";
     cin >> newheight;
     cout<<"Enter width: ";
     cin >> newwidth;
     Image newf8(newwidth,newheight);
    int hiegtscale = newheight / ref8.height;
     int widthscale = newwidth / ref8.width;
     for (int x = 0; x < newwidth; x++) {
         for (int y = 0; y < newheight; y++) {
            int oldx = x * ref8.width/newwidth;
             int oldy = y * ref8.height/newheight;
             for (int c = 0; c < 3; c++) {
                 newf8(x,y,c)=ref8(oldx,oldy,c);
             }
         }
     }
     newf8.saveImage("imgnewww.png");
 }



void frame() {
    Image orignal("House.bmp");
    int n = 20;
    int width = orignal.width;
    int height = orignal.height;
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
                    f4(j, i, k) = orignal(j - n, i - n, k);
            }
        }
    }
    f4.saveImage("Iteeepppppe.jpg");
}




