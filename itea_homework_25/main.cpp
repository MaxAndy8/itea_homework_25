#include <iostream>
#include <sstream>
#include <vector>
#include <numeric>

int main() {
    system("chcp 1251>nul");

    std::cout << "Введіть рядок (елементами якого можуть бути: цілі числа з діапазону (-333, 333), символ “д”, символ “с” або символ “+”. Інші символи недопустимі.) :" << std::endl;

    std::string input;
    std::getline(std::cin, input);
    
    std::istringstream iss(input);

    std::vector<int> result;

    int controlElementsCount = 0;
    std::string token;
    while (iss >> token) {


        if (token == "+") {                // “+” - записати новий рахунок рівний сумі двох попередніх;           
            int size = result.size();
            if (size < 2) {
                std::cerr << "ПОМИЛКА. Для виконання операції “+” має бути щонайменше два попередні числа." << std::endl;
                return 1;
            }
            int newElement = result.at(size - 1) + result.at(size - 2);
            result.push_back(newElement);
        } else if (token == "д") {        // “д” — записати новий рахунок вдвічі більший за попередній;
            int size = result.size();
            if (size < 1) {
                std::cerr << "ПОМИЛКА. Для “д” має бути щонайменше 1 запис." << std::endl;
                return 1;
            }
            int newElement = result.at(size - 1) * 2;
            result.push_back(newElement);
        } else if (token == "с") {       // “с” — скасувати попередній записаний рахунок.
            int size = result.size();
            if (size < 1) {
                std::cerr << "ПОМИЛКА. Для “с” має бути щонайменше 1 запис." << std::endl;
                return 1;
            }            
            result.pop_back();
        } else {                        // ціле число — записати новий рахунок рівний цьому числу;
            size_t pos;
            int num = std::stoi(token, &pos);
            if (pos < token.length()) {               
                std::cerr << "ПОМИЛКА. Очікується ціле число." << std::endl;
                return 1;
            }
            if (num >= -333 && num <= 333) {
                result.push_back(num);
            }
            else {
                std::cerr << "ПОМИЛКА. Якщо елементом є число, то воно має бути в діапазоні від -333 до +333." << std::endl;
                return 1;
            }
        }
        
        controlElementsCount++;
        if (controlElementsCount > 1000) {
            std::cerr << "ПОМИЛКА. Переповнення к-ть елементів управління рахунком." << std::endl;
            return 1;
        }

    }

    // Використовуємо std::accumulate для обчислення суми
    int sum = std::accumulate(result.begin(), result.end(), 0);
    
    std::cout << "Сума елементів вектора: " << sum << std::endl;


    return 0;
}



































