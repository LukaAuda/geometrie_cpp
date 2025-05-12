#include "point.hpp"
#include "shapes/square.hpp"
#include<cmath>
#include "shapes/circle.hpp"
#include <vector>
#include "draw.hpp"
#include "shapes.hpp"



using namespace std;

Square::Square(Point P, Point R) : A(P), C(R) {};

double Square::side(){
    double x = C.x - A.x;
    double y = C.y - A.y;
    double diagonal = std::sqrt(x*x + y*y);
    return diagonal / std::sqrt(2) ;

}

double Square:: perimeter(){
    double s = side();
    return 4 * s;
}

double Square::area(){
    double s = side() ;
    return s * s;
    
}

Point Square::center(){
    Point O;
     O.x = (C.x + A.x)/2;
     O.y = (C.y + A.y)/2;
     return O;

}

void Square::draw(){
    Point O = center();
    double x = O.x - C.x;
    double y = O.y - C.y;
    Point D (O.x + y ,O.y - x) ;
    Point B (O.x - y,O.y + x);

    vector<Point> points = {
		Point(A.x, A.y),
		Point(B.x, B.y),
		Point(C.x, C.y),
		Point(D.x, D.y),
		Point(A.x, A.y)

	};
    draw_picture(points);
}

void Square::translate(Point T){
    A.x = A.x + T.x;
    A.y = A.y + T.y;
    C.x = C.x + T.x;
    C.y = C.y + T.y;

}

void Square::resize(double ratio){
    Point O = center();
    A.x = O.x + (A.x - O.x) * ratio;
    A.y = O.y + (A.y - O.y) * ratio;
    C.x = O.x + (C.x - O.x) * ratio;
    C.y = O.y + (C.y - O.y) * ratio;
}

void Square::rotate(double angle){
    Point O = center();
    Point F (A.x-O.x ,A.y-O.y);
    Point G (C.x-O.x,C.y-O.y);
    A.x = F.x * cos(angle) - F.y * sin(angle);
    A.y = F.x * sin(angle) + F.y * cos(angle);
    C.x = G.x * cos(angle) - G.y * sin(angle);
    C.y = G.x * sin(angle) + G.y * cos(angle);
    A.x += O.x;
    A.y += O.y;
    C.x += O.x;
    C.y += O.y;
}

bool Square::equals(Square square)
{ if(A.x == square.A.x && A.y == square.A.y && C.x == square.C.x && C.y == square.C.y ){
    return true ;
}
    return false;
}

Circle Square::inscribedCircle(){ 
    Point O = center();
    double r = side() / 2;
    return Circle(r, O) ;
}

Circle Square::circumscribedCircle() {
    Point O = center();
    double x = C.x - O.x;
    double y = C.y - O.y;
    double rayon = std::sqrt(x*x + y*y);
    return Circle(rayon, O);
}

