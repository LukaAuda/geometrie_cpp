#include "point.hpp"
#include "shapes/triangle.hpp"
#include "draw.hpp"
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

Triangle::Triangle(Point P, Point Q, Point R) : A(P), B(Q), C(R) {}

double Triangle::  perimeter(){
    double coteAB = sqrt(pow(B.x - A.x, 2)+ pow(B.y-A.y, 2));
    double coteBC = sqrt(pow(C.x - B.x, 2)+ pow(C.y-B.y, 2));
    double coteCA = sqrt(pow(A.x - C.x, 2)+ pow(A.y-C.y, 2));

    return coteAB + coteBC + coteCA;
}

double Triangle::  area(){
    return (0.5 * abs(A.x*(B.y-C.y)+B.x*(C.y - A.y)+C.x*(A.y-B.y)));
}

Point Triangle:: center(){
    Point centre = Point(0,0);
    centre.x = (A.x + B.x + C.x)/3;
    centre.y = (A.y + B.y + C.y)/3;

    return centre;
}

void Triangle:: draw(){
    vector<Point> points = {A, B, C, A};
    draw_picture(points);
}

void Triangle:: translate(Point T){
    A.x = A.x + T.x;
    B.x = B.x + T.x;
    C.x = C.x + T.x;
    A.y = A.y + T.y;
    B.y = B.y + T.y;
    C.y = C.y + T.y;
}

void Triangle:: resize(double ratio){
    Point M = center();
    A.x += A.x - ratio*M.x;
    B.x += B.x - ratio*M.x;
    C.x += C.x - ratio*M.x;
    A.y += A.y - ratio*M.y;
    B.y += B.y - ratio*M.y;
    C.y += C.y - ratio*M.y;

    for(int i = 0; i < ratio; i++){
        translate(M);
    }
}


Point rotationPoint(Point K, double degre){
        double Kx = K.x;
        double Ky = K.y;
        double teta = degre * M_PI /180;
        K.x = Kx* cos(teta) - Ky* sin(teta);
        K.y = Kx* sin(teta) + Ky* cos(teta);
        return K; 
    }

void Triangle:: rotate(double angle){
    Point M = center();
    Point moinsM = Point(-M.x, -M.y);

    translate(moinsM);

    A = rotationPoint(A, angle);
    B = rotationPoint(B, angle);
    C = rotationPoint(C, angle);

    translate(M);
}
