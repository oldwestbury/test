#include <iostream>

#include "bmp.hpp"

void draw_rectangle(BMP &bmp,int x, int y, int l, int h, int b){
    for(int i=0;i<l;i++){
        for(int ii=0;ii<b;ii++){
        bmp.set_pixel(i+x, y+ii, 0,0,0);
        bmp.set_pixel(i+x, y+h-ii, 0,0,0);
        }
    }
    for(int j=0;j<h;j++){
        for(int ii=0;ii<b;ii++){
            bmp.set_pixel(x+ii, y+j, 0,0,0);
            bmp.set_pixel(x+l-ii, y+j, 0,0,0);
        }
    }
}
int main(){

BMP img(20,20);
draw_rectangle(img, 3,5,10,10,2);
img.write("small.bmp");


}
