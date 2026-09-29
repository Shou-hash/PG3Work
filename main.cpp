#include <iostream>

int main() {
    // コンソールをUTF-8にする設定[cite: 1]
    system("chcp 65001 > nul");

    // printf()関数を使って好きな文字列を表示[cite: 1, 4]
    printf("こんにちは！UTF-8で文字化けせずに表示されています。\n");

    return 0;
}