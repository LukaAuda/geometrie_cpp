#include <iostream>
#include <cmath>
#include <cassert>
#include "point.hpp"
#include "shapes/triangle.hpp"
#include "draw.hpp"

using namespace std;

int main() {
    // Création de trois points pour former un triangle
    Point P(0, 0);
    Point Q(3, 0);
    Point R(0, 4);

    // Création du triangle avec les points
    Triangle t(P, Q, R);

    // Test de la méthode 'perimeter'
    double perimeter = t.perimeter();
    double expectedPerimeter = 12.0;  // Périmètre attendu : 3 + 4 + 5
    assert(fabs(perimeter - expectedPerimeter) < 1e-6);
    cout << "Test 'perimeter' réussi!" << endl;

    // Test de la méthode 'area'
    double area = t.area();
    double expectedArea = 6.0;  // Aire attendue : (0.5 * base * hauteur) = (0.5 * 3 * 4)
    assert(fabs(area - expectedArea) < 1e-6);
    cout << "Test 'area' réussi!" << endl;

    // Test de la méthode 'center'
    Point center = t.center();
    Point expectedCenter(1.0, 1.33);  // Centre attendu : (1,1.33)
    assert(fabs(center.x - expectedCenter.x) < 1e-6 && fabs(center.y - expectedCenter.y) < 1e-6);
    cout << "Test 'center' réussi!" << endl;

    // Test de la méthode 'translate'
    Point translation(2, 3);
    t.translate(translation);
    assert(fabs(t.A.x - 2) < 1e-6 && fabs(t.A.y - 3) < 1e-6);
    assert(fabs(t.B.x - 5) < 1e-6 && fabs(t.B.y - 3) < 1e-6);
    assert(fabs(t.C.x - 2) < 1e-6 && fabs(t.C.y - 7) < 1e-6);
    cout << "Test 'translate' réussi!" << endl;

    // Test de la méthode 'resize'
    double ratio = 0.5;
    t.resize(ratio);
    assert(fabs(t.A.x - 1) < 1e-6 && fabs(t.A.y - 1.5) < 1e-6);
    assert(fabs(t.B.x - 3) < 1e-6 && fabs(t.B.y - 1.5) < 1e-6);
    assert(fabs(t.C.x - 1) < 1e-6 && fabs(t.C.y - 4.0) < 1e-6);
    cout << "Test 'resize' réussi!" << endl;

    // Test de la méthode 'rotate'
    double angle = 90;  // Rotation de 90 degrés
    t.rotate(angle);
    assert(fabs(t.A.x + 1.5) < 1e-6 && fabs(t.A.y - 1) < 1e-6);
    assert(fabs(t.B.x - 1.5) < 1e-6 && fabs(t.B.y - 3) < 1e-6);
    assert(fabs(t.C.x - 1.0) < 1e-6 && fabs(t.C.y - 1.0) < 1e-6);
    cout << "Test 'rotate' réussi!" << endl;

    cout << "Tous les tests ont réussi!" << endl;

    return 0;
}
