#include <iostream>
#include <cmath>

double f(double x) {
    return pow(x, 2) + 5 * cos(x);
}

double df(double x) {
    return 2 * x - 5 * sin(x);
}

double ddf(double x) {
    return 2 - 5 * cos(x);
}

double newtonsMethod(double x0, double tol, int maxiter) {
    double x = x0;
    int iter = 0;
    while (iter < maxiter) { // 迭代次数限制
        double dx = -df(x) / ddf(x);
        x += dx;
        if (fabs(dx) < tol) {
            break;
        }
        iter++;
    }
    return x; // 返回极小值的位置
}

int main() {
    double x0 = 2; // 初始点
    double tol = 1e-6; // 容忍度
    int maxiter = 100; // 迭代次数限制
    double x_min = newtonsMethod(x0, tol, maxiter);
    std::cout << "Minimum value found at x = " << x_min << "\n";
    std::cout << "Minimum function value = " << f(x_min) << "\n";
    return 0;
}
