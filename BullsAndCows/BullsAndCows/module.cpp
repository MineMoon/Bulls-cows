#include <string>
#include <iostream>
#include <random>
#include <cstdlib>
#include <time.h>
#include <set>
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
std::string Random() {
	srand(time(NULL));
	std::string digit = "";
	while (digit.size() != 4) {
		char temp = '0' + rand() % 10;
		if (temp == '0' && digit.size() == 0) {
			while (!(temp == '0')) {
				temp = '0' + rand() % 10;
			}
		}
		if (digit.find(temp) == std::string::npos)
			digit += temp;
	}
	return digit;
}