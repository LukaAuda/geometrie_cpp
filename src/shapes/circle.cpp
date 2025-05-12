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
    const int nb_points = 1000;
    double pas_angle = 2 * pi / nb_points; 

    vector<Point> points;
   
    for (int i = 0; i < nb_points; ++i) {
        double angle = i * pas_angle;
        double x = center.x + radius * cos(angle); 
        double y = center.y + radius * sin(angle); 
        points.push_back(Point(x, y));
    }

    draw_picture(points);
    }
}

}

void Circle::translate(Point T){
    center.x +=T.x;
    center.y +=T.y;
}

void Circle::resize(double ratio){
    radius *=ratio;
}

bool Circle::equals(Circle circle){
    if (radius == circle.radius && center.x == circle.center.x && center.y == circle.center.y){
        return true;
    }
    return false;
}