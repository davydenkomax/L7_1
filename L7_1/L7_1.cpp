/*
    Написать функцию f(a,b), вычисляющую и возвращающую величину неизвестного угла С в треугольнике 
    по заданным величинам его известных углов a и b. Продемонстрировать ее работу для трех треугольников.
*/
#include <iostream>

using namespace std;

/**
 * @brief Вычисление угла С в треугольнике ABC
 * @param a значение угла А
 * @param b значение угла B
 * @return Значение угла С
*/
double getAngle_r(const double a, const double b);

/**
 * @brief Вычисление угла С в треугольнике ABC
 * @param a значение угла А
 * @param b значение угла B
 * @param result возвращает значние угла С по указателю
*/
void getAngle_p(const double a, const double b, double* result);

/**
 * @brief Вычисление угла С в треугольнике ABC
 * @param a значение угла А
 * @param b значение угла B
 * @param result возвращает значние угла С по ссылке
*/
void getAngle_l(const double a, const double b, double& result);


int main() {
    setlocale(LC_ALL, "ru");
    // Объявление переменных a, b
    double a, b;
    for (int i = 0; i < 3; i++) {
        // Ввод значений переменных a, b
        cout << "Укажите первый угол a(0 < a < 180): ";
        cin >> a;
        cout << "Укажите второй угол b(0 < b < " << 180 - a << "): ";
        cin >> b;
        // Проверка на неправильный ввод данных
        if (a <= 0 || a >= 180 || b <= 0 || b >= (180 - a)) {
            cerr << "Неправильный ввод переменных";
            return 1;
        }
        // Присвоение пересенной результата выполнения ф-ии getAngle_r
        double result1 = getAngle_r(a, b);
        cout << "Функция через return" << endl;
        cout << "Угол C = " << result1 << endl;
        // Объявление переменной
        double result2;
        // Вызов ф-ии и передача в ф-ию getAngle_p ссылку на переменную result2
        getAngle_p(a, b, &result2);
        cout << "Функция через pointer" << endl;
        cout << "Угол C = " << result2 << endl;
        // Объявление переменной
        double result3;
        // Вызов ф-ии getAngle_l
        getAngle_l(a, b, result3);
        cout << "Функция через link" << endl;
        cout << "Угол C = " << result3 << endl;
    }
}

double getAngle_r(const double a, const double b) {
    return 180 - (a + b);
}

void getAngle_p(const double a, const double b, double *result) {
    *result = 180 - (a + b);
}

void getAngle_l(const double a, const double b, double& result) {
    result = 180 - (a + b);
}