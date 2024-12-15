# Bulls-cows
Лабораторная работа №7
Участникни: Мастыко Михаил, Дарья Ширяева, Анастасия Драчева. 
Группа ИТ-11-12
================
Описание проекта:

Функции:
  1. Random -- Генерация случайного четырехзначного числа
  2. check_input -- Проверка корректности ввода
  3. countBullsAndCows - подсчет коров и быков

Инструкция по запуску:
При запуске программы у пользователя появляется возможность выбора соперника. Пользователь может ввести "1" и играть против компьютера, в этом случае используется функция Random для генерации четырех-значного числа. В случае ввода "2" соперник пользователя вводит с клавиатуры четырех-значное число, после чего с помощью функции check_input проводится проверка на корректность ввода. В случае некорректного ввода пользователю выводится ошибка, после чего он может ввести число заново. Далее строка ввода очищается, следовательно, загаданное число в любом случае скрыто.

Начнем игру. Пользователь вводит число, после чего запускается функция check_input(ее работа была описана выше), если ввод некорректен, пользователь модет ввести число заново. Далее выводится количество быков(числа угаданы и на своих местах) и коров(числа угаданы, но не на своих местах). Действия продолжаются до тех пор, пока количество быков не станет равно четырем, что будет означать, что все числа угаданы и находятся на своих местах.

Роли участников: 
  Мастыко Михаил - тимлид
  Дарья Ширяева - тестировщик
  Анастасия Драчева - разработчик
