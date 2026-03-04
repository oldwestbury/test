#include <iostream>
#include <algorithm>
#include "bmp.hpp"

void draw_rectangle(BMP &bmp,int x, int y, int l, int h, int b){
    for(int i=0;i<=l;i++){
        for(int ii=0;ii<=b;ii++){
        bmp.set_pixel(i+x, y+ii, 0,0,0);
        bmp.set_pixel(i+x, y+h-ii, 0,0,0);
        }
    }
    for(int j=0;j<=h;j++){
        for(int ii=0;ii<=b;ii++){
            bmp.set_pixel(x+ii, y+j, 0,0,0);
            bmp.set_pixel(x+l-ii, y+j, 0,0,0);
        }
    }
}
color mix_color(const color& c1, const color& c2, double alpha) {
    color m;
    m.r=alpha* c1.r+(1-alpha)*c2.r;
    m.g=alpha* c1.g+(1-alpha)*c2.g;
    m.b=alpha* c1.b+(1-alpha)*c2.b;
    return m;
}


void draw_h_line(BMP &bmp, int x1, int x2, int y, const color &c1, const color &c2){
    if(x1>x2) std::swap(x1,x2);
    float distance=(float)abs(x2-x1);
    for(int x=x1;x<x2;x++){
        double r=(x-x1)/distance; //BUG
        color m=mix_color(c1, c2, r);
        bmp.set_pixel(x, y, m.r, m.g, m.b);
    }

}

int main(){

BMP img(500,500);
//draw_rectangle(img, 3,5,100,100,5);
draw_h_line(img,1,500,200, color(255,0,0), color(0,255,0) );
img.write("small.bmp");


}
