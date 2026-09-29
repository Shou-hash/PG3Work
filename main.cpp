#include <iostream>
#include <iomanip>

using namespace std;

// 再帰的な賃金体系における n 時間目の「時給」を計算する再帰関数
int GetRecursiveWage(int n) {
    // 最初の1時間働いたときの時給は100円
    if (n <= 1) {
        return 100;
    }
    // 次の1時間からは「前の1時間でもらった時給 * 2 - 50円」
    return GetRecursiveWage(n - 1) * 2 - 50;
}

int main() {
    // コンソールの文字化け対策
    system("chcp 65001 > nul");

    const int NORMAL_HOURLY = 1226; // 一般的な賃金体系（時給1,226円）
    int normal_total = 0;           // 一般的な賃金体系の累計支給額
    int recursive_total = 0;        // 再帰的な賃金体系の累計支給額

    cout << "時間   | 一般(時給) | 一般(累計) | 再帰(時給) | 再帰(累計) | 比較結果" << endl;
    cout << "------------------------------------------------------------" << endl;

    for (int h = 1; h <= 10; h++) {
        int r_wage = GetRecursiveWage(h);
        normal_total += NORMAL_HOURLY;
        recursive_total += r_wage;

        cout << setw(2) << h << "時間目 | "
            << setw(6) << NORMAL_HOURLY << "円 | "
            << setw(6) << normal_total << "円 | "
            << setw(6) << r_wage << "円 | "
            << setw(6) << recursive_total << "円 | ";

        if (recursive_total > normal_total) {
            cout << "再帰的のほうが儲かる" << endl;
        }
        else {
            cout << "一般的なほうが儲かる" << endl;
        }
    }

    return 0;
}