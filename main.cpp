#include "include/draw.hpp"
#include "include/point.hpp"
#include "include/shapes/triangle.hpp"
#include "include/shapes/square.hpp"
#include "include/shapes/circle.hpp"
#include <iostream>
#include <cmath>
#include <cassert>
#include <vector>
#define pi 3.14159265358979323846

using namespace std;

int main() {
    // Définir des points dans un vecteur
    vector<Point> points = {
        Point(0, 0),
        Point(100, 0),
        Point(100, 100),
        Point(0, 100),
        Point(0, 0)
    };
    
     //Partie 1 : Tests sur le cercle 
     // Création d’un cercle 
     Point center(0, 0);
     Circle c(5.0, center);
 
     // Test circonference
     double circumference = c.circumference();
     double expectedCircumference = 2 * pi * 5.0;
     assert(fabs(circumference - expectedCircumference) < 1e-6);
     cout << "Test 'circumference' réussi!" << endl;
 
     // Test aire
     double area = c.area();
     double expectedArea = pi * 25.0; 
     assert(fabs(area - expectedArea) < 1e-6);
     cout << "Test 'area' réussi!" << endl;
 
     // Test translation
     Point translation(3, 4);
     c.translate(translation);
     assert(fabs(c.center.x - 3) < 1e-6 && fabs(c.center.y - 4) < 1e-6);
     cout << "Test 'translate' réussi!" << endl;
 
     // Test ratio
     double ratio = 2.0;
     c.resize(ratio);
     assert(fabs(c.radius - 10.0) < 1e-6);
     cout << "Test 'resize' réussi!" << endl;
 
     // Test egalite
     Circle otherCircle(10.0, Point(3, 4));
     assert(c.equals(otherCircle));
     cout << "Test 'equals' réussi!" << endl;
 
 
     cout << "Tous les tests du cercle ont réussi!" << endl;

    // Partie 2 : Tests sur le carre
    // Création d’un carré 
    Point A(0, 0);
    Point C(2, 2);
    Square s(A, C);

    // Test cotes
    double side = s.side();  
    double expectedSide = 2.0;
    assert(fabs(side - expectedSide) < 1e-6);
    cout << "Test 'side' réussi!" << endl;

    // Test perimetre
    double perimeter = s.perimeter();
    double expectedPerimeter = 4 * expectedSide;
    assert(fabs(perimeter - 8.0) < 1e-6);
    cout << "Test 'perimeter' réussi!" << endl;

    // Test aire
    double area2 = s.area();
    double expectedArea2 = expectedSide * expectedSide;
    assert(fabs(area2 - 4.0) < 1e-6);
    cout << "Test 'area2' réussi!" << endl;

    // Test centre
    Point center2 = s.center();
    assert(fabs(center2.x - 1.0) < 1e-6 && fabs(center2.y - 1.0) < 1e-6);
    cout << "Test 'center2' réussi!" << endl;

    // Test translation
    Point translation2(1, -1);
    s.translate(translation2);
    assert(fabs(s.A.x - 1.0) < 1e-6 && fabs(s.A.y - -1.0) < 1e-6);
    assert(fabs(s.C.x - 3.0) < 1e-6 && fabs(s.C.y - 1.0) < 1e-6);
    cout << "Test 'translate2' réussi!" << endl;

    // Test resize
    s.resize(0.5);  
    assert(fabs(s.side() - 1.0) < 1e-6);  
    cout << "Test 'resize' réussi!" << endl;

    // Test rotation
    s.rotate(M_PI / 2);  
    Point newCenter = s.center();
    assert(fabs(newCenter.x - 2.0) < 1e-6 && fabs(newCenter.y == 0.0) < 1e-6);
    cout << "Test 'rotate' réussi!" << endl;

    // Test egalite
    Square s2(s.A, s.C);
    assert(s.equals(s2));
    cout << "Test 'equals' réussi!" << endl;

    // Test inscribedCircle
    Circle inCircle = s.inscribedCircle();
    assert(fabs(inCircle.radius - s.side() / 2) < 1e-6);
    assert(fabs(inCircle.center.x - s.center().x) < 1e-6 && fabs(inCircle.center.y - s.center().y) < 1e-6);
    cout << "Test 'inscribedCircle' réussi!" << endl;

    // Test circumscribedCircle
    Circle outCircle = s.circumscribedCircle();
    double expectedRadius = sqrt(2) * (s.side() / 2);  
    assert(fabs(outCircle.radius - expectedRadius) < 1e-6);
    cout << "Test 'circumscribedCircle' réussi!" << endl;

    cout << "Tous les tests du carré ont réussi!" << endl;

    // Partie 3 : Tests sur le triangle
    // Création points triangle
    Point P(0, 0);
    Point Q(3, 0);
    Point R(0, 4);

    // Création du triangle avec les points
    Triangle t(P, Q, R);

    // Test de la méthode 'perimeter'
    double perimeter3 = t.perimeter();
    double expectedPerimeter3 = 12.0;  // Périmètre attendu : 3 + 4 + 5
    assert(fabs(perimeter3 - expectedPerimeter3) < 1e-6);
    cout << "Test 'perimeter3' réussi!" << endl;

    // Test aire
    double area3 = t.area();
    double expectedArea3 = 6.0;  
    assert(fabs(area3 - expectedArea3) < 1e-6);
    cout << "Test 'area3' réussi!" << endl;

    // Test centre
    Point center3 = t.center();
    Point expectedCenter(1.0, 1.333333);  
    assert(fabs(center.x - expectedCenter.x) < 1e-6 && fabs(center.y - expectedCenter.y) < 1e-6);
    cout << "Test 'center3' réussi!" << endl;

    // Test translation
    Point translation3(2, 3);
    t.translate(translation3);
    assert(fabs(t.A.x - 2) < 1e-6 && fabs(t.A.y - 3) < 1e-6);
    assert(fabs(t.B.x - 5) < 1e-6 && fabs(t.B.y - 3) < 1e-6);
    assert(fabs(t.C.x - 2) < 1e-6 && fabs(t.C.y - 7) < 1e-6);
    cout << "Test 'translate' réussi!" << endl;

    // Test resize
    double ratio3 = 0.5;
    t.resize(ratio3);
    assert(fabs(t.A.x - 1) < 1e-6 && fabs(t.A.y - 1.5) < 1e-6);
    assert(fabs(t.B.x - 3) < 1e-6 && fabs(t.B.y - 1.5) < 1e-6);
    assert(fabs(t.C.x - 1) < 1e-6 && fabs(t.C.y - 4.0) < 1e-6);
    cout << "Test 'resize' réussi!" << endl;

    // Test rotation
    double angle = 90;  
    t.rotate(angle);
    assert(fabs(t.A.x + 1.5) < 1e-6 && fabs(t.A.y - 1) < 1e-6);
    assert(fabs(t.B.x - 1.5) < 1e-6 && fabs(t.B.y - 3) < 1e-6);
    assert(fabs(t.C.x - 1.0) < 1e-6 && fabs(t.C.y - 1.0) < 1e-6);
    cout << "Test 'rotate' réussi!" << endl;

    
    cout << "Tous les tests ont réussi!" << endl;

    return 0;
}
