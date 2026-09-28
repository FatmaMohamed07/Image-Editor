#include <complex.h>
#include <filesystem>
#include <iostream>
#include "stb_image.h"
#include "Image_Class.h"
using namespace std;

void frame() {
    Image orignal("House.bmp");
    int n = 20;
    int width = orignal.width;
    int height = orignal.height;
    int newhieght = 2*n +height;
    int newwidth =  2*n +width;

    Image f4(newwidth , newhieght);

    for (int i = 0; i < newhieght; ++i) {
        for (int j = 0; j < newwidth; ++j) {
            if (i>=height + n || i <n || j < n || j>=width +n) {
                f4(i,j,0)=255;
                f4(i,j,1)=0;
                f4(i,j,2)=0;
                for (int k = 0; k < 3; ++k) {
                    //f4(i, j, k)=770;
                }
            }else {
                int orow = i-n;
                int ocol = j-n;
                for (int k = 0; k < 3; ++k) {
                    f4(i, j, k)=orignal(orow,ocol,k);

                }
            }
        }

    }
    f4 .saveImage("lteeeppppppe.bmp");
}

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




