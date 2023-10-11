#include <iostream>
#include <cmath>

double calc_geometric_mean(double* arr, int n) {
    if (n <= 0) {
        std::cout << "Размер массива должен быть положительным числом" << std::endl;
        return 0.;
    }
    double prod = 0.;
    int not_null_count = 0;
    for (int i = 0; i < n; i++) {
        double target = arr[i];
        if (target == 0) continue;
        not_null_count += 1;
        if (prod == 0) {
            prod = target;
            continue;
        }
        prod *= target;
    }
    if (prod < 0) {
        std::cout << "Произведение является отрицательным числом. Вычисление невозможно" << std::endl;
        return 0.;
    }
    double power = 1. / static_cast<double>(not_null_count);
    double mean = std::pow(prod, power);

    return mean;
}

void empty_array() {
    int n = 0;
    double arr[1] = {};
    double result = calc_geometric_mean(arr, n);

    if (result == 0.) {
        std::cout << "Тест пройден" << std::endl;
    }
    else {
        std::cout << "Тест не пройден" << std::endl;
    }
}

void only_zero() {
    int n = 5;
    double arr[5] = {0,0,0,0,0};
    double result = calc_geometric_mean(arr, n);

    if (result == 0.) {
        std::cout << "Тест пройден" << std::endl;
    }
    else {
        std::cout << "Тест не пройден" << std::endl;
    }
}

void negative_prod() {
    int n = 5;
    double arr[5] = { -1,1,2,3,4 };
    double result = calc_geometric_mean(arr, n);

    if (result == 0.) {
        std::cout << "Тест пройден" << std::endl;
    }
    else {
        std::cout << "Тест не пройден" << std::endl;
    }
}

void default_mean() {
    int n = 5;
    double arr[5] = { 1,-1,0,1,-1 };
    double result = calc_geometric_mean(arr, n);

    if (result == 1.) {
        std::cout << "Тест пройден" << std::endl;
    }
    else {
        std::cout << "Тест не пройден" << std::endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    empty_array();
    only_zero();
    negative_prod();
    default_mean();
    return 0;
}
