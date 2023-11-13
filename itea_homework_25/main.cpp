#include <iostream>
#include <sstream>
#include <vector>
#include <numeric>

int main() {
    system("chcp 1251>nul");

    std::cout << "������ ����� (���������� ����� ������ ����: ��� ����� � �������� (-333, 333), ������ ��, ������ �� ��� ������ �+�. ���� ������� ����������.) :" << std::endl;

    std::string input;
    std::getline(std::cin, input);
    
    std::istringstream iss(input);

    std::vector<int> result;

    int controlElementsCount = 0;
    std::string token;
    while (iss >> token) {


        if (token == "+") {                // �+� - �������� ����� ������� ����� ��� ���� ���������;           
            int size = result.size();
            if (size < 2) {
                std::cerr << "�������. ��� ��������� �������� �+� �� ���� ���������� ��� �������� �����." << std::endl;
                return 1;
            }
            int newElement = result.at(size - 1) + result.at(size - 2);
            result.push_back(newElement);
        } else if (token == "�") {        // �� � �������� ����� ������� ����� ������ �� ���������;
            int size = result.size();
            if (size < 1) {
                std::cerr << "�������. ��� �� �� ���� ���������� 1 �����." << std::endl;
                return 1;
            }
            int newElement = result.at(size - 1) * 2;
            result.push_back(newElement);
        } else if (token == "�") {       // �� � ��������� ��������� ��������� �������.
            int size = result.size();
            if (size < 1) {
                std::cerr << "�������. ��� �� �� ���� ���������� 1 �����." << std::endl;
                return 1;
            }            
            result.pop_back();
        } else {                        // ���� ����� � �������� ����� ������� ����� ����� �����;
            size_t pos;
            int num = std::stoi(token, &pos);
            if (pos < token.length()) {               
                std::cerr << "�������. ��������� ���� �����." << std::endl;
                return 1;
            }
            if (num >= -333 && num <= 333) {
                result.push_back(num);
            }
            else {
                std::cerr << "�������. ���� ��������� � �����, �� ���� �� ���� � ������� �� -333 �� +333." << std::endl;
                return 1;
            }
        }
        
        controlElementsCount++;
        if (controlElementsCount > 1000) {
            std::cerr << "�������. ������������ �-�� �������� ��������� ��������." << std::endl;
            return 1;
        }

    }

    // ������������� std::accumulate ��� ���������� ����
    int sum = std::accumulate(result.begin(), result.end(), 0);
    
    std::cout << "���� �������� �������: " << sum << std::endl;


    return 0;
}



































