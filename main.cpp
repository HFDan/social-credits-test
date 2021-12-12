#include <chrono>
#include <cstdio>
#include <iostream>
#include <thread>

#include "color.h"
#include "socialcredits.hpp"

extern question_list questions;

int main(int argc, char **argv) {
	long long social_credits = 1000;
	while (true) {
		system(CLEAR_COMMAND);
		auto randQ = PickRandomQuestion();
		printf("You currently have %lli social credits\n", social_credits);
		printf("Quit? [Y/n] ");
		std::string input;
		std::cin >> input;

		if (input == "Y" || input == "y") break;

		auto prize = PrintQuestion(questions[randQ]);
		if (VerifyQuestion(questions[randQ])) {
			social_credits -= prize;
			setclr(RED, DEFAULT);
			printf(
				"You have lost %llu social credits. Do better next time, "
				"citizen!\n",
				prize);
			resetclr();
			PrintRandomAsciiArt();
			std::this_thread::sleep_for(std::chrono::seconds(3));
		} else {
			social_credits += prize;
			setclr(GREEN, DEFAULT);
			printf("You have won %llu social credits. Good job!\n", prize);
			resetclr();
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	}

	if (social_credits > 1000) {
		setclr(GREEN, DEFAULT);
		printf("You are a model citizen!\nThe CCP salutes you!\n");
		resetclr();
	} else if (social_credits == 1000) {
		setclr(GREEN, DEFAULT);
		printf("You are a good citizen!\nThe CCP salutes you!\n");
		resetclr();
	} else if (social_credits < 100) {
		setclr(RED, DEFAULT);
		printf(
			"You are a bad citizen!\nYou have been sentenced to extreme COCK "
			"AND BALLS extermination via monke.\n"
			"Do not resist.\n"
			"Your execution date is tomorrow at 7AM.\n"
			"Your last meal is Bing Chilling\n");
		resetclr();
	} else if (social_credits < 500) {
		setclr(RED, DEFAULT);
		printf(
			"You are a bad citizen!\nYou, your family, your teachers\n"
			"and your friends are all to be arrested and sent to a "
			"reeducation\n"
			"camp in the xinjiang uyghur autonomous zone.");
		resetclr();
	} else if (social_credits < 1000) {
		setclr(YELLOW, DEFAULT);
		printf(
			"You are an average citizen!\nYou can do better! The CCP has faith "
			"in you!\n");
		resetclr();
	}

	return 0;
}
