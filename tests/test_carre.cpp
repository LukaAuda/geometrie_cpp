#include <iostream>
#include <cmath>
#include <cassert>
#include "point.hpp"
#include "shapes/square.hpp"
#include "shapes/circle.hpp"

using namespace std;

int main() {
    // Création carre
    Point A(0, 0);
    Point C(2, 2);
    Square s(A, C);

    // Test longueur cote
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
    double area = s.area();
    double expectedArea = expectedSide * expectedSide;
    assert(fabs(area - 4.0) < 1e-6);
    cout << "Test 'area' réussi!" << endl;

    // Test centre
    Point center = s.center();
    assert(fabs(center.x - 1.0) < 1e-6 && fabs(center.y - 1.0) < 1e-6);
    cout << "Test 'center' réussi!" << endl;

    // Test translate
    Point translation(1, -1);
    s.translate(translation);
    assert(fabs(s.A.x - 1.0) < 1e-6 && fabs(s.A.y - -1.0) < 1e-6);
    assert(fabs(s.C.x - 3.0) < 1e-6 && fabs(s.C.y - 1.0) < 1e-6);
    cout << "Test 'translate' réussi!" << endl;

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

    return 0;
}
