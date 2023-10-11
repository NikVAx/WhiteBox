#include <iostream>
#include <cmath>

double calc_geometric_mean(int n) {
    if (n <= 0) {
        std::cout << "Размер массива должен быть положительным числом" << std::endl;
        return 0.;
    }
    double* arr = new double[n];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    double prod = 0;
    double not_null_count = 0;
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

    delete[] arr;
    return mean;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    std::cin >> n;
    double result = calc_geometric_mean(n);
    std::cout << result;
    return 0;
}
