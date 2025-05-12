#include "point.hpp"
#include "shapes/circle.hpp"
#include <iostream>
#include <cmath>
#define pi 3.14159265358979323846

using namespace std;

Circle::Circle(double r, Point c) : radius(r), center(c) {}

double Circle::circumference(){
    return 2 * pi * radius;
}

double Circle::area(){
    return pi * radius * radius;
}

void Circle::draw(){
    cout << "cercle de centre (" << center.x << ", " << center.y << ") et de rayon " << radius << endl;
}

void Circle::translate(Point T){
    center.x += T.x;
    center.y += T.y;
}

void Circle::resize(double ratio){
    radius *= ratio;
}

bool Circle::equals(Circle circle){
    return radius == circle.radius && center.x == circle.center.x && center.y == circle.center.y;
}