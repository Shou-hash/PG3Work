#include <stdio.h>
#include <string.h>
#include <list>

using namespace std;

// 駅一覧を表示する関数
void printStations(const list<const char*>& stations, int year) {
    printf("=== Yamanote Line Stations (%d) ===\n", year);
    for (auto itr = stations.begin(); itr != stations.end(); ++itr) {
        printf("%s\n", *itr);
    }
    printf("\n");
}

int main() {
    // コンソールの文字化け対策（日本語表示用）
    system("chcp 65001 > nul");

    // 1970年時点の山手線の駅一覧（英語表記・27駅）
    list<const char*> yamanote = {
        "Tokyo", "Kanda", "Akihabara", "Okachimachi", "Ueno",
        "Uguisudani", "Nippori", "Tabata", "Komagome", "Sugamo",
        "Otsuka", "Ikebukuro", "Mejiro", "Takadanobaba", "Shinjuku",
        "Yoyogi", "Harajuku", "Shibuya", "Ebisu", "Meguro",
        "Gotanda", "Osaki", "Shinagawa", "Tamachi", "Hamamatsucho",
        "Shimbashi", "Yurakucho"
    };

    // 1970年の駅一覧を表示
    printStations(yamanote, 1970);

    // 西日暮里駅 (1971年開業) を適切な位置に挿入
    //（Nippori と Tabata の間 → Tabata の直前に挿入）
    for (auto itr = yamanote.begin(); itr != yamanote.end(); ++itr) {
        if (strcmp(*itr, "Tabata") == 0) {
            yamanote.insert(itr, "Nishi-Nippori");
            break;
        }
    }

    // 2019年の駅一覧を表示
    printStations(yamanote, 2019);

    // 高輪ゲートウェイ駅 (2020年開業) を適切な位置に挿入
    //（Shinagawa と Tamachi の間 → Tamachi の直前に挿入）
    for (auto itr = yamanote.begin(); itr != yamanote.end(); ++itr) {
        if (strcmp(*itr, "Tamachi") == 0) {
            yamanote.insert(itr, "Takanawa Gateway");
            break;
        }
    }

    // 2022年の駅一覧を表示
    printStations(yamanote, 2022);

    return 0;
}