#include <string>
#include <iostream>
#include <set>
#include<windows.h>

int check_input(std::string s) {
	std::set<char> numbers;
	for (int i = 0; i < s.size(); i++) {
		if ((int)s[i] < 48 || (int)s[i] > 57) {
			return 1;
		}
		numbers.insert(s[i]);
	}
	if (s.size() != 4) {
		return 3;
	}
	if (s[0] == '0') {
		return 2;
	}
	if (numbers.size() != 4) {
		return 4;
	}
	return 0;
}

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	int length = 4; // Длина загаданного числа
	/*std::string number = generateNumber(length);*/ //Сделать функцию генерации 4-х значного числа, состоящего из уникальных чисел, возращать в int
	std::cout << "Добро пожаловать в игру 'Быки и коровы'!" << std::endl;
	std::cout << "Компьютер загадал число из " << length << " уникальных цифр." << std::endl;
	std::cout << "Ваша задача - угадать это число." << std::endl;
	std::cout << "Введите ваше предположение, и вам сообщат количество быков и коров." << std::endl;
	std::cout << "Быки - цифра на правильном месте, коровы - цифра есть, но на неправильном месте." << std::endl;

	std::string guess;
	int bulls = 0, cows = 0;
	int attempts = 0;

	// Основной игровой цикл
	while (bulls != length) {
		std::cout << "Введите ваше предположение: ";
		std::cin >> guess; 

		if (check_input(guess) != 0) {
			do {
				switch (check_input(guess))
				{
				case 1:
					std::cout << "Число содержить только цифры от 0 до 9!\n";
					break;
				case 2:
					std::cout << "Первой цифрой не может быть 0!\n";
					break;
				case 3:
					std::cout << "Число должно быть 4-х значным, то есть состоять из 4 цифр!\n";
					break;
				case 4:
					std::cout << "Все цифры в числе должны быть уникальны!\n";
					break;
				}
				std::cout << "Введите ваше предположение еще раз: ";
				std::cin >> guess;
			} while (check_input(guess) != 0);
		}

		++attempts;
		/*countBullsAndCows(secret, guess, bulls, cows);*/ //Сделать функцию подсчета коров, возращать в int
		std::cout << "Быки: " << bulls << ", Коровы: " << cows << std::endl;

		if (bulls == length) {
			std::cout << "поздравляем! вы угадали число " << number << " за " << attempts << " попыток!" << std::endl;
		}
	}

	return 0;
}