#include <iostream>
#include <cmath>

double f(double x) {
    return pow(x, 2) + 5 * cos(x);
}

double goldenSectionSearch(double a, double b, double tol) {
    double phi = (1 + sqrt(5)) / 2; // 黄金分割率
    double x1 = b - (b - a) / phi; // 计算第一个分割点
    double x2 = a + (b - a) / phi; // 计算第二个分割点

    while (fabs(b - a) > tol) { // 迭代直到收敛
        if (f(x1) < f(x2)) {
            b = x2;
            x2 = x1;
            x1 = b - (b - a) / phi;
        } else {
            a = x1;
            x1 = x2;
            x2 = a + (b - a) / phi;
        }
    }

    return (a + b) / 2; // 返回极小值的位置
}

int main() {
    double a = -10; // 搜索区间左端点
    double b = 10; // 搜索区间右端点
    double tol = 1e-6; // 容忍度
    double x_min = goldenSectionSearch(a, b, tol);
    std::cout << "Minimum value found at x = " << x_min << "\n";
    std::cout << "Minimum function value = " << f(x_min) << "\n";
    return 0;
}
