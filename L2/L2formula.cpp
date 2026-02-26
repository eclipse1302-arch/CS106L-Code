#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
pair<bool,pair<double, double>> quadratic_formula(const double a, const double b, const double c) {
    double discriminant = b*b - 4*a*c;
    if (discriminant < 0) return {false, {NAN, NAN}}; // No real roots
    double sqrt_disc = sqrt(discriminant);
    double root1 = (-b + sqrt_disc) / (2*a);
    double root2 = (-b - sqrt_disc) / (2*a);
    return {true, {root1, root2}};
}
int main() {
    double a = 1, b = -3, c = 2; // Example coefficients
    auto [found,solutions] = quadratic_formula(a, b, c);
    if (found) {
        cout << "Roots: " << solutions.first << " and " << solutions.second << endl;
    } else {
        cout << "No real roots." << endl;
    }
    return 0;
}