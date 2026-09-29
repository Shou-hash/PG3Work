#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <functional> // std::function を使用するために必要

// DelayReveal 関数：関数ポインタから std::function に変更
void DelayReveal(std::function<void(int, int)> fn, unsigned int delayMs, int roll, int userGuess) {
    printf("結果を判定中...\n");

    // 指定ミリ秒待機
    Sleep(delayMs);

    // コールバック関数の呼び出し
    fn(roll, userGuess);
}

int main(void) {
    // コンソールの文字化け防止（UTF-8指定）
    SetConsoleOutputCP(65001);

    // シード初期化
    srand((unsigned int)time(NULL));

    // ユーザー入力
    int userGuess = 0;
    printf("予想を入力してください（半(奇数) = 1 / 丁(偶数) = 0）: ");
    scanf_s("%d", &userGuess);

    // 1〜6の乱数を生成
    int roll = (rand() % 6) + 1;

    // 【書き換えポイント】
    // std::function 変数に判定処理のラムダ式を代入[cite: 47, 50]
    std::function<void(int, int)> ShowResult = [](int roll, int userGuess) {
        printf("出目は %d でした。\n", roll);

        int result = roll % 2;
        if (result == userGuess) {
            printf("正解\n");
        }
        else {
            printf("不正解\n");
        }
        };

    // DelayReveal の呼び出し
    DelayReveal(ShowResult, 3000, roll, userGuess);

    return 0;
}