#include <iostream>
#include <cmath>

double f(double x) {
    return pow(x, 2) + 5 * cos(x);
}

double dichotomyMethod(double a, double b, double tol) {
    while (fabs(b - a) > tol) { // 迭代直到收敛
        double x1 = (a + b - tol/2) / 2;
        double x2 = (a + b + tol/2) / 2;
        if (f(x1) < f(x2)) {
            b = x2;
        } else {
            a = x1;
        }
    }

    return (a + b) / 2; // 返回极小值的位置
}

int main() {
    double a = -10; // 搜索区间左端点
    double b = 10; // 搜索区间右端点
    double tol = 1e-6; // 容忍度
    double x_min = dichotomyMethod(a, b, tol);
    std::cout << "Minimum value found at x = " << x_min << "\n";
    std::cout << "Minimum function value = " << f(x_min) << "\n";
    return 0;
}
