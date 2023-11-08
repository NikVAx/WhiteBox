#include <iostream>
#include <cmath>
#include <iomanip>

double calc_geometric_mean(double* arr, int n) {
    if (n <= 0) {
        std::cerr << "Размер массива должен быть положительным числом" << std::endl;
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
        std::cerr << "Произведение является отрицательным числом. Вычисление невозможно" << std::endl;
        return 0.;
    }
    double power = 1. / static_cast<double>(not_null_count);
    double mean = std::pow(prod, power);
    return mean;
}

const double EPSILON = 1.E-15;

bool is_double_equals(double first, double second, double epsilon)
{
    return std::abs(first - second) < epsilon;
}

void expect_error_empty_array() {
    int n = 0;
    double arr[1] = {};
    double result = calc_geometric_mean(arr, n);

    if (result == 0.) {
        std::cout << ">> Тест пройден" << std::endl;
    }
    else {
        std::cout << ">> Тест не пройден" << std::endl;
    }
}

void expect_error_only_zero() {
    int n = 5;
    double arr[5] = { 0,0,0,0,0 };
    double result = calc_geometric_mean(arr, n);

    if (result == 0.) {
        std::cout << ">> Тест пройден" << std::endl;
    }
    else {
        std::cout << ">> Тест не пройден" << std::endl;
    }
}

void expect_error_negative_prod() {
    int n = 5;
    double arr[5] = { -1,1,2,3,4 };
    double result = calc_geometric_mean(arr, n);

    if (result == 0.) {
        std::cout << ">> Тест пройден" << std::endl;
    }
    else {
        std::cout << ">> Тест не пройден" << std::endl;
    }
}

void expect_right_case_1() {
    int n = 5;
    double arr[5] = { 1,-1,0,1,-1 };
    double result = calc_geometric_mean(arr, n);

    std::cout << result << "\n";

    if (is_double_equals(result, 1.0000000000000000, EPSILON)) {
        std::cout << ">> Тест пройден" << std::endl;
    }
    else {
        std::cout << ">> Тест не пройден" << std::endl;
    }
}

void expect_right_case_2()
{
    int n = 5;
    double arr[5] = { 1,2,3,4,5 };
    double result = calc_geometric_mean(arr, n);

    std::cout << result << "\n";

    if (is_double_equals(result, 2.6051710846973519, EPSILON)) {
        std::cout << ">> Тест пройден" << std::endl;
    }
    else {
        std::cout << ">> Тест не пройден" << std::endl;
    }
}

void expect_right_case_3()
{
    int n = 5;
    double arr[5] = { 1,2,0,4,5 };
    double result = calc_geometric_mean(arr, n);

    std::cout << result << "\n";

    if (is_double_equals(result, 2.5148668593658708, EPSILON)) {
        std::cout << ">> Тест пройден" << std::endl;
    }
    else {
        std::cout << ">> Тест не пройден" << std::endl;
    }
}

void expect_right_case_4()
{
    int n = 5;
    double arr[5] = { 100,100,100,100,100 };
    double result = calc_geometric_mean(arr, n);

    std::cout << result << "\n";

    if (is_double_equals(result, 100, 1.E-13)) {
        std::cout << ">> Тест пройден" << std::endl;
    }
    else {
        std::cout << ">> Тест не пройден" << std::endl;
    }
}

void expect_is_equal_true_case_1() {
    double eps_ = 0.000'000'1;
    double arg1 = 2.000'000'1;
    double arg2 = 2.000'000'1;

    if (is_double_equals(arg1, arg2, eps_) == true)
    {
        std::cout << ">> Тест пройден" << std::endl;
    }
    else
    {
        std::cout << ">> Тест не пройден" << std::endl;
    }
}

void expect_is_equal_true_case_2() {
    double eps_ = 0.000'000'1;
    double arg1 = 2.000'000'1;
    double arg2 = 2.000'000'04;

    if (is_double_equals(arg1, arg2, eps_) == true)
    {
        std::cout << ">> Тест пройден" << std::endl;
    }
    else
    {
        std::cout << ">> Тест не пройден" << std::endl;
    }
}

void expect_is_equal_false() {
    double eps_ = 0.000'000'1;
    double arg1 = 2.000'000'3;
    double arg2 = 2.000'000'6;


    if (is_double_equals(arg1, arg2, eps_) == false)
    {
        std::cout << ">> Тест пройден" << std::endl;
    }
    else
    {
        std::cout << ">> Тест не пройден" << std::endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    expect_is_equal_true_case_1();
    expect_is_equal_true_case_2();
    expect_is_equal_false();
    
    expect_error_empty_array();
    expect_error_only_zero();
    expect_error_negative_prod();
    expect_right_case_1();
    expect_right_case_2();
    expect_right_case_3();
    expect_right_case_4();

    return 0;
}
