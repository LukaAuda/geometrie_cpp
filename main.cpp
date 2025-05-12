#include "include/draw.hpp"
#include "include/point.hpp"
#include "include/shapes/triangle.hpp"
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

    // Partie 2 : Tests sur le carre
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

    // Partie 3 : Tests sur le triangle
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
    Point expectedCenter(1.0, 1.333333);  // Centre attendu : (1,1.33)
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

    // Affichage final
    cout << "Tous les tests ont réussi!" << endl;

    return 0;
}
