#include <iostream>
#include <cmath>
#include <cassert>
#include "point.hpp"
#include "shapes/square.hpp"
#include "shapes/circle.hpp"

using namespace std;

int main() {
    // Création d’un carré avec les points A(0, 0) et C(2, 2) => carré de côté √2 * √2 = 2
    Point A(0, 0);
    Point C(2, 2);
    Square s(A, C);

    // Test de la méthode 'side'
    double side = s.side();  // diagonale = 2√2, côté = 2
    double expectedSide = 2.0;
    assert(fabs(side - expectedSide) < 1e-6);
    cout << "Test 'side' réussi!" << endl;

    // Test de la méthode 'perimeter'
    double perimeter = s.perimeter();
    double expectedPerimeter = 4 * expectedSide;
    assert(fabs(perimeter - 8.0) < 1e-6);
    cout << "Test 'perimeter' réussi!" << endl;

    // Test de la méthode 'area'
    double area = s.area();
    double expectedArea = expectedSide * expectedSide;
    assert(fabs(area - 4.0) < 1e-6);
    cout << "Test 'area' réussi!" << endl;

    // Test de la méthode 'center'
    Point center = s.center();
    assert(fabs(center.x - 1.0) < 1e-6 && fabs(center.y - 1.0) < 1e-6);
    cout << "Test 'center' réussi!" << endl;

    // Test de la méthode 'translate'
    Point translation(1, -1);
    s.translate(translation);
    assert(fabs(s.A.x - 1.0) < 1e-6 && fabs(s.A.y - -1.0) < 1e-6);
    assert(fabs(s.C.x - 3.0) < 1e-6 && fabs(s.C.y - 1.0) < 1e-6);
    cout << "Test 'translate' réussi!" << endl;

    // Test de la méthode 'resize'
    s.resize(0.5);  // réduction à 50%
    assert(fabs(s.side() - 1.0) < 1e-6);  // nouveau côté : 1
    cout << "Test 'resize' réussi!" << endl;

    // Test de la méthode 'rotate'
    s.rotate(M_PI / 2);  // rotation de 90° autour du centre
    // On teste simplement que le centre reste inchangé après rotation
    Point newCenter = s.center();
    assert(fabs(newCenter.x - 2.0) < 1e-6 && fabs(newCenter.y == 0.0) < 1e-6);
    cout << "Test 'rotate' réussi!" << endl;

    // Test de la méthode 'equals'
    Square s2(s.A, s.C);
    assert(s.equals(s2));
    cout << "Test 'equals' réussi!" << endl;

    // Test de la méthode 'inscribedCircle'
    Circle inCircle = s.inscribedCircle();
    assert(fabs(inCircle.radius - s.side() / 2) < 1e-6);
    assert(fabs(inCircle.center.x - s.center().x) < 1e-6 && fabs(inCircle.center.y - s.center().y) < 1e-6);
    cout << "Test 'inscribedCircle' réussi!" << endl;

    // Test de la méthode 'circumscribedCircle'
    Circle outCircle = s.circumscribedCircle();
    double expectedRadius = sqrt(2) * (s.side() / 2);  // moitié de la diagonale
    assert(fabs(outCircle.radius - expectedRadius) < 1e-6);
    cout << "Test 'circumscribedCircle' réussi!" << endl;

    cout << "Tous les tests du carré ont réussi!" << endl;

    return 0;
}
