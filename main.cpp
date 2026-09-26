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

void f8() {
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

int main() {
    int choice ;
    cout<<"Enter choice: ";
    cin>>choice;

}

