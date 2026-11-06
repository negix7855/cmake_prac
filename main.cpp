#include <cstdint>
#include <cstddef>
#include <iostream>
#include <string>
#include <string_view>
#include <bitset>

#ifdef _WIN32
#include <windows.h>
#endif

int getNumberFromUser() {
    int input{};
    std::cin >> input;
    return input;
}

std::string getStringFromUser() {
    std::string input{};
    std::getline(std::cin >> std::ws, input);
    return input;
}

std::string_view getZoneName(int zone) {
    if (zone == 1)
        return "Residential";
    else if (zone == 2)
        return "Commercial";
    else if (zone == 3)
        return "Industry";
    else return "Unknown";
}

void printCityInfo(std::string_view cityName, int population, std::string_view zoneName) {
    std::cout << "---- 街の情報 ----" << "\n";
    std::cout << "町の名前: " << cityName << "(" << cityName.length() << "文字)\n";
    std::cout << "人口; " << population << "\n";
    std::cout << "区画: " << zoneName << "\n";
}

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    std::cout << "人口を入力してください: ";
    const int population{ getNumberFromUser() };

    std::cout << "街の名前を入力してください: ";
    const std::string cityName{ getStringFromUser() };

    std::cout << "区画の番号を入力してください(1:住宅 2:商業 3:工業): ";
    const int zone{ getNumberFromUser() };
    std::string_view zoneName{ getZoneName(zone) };
    
    printCityInfo(cityName, population, zoneName);

    return 0;
}