#include <string>
#include <iostream>

void countBullsAndCows(std::string secret, std::string guess, int& bulls, int& cows) {
	bulls = 0;
	cows = 0;

	//Подсчет быков
	for (int i = 0; i < secret.length(); i++) {
		if (guess[i] == secret[i]) {
			bulls++;
		}
	}

	//Подсчет коров
	for (int i = 0; i < secret.length(); i++) {
		for (int j = 0; j < secret.length(); j++) {
			if (i != j && guess[i] == secret[j]) {
				cows++;
			}
		}
	}
}

int main() {
	int length = 4; // Длина загаданного числа
	/*std::string number = generatNumber(length);*/ //Сделать функцию генерации 4-х значного числа, состоящего из уникальных чисел, возращать в int

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