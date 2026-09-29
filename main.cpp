#include <iostream>

using namespace std;

// 関数テンプレートによる Min 関数の定義
template <typename Type>
Type Min(Type a, Type b) {
    return (a < b) ? a : b;
}

int main() {
    // int型の3対目（ペア1）
    int i1 = 15;
    int i2 = 8;
    cout << "int型の最小値: " << Min<int>(i1, i2) << endl;

    // float型の3対目（ペア2）
    float f1 = 3.14f;
    float f2 = 1.59f;
    cout << "float型の最小値: " << Min<float>(f1, f2) << endl;

    // double型の3対目（ペア3）
    double d1 = 9.81;
    double d2 = 12.34;
    cout << "double型の最小値: " << Min<double>(d1, d2) << endl;

    return 0;
}