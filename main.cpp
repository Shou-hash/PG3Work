#include <iostream>

int main() {
    // コンソールをUTF-8にする設定
    system("chcp 65001 > nul");

    // printf()関数を使って好きな文字列を表示
    char str[] = "こんにちは！UTF-8で文字化けせずに表示されています。\n";

    printf("%s", str);

    return 0;
}