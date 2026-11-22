#include <cstdint>
#include <cstddef>
#include <iostream>
#include <string>
#include <string_view>
#include <bitset>

#ifdef _WIN32
#include <windows.h>
#endif

void collectTax(int& budget, int population) {
    // 予算は変更ありだから参照渡し、人口は変更無しだから値渡し
    constexpr int tax{ 10 };
    budget += population * tax;
}

void payConstruction(int& budget, int constructionFee) {
    // 予算は変更ありだから参照渡し、建設費は変更無しだから値渡し
    budget -= constructionFee;
}

void printReport(std::string_view cityName, int budget) {
    // 市の名前はコピー不要だからstring_view予算は変更無しだから値渡し
    std::cout << "[" << cityName << "] 予算: " << budget << "\n";
}

void swapPopulation(int& populationA, int& populationB) {
    // 人口A,Bともに変更ありだから参照渡し
    int temp{ populationA };
    populationA = populationB;
    populationB = temp;
}

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    int budget{ 100'000 };
    constexpr int population{ 5'000 };
    constexpr std::string_view cityName{ "Midori Town" };

    constexpr int roadFee{ 3'000 };
    constexpr int parkFee{ 12'000 };

    printReport(cityName, budget);

    std::cout << "税収を集めました\n";
    collectTax(budget, population);

    printReport(cityName, budget);

    std::cout << "道路を3本建設しました\n";
    payConstruction(budget, roadFee * 3);

    printReport(cityName, budget);

    std::cout << "公園を建設しました\n";
    payConstruction(budget, parkFee);

    printReport(cityName, budget);

    int populationA{ 3'000 };
    int populationB{ 2'000 };

    std::cout << "入れ替え前 地区A: " << populationA << " 地区B: " << populationB << "\n";
    swapPopulation(populationA, populationB);
    std::cout << "入れ替え後 地区A: " << populationA << " 地区B: " << populationB << "\n";

    return 0;
}