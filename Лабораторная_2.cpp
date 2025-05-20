#include <iostream>

using namespace std;

// Вектор
class vect {
private:
    int dim;
    double* b;
    int num;
    static int count;

public:
    // Конструктор по умолчанию.
    vect() : dim(0), b(nullptr), num(++count) {
        cout << "Вектор #" << num << ": создан по умолчанию." << endl;
    }
    
    // Конструктор с размерностью.
    explicit vect(int dimension) : dim(dimension), b(new double[dimension]), num(++count) {
        for (int i = 0; i < dim; ++i) {
            b[i] = 0.0;
        }
        cout << "Вектор #" << num << ": создан с размерностью " << dim << "." << endl;
    }

    // Конструктор копированием
    vect(const vect& other) : dim(other.dim), b(new double[other.dim]), num(++count) {
        for (int i = 0; i < dim; ++i) {
            b[i] = other.b[i];
        }
        cout << "Вектор #" << num << ": создан копированием из вектора #" << other.num << "." << endl;
    }

    // Деструктор
    ~vect() {
        delete[] b;
        cout << "Вектор #" << num << ": уничтожен." << endl;
    }

    // Операторы доступа
    double& operator[](int index) {
        return b[index];
    }
    
    const double& operator[](int index) const {
        return b[index];
    }

    // Операторы
    vect operator+(const vect& other) const {
        cout << "Операция: вектор #" << num << " + вектор #" << other.num << endl;
        vect result(dim);
        for (int i = 0; i < dim; ++i) {
            result.b[i] = b[i] + other.b[i];
        }
        return result;
    }

    vect operator-(const vect& other) const {
        cout << "Операция: вектор #" << num << " - вектор #" << other.num << endl;
        vect result(dim);
        for (int i = 0; i < dim; ++i) {
            result.b[i] = b[i] - other.b[i];
        }
        return result;
    }

    vect operator-() const {
        cout << "Операция: -вектор #" << num << endl;
        vect result(dim);
        for (int i = 0; i < dim; ++i) {
            result.b[i] = -b[i];
        }
        return result;
    }

    double operator*(const vect& other) const {
        cout << "Операция: вектор #" << num << " * вектор #" << other.num << " (скалярное)" << endl;
        double product = 0.0;
        for (int i = 0; i < dim; ++i) {
            product += b[i] * other.b[i];
        }
        return product;
    }

    vect operator*(double k) const {
        cout << "Операция: вектор #" << num << " * " << k << endl;
        vect result(dim);
        for (int i = 0; i < dim; ++i) {
            result.b[i] = b[i] * k;
        }
        return result;
    }

    vect& operator=(const vect& other) {
        cout << "Операция: вектор #" << num << " = вектор #" << other.num << endl;
        if (this != &other) {
            delete[] b;
            dim = other.dim;
            b = new double[dim];
            for (int i = 0; i < dim; ++i) {
                b[i] = other.b[i];
            }
        }
        return *this;
    }

    // Дружественные операторы
    friend vect operator*(double k, const vect& v) {
        cout << "Операция: " << k << " * вектор #" << v.num << endl;
        return v * k;
    }

