#include <iostream>
#define NOGDI // windows.h の Rectangle 関数との名前衝突を防止
#include <windows.h>

// 1. 基底クラス（抽象クラス / インターフェイス）：図形
class IShape {
public:
    // 基底クラス用の仮想デストラクタ
    virtual ~IShape() {}

    // 純粋仮想関数（= 0 をつけて派生クラスに実装を強制する）
    virtual void Size() = 0;
    virtual void Draw() = 0;
};

// 2. 派生クラス：円
class Circle : public IShape {
private:
    double radius; // 半径
    double area;   // 面積

public:
    Circle(double r) : radius(r), area(0.0) {}

    // 面積を求める
    void Size() override {
        area = radius * radius * 3.14;
    }

    // 求めた面積を表示する
    void Draw() override {
        std::cout << "円の面積（半径 " << radius << "）: " << area << std::endl;
    }
};

// 3. 派生クラス：矩形（長方形）
class Rectangle : public IShape {
private:
    double width;  // 幅
    double height; // 高さ
    double area;   // 面積

public:
    Rectangle(double w, double h) : width(w), height(h), area(0.0) {}

    // 面積を求める
    void Size() override {
        area = width * height;
    }

    // 求めた面積を表示する
    void Draw() override {
        std::cout << "矩形の面積（幅 " << width << ", 高さ " << height << "）: " << area << std::endl;
    }
};

int main() {
    // コンソールの文字化け防止（UTF-8指定）
    SetConsoleOutputCP(65001);

    const int NUM_SHAPES = 2;
    // 抽象クラス（IShape）のポインタ配列で派生クラスをまとめて扱う
    IShape* shapes[NUM_SHAPES];

    // --- 生成フェーズ ---
    shapes[0] = new Circle(5.0);          // 半径 5.0 の円
    shapes[1] = new Rectangle(4.0, 6.0);  // 幅 4.0, 高さ 6.0 の矩形

    // --- 実行フェーズ（ポリモーフィズム） ---
    std::cout << "=== 図形の面積計算と表示 ===" << std::endl;
    for (int i = 0; i < NUM_SHAPES; i++) {
        shapes[i]->Size(); // 面積を計算
        shapes[i]->Draw(); // 計算結果を表示
    }

    // --- 破棄フェーズ ---
    for (int i = 0; i < NUM_SHAPES; i++) {
        delete shapes[i];
    }

    return 0;
}