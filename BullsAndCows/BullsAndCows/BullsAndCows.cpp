#include <string>
#include <iostream>
#include <set>

int check_input(std::string s) {
	std::set<char> numbers;
	if (s.size() != 4) {
		return 1;
	}
	if (s[0] == '0') {
		return 2;
	}
	for (int i = 0; i < s.size(); i++){
		if ((int)s[i] < 48 || (int)s[i] > 57) {
			return 3;
		}
		numbers.insert(s[i]);
	}
	if (numbers.size() != 4) {
		return 4;
	}
	return 0;
}

int main() {
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
		std::cin >> guess; // Добавить проверки на дурака


		if (guess.length() != length) {
			std::cout << "Число должно быть длиной " << length << " цифр. Попробуйте снова." << std::endl;
			continue;
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