    // Вывод
    void print() const {
        cout << "Вектор #" << num << ": [";
        for (int i = 0; i < dim; ++i) {
            cout << b[i];
            if (i < dim - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    int getNum() const { return num; }
    static int getCount() { return count; }
};

int vect::count = 0;

// Класс матрицы
class matr {
private:
    int dim;
    double* a;
    int num;
    static int count;

public:
    // Конструктор
    matr() : dim(0), a(nullptr), num(++count) {
        cout << "Матрица #" << num << ": создана по умолчанию." << endl;
    }
    
    // Конструктор с размерностью
    explicit matr(int dimension) : dim(dimension), a(new double[dimension*dimension]), num(++count) {
        for (int i = 0; i < dim*dim; ++i) {
            a[i] = 0.0;
        }
        cout << "Матрица #" << num << ": создана с размерностью " << dim << "x" << dim << "." << endl;
    }
    
    // Конструктор копированием
    matr(const matr& other) : dim(other.dim), a(new double[other.dim*other.dim]), num(++count) {
        for (int i = 0; i < dim*dim; ++i) a[i] = other.a[i];
        cout << "Матрица #" << num << ": создана копированием из матрицы #" << other.num << "." << endl;
    }

    // Деструктор
    ~matr() {
        delete[] a;
        cout << "Матрица #" << num << ": уничтожена." << endl;
    }

    // Операторы доступа
    double& operator()(int row, int col) { 
        return a[row*dim + col]; 
    }
    
    const double& operator()(int row, int col) const {
        return a[row*dim + col];
    }

    // Операторы
    matr operator+(const matr& other) const {
        cout << "Операция: матрица #" << num << " + матрица #" << other.num << endl;
        matr result(dim);
        for (int i = 0; i < dim*dim; ++i) {
            result.a[i] = a[i] + other.a[i];
        }
        return result;
    }

    matr operator-(const matr& other) const {
        cout << "Операция: матрица #" << num << " - матрица #" << other.num << endl;
        matr result(dim);
        for (int i = 0; i < dim*dim; ++i) {
            result.a[i] = a[i] - other.a[i];
        }
        return result;
    }

    matr operator-() const {
        cout << "Операция: -матрица #" << num << endl;
        matr result(dim);
        for (int i = 0; i < dim*dim; ++i) {
            result.a[i] = -a[i];
        }
        return result;
    }

    matr operator*(const matr& other) const {
        cout << "Операция: матрица #" << num << " * матрица #" << other.num << endl;
        matr result(dim);
        for (int i = 0; i < dim; ++i) {
            for (int j = 0; j < dim; ++j) {
                double sum = 0.0;
                for (int k = 0; k < dim; ++k) {
                    sum += a[i*dim + k] * other.a[k*dim + j];
                }
                result.a[i*dim + j] = sum;
            }
        }
        return result;
    }

    matr operator*(double k) const {
        cout << "Операция: матрица #" << num << " * " << k << endl;
        matr result(dim);
        for (int i = 0; i < dim*dim; ++i) {
            result.a[i] = a[i] * k;
        }
        return result;
    }

    vect operator*(const vect& v) const {
        cout << "Операция: матрица #" << num << " * вектор #" << v.getNum() << endl;
        vect result(dim);
        for (int i = 0; i < dim; ++i) {
            double sum = 0.0;
            for (int j = 0; j < dim; ++j) {
                sum += a[i*dim + j] * v[j];
            }
            result[i] = sum;
        }
        return result;
    }

    matr& operator=(const matr& other) {
        cout << "Операция: матрица #" << num << " = матрица #" << other.num << endl;
        if (this != &other) {
            delete[] a;
            dim = other.dim;
            a = new double[dim*dim];
            for (int i = 0; i < dim*dim; ++i) {
                a[i] = other.a[i];
            }
        }
        return *this;
    }

    // friend операторы
    friend matr operator*(double k, const matr& m) {
        cout << "Операция: " << k << " * матрица #" << m.num << endl;
        return m * k;
    }

    // Вывод
    void print() const {
        cout << "Матрица #" << num << ":\n";
        for (int i = 0; i < dim; ++i) {
            for (int j = 0; j < dim; ++j) {
                cout << a[i*dim + j] << " ";
            }
            cout << "\n";
        }
    }

    int getNum() const { return num; }
    static int getCount() { return count; }
};

int matr::count = 0;

int main() {
    cout << "Работа с векторами:" << endl;
    vect v1(3), v2(3);
    v1[0] = 1; v1[1] = 2; v1[2] = 3;
    v2[0] = 4; v2[1] = 5; v2[2] = 6;

    vect v3 = v1 + v2;
    v3.print();

    vect v4 = v1 - v2;
    v4.print();

    double dot = v1 * v2;
    cout << "Скалярное произведение: " << dot << endl;

    vect v5 = -v1;
    v5.print();

    vect v6 = 2.5 * v1;
    v6.print();

    cout << "Работа с матрицами:" << endl;
    matr m1(2), m2(2);
    m1(0,0) = 1; m1(0,1) = 2; m1(1,0) = 3; m1(1,1) = 4;
    m2(0,0) = 5; m2(0,1) = 6; m2(1,0) = 7; m2(1,1) = 8;

    matr m3 = m1 + m2;
    m3.print();

    matr m4 = m1 - m2;
    m4.print();

    matr m5 = m1 * m2;
    m5.print();

    matr m6 = -m1;
    m6.print();

    matr m7 = 3.0 * m1;
    m7.print();

    vect v7(2);
    v7[0] = 1; v7[1] = 2;
    vect v8 = m1 * v7;
    v8.print();

    cout << "\nВсего создано векторов: " << vect::getCount() << endl;
    cout << "Всего создано матриц: " << matr::getCount() << endl;

    return 0;
}