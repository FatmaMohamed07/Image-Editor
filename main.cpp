#include "Image_Class.h"
#include <iostream>
#include <algorithm>
using namespace std;
Image img;

void LightenDarkenImage(bool isLighten) {
    img.loadNewImage("house4.jpeg");
    for (int i=0;i<img.width;i++) {
        for (int j=0;j<img.height;j++) {
            for (int k=0;k<3;k++) {
               if (isLighten) {
                   img(i,j,k)=min(255,(int)(img(i,j,k)*1.5));
               }else {
                   img(i,j,k)=max(0,(int)(img(i,j,k)*0.5));
               }

            }
        }
    }

    img.saveImage("Newhouse4.jpeg");
}
void CropImage() {
    int x,y,w,h; cin>>x>>y>>w>>h;
    img.loadNewImage("baby0.jpeg");
    cout<<img.width<<" "<<img.height<<endl;
    if (!(x>=0&&y>=0&&x+w<=img.width&&y+h<=img.height) ){
        // cout<<img.width<<" "<<img.height<<endl;
        cout<<"Error"<<endl;
        return;
    }
    Image cutted(w,h);
    for (int i=0;i<w;i++) {
        for (int j=0;j<h;j++) {
            for (int k=0;k<3;k++) {
                cutted(i,j,k)=img(x+i,y+j,k);
            }
        }
    }
    cutted.saveImage("Newbaby0.jpeg");
}

int main() {
     cout <<"Select Your Choice:"<<endl;

     cout<<"7. Darken Or Lighten Image"<<endl;
     cout<<"11. Crop Image"<<endl;

     int choice; cin>>choice;
     switch(choice) {

         case 7:
             cout<<"1. lighten"<<endl;
             cout<<"2. darken"<<endl;
             cout<<"choose 1 or 2"<<endl;
             int choice; cin>>choice;
             LightenDarkenImage(choice==1);
             break;

         case 11:
         CropImage();
         break;

         default:
             cout<<"invalid Choice"<<endl;
     }

    return 0;
    }