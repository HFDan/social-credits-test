#pragma once

#include <map>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#elif UNIX
#define CLEAR_COMMAND "clear"
#else
#define CLEAR_COMMAND "clear"
#warning Possibly unsupported platform. Check if your compiler defines either WIN32 or UNIX
#endif

typedef std::tuple<
	std::string, std::vector<std::string>, std::vector<std::string>,
	unsigned long long>
	question;

typedef std::unordered_map<uint64_t, question> question_list;

unsigned long long PickRandomQuestion();

unsigned long long PrintQuestion(question q);

bool VerifyQuestion(question q);

void PrintRandomAsciiArt();
