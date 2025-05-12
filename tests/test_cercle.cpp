#include <iostream>
#include <cmath>
#include <cassert>
#include "point.hpp"
#include "shapes/circle.hpp"

#define pi 3.14159265358979323846

using namespace std;

int main() {
    // Création d’un cercle de rayon 5 centré en (0, 0)
    Point center(0, 0);
    Circle c(5.0, center);

    // Test de la méthode 'circumference'
    double circumference = c.circumference();
    double expectedCircumference = 2 * pi * 5.0;
    assert(fabs(circumference - expectedCircumference) < 1e-6);
    cout << "Test 'circumference' réussi!" << endl;

    // Test de la méthode 'area'
    double area = c.area();
    double expectedArea = pi * 25.0; // π * r²
    assert(fabs(area - expectedArea) < 1e-6);
    cout << "Test 'area' réussi!" << endl;

    // Test de la méthode 'translate'
    Point translation(3, 4);
    c.translate(translation);
    assert(fabs(c.center.x - 3) < 1e-6 && fabs(c.center.y - 4) < 1e-6);
    cout << "Test 'translate' réussi!" << endl;

    // Test de la méthode 'resize'
    double ratio = 2.0;
    c.resize(ratio);
    assert(fabs(c.radius - 10.0) < 1e-6);
    cout << "Test 'resize' réussi!" << endl;

    // Test de la méthode 'equals'
    Circle otherCircle(10.0, Point(3, 4));
    assert(c.equals(otherCircle));
    cout << "Test 'equals' réussi!" << endl;

    // (Optionnel) Test visuel de 'draw' – affiche les points du cercle
    // c.draw(); // Décommente pour visualiser les points du cercle

    cout << "Tous les tests du cercle ont réussi!" << endl;

    return 0;
}
