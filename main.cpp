#include "Image_Class.h"
#include <iostream>
using namespace std;


void grayScale(Image &image){
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

int main() {
   Image img;
   string filename;

   cout<<"Enter image: ";
   cin>>filename;

   if (img.loadNewImage(filename)) {
      cout<<"Image successfully loaded"<<endl;
   }

   int filter;
   string filterType;
   cout<<"Filters:" << endl;
   cout << "1 : Grayscale" << endl;
   cout << "2 : Flip" << endl;
   cout<<"Enter filter number : " << endl;
   cin>>filter;
   if (filter == 2){
      cout << "Vertical or Horizontal"<< endl;
      cout << "Enter filter type : ";
      cin>>filterType;
   }

   switch (filter) {
      case 1:
         grayScale(img);
         img.saveImage("output.jpg");
         break;
      case 2:
         if (filterType == "Vertical") {
            flipVertical(img);
         }
         else if (filterType == "Horizontal") {
            flipHorizontal(img);
         }
         img.saveImage("output.jpg");
         break;
   }
}
