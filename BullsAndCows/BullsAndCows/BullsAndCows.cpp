﻿#include <string>
#include <iostream>
#include <random>
#include <cstdlib>
#include <time.h>
#include <set>
#include<windows.h>
#include"add.h";
int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	int choice;
	std::string number;
	std::cout << "Добро пожаловать в игру 'Быки и коровы'!" << std::endl;
	std::cout << "Компьютер или человек загадывает число из 4 уникальных цифр." << std::endl;
	std::cout << "Ваша задача - угадать это число." << std::endl;
	std::cout << "Введите ваше предположение, и вам сообщат количество быков и коров." << std::endl;
	std::cout << "Быки - цифра на правильном месте, коровы - цифра есть, но на неправильном месте." << std::endl;
	std::cout << std::endl;
	std::cout << "Выберите противника: 1 - компьютер, 2 - второй человек: ";
	std::cin >> choice;
	while (choice < 1 || choice > 2) {
		std::cout << "Неверно выбран противник, попробуйте еще раз: ";
		std::cin >> choice;
	}

	if (choice == 1) {
		number = Random();
	}
	else {
		std::cout << "Загадайте число из 4 уникальных цифр: ";
		std::cin >> number;
		if (check_input(number) != 0) {
			do {
				switch (check_input(number))
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
				std::cin >> number;
			} while (check_input(number) != 0);
		}
	}
	system("cls");
	std::cout << "Число загадано!";

	std::string guess;
	int bulls = 0, cows = 0;
	int attempts = 0; // счетчик
	std::cout << std::endl;
	while (bulls != 4) {
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
		countBullsAndCows(number, guess, bulls, cows); //Функция подсчета коров и быков
		std::cout << "Быки: " << bulls << ", Коровы: " << cows << std::endl;

		if (bulls == 4) {
			std::cout << "Поздравляем! вы угадали число " << number << " за " << attempts << " попыток!" << std::endl;
		}
	}

	return 0;
}