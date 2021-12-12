#include "socialcredits.hpp"

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <random>
#include <string>

std::map<int, std::string> ascii_art{
{0,
	 R"(
⣿⣿⣿⣿⣿⠟⠋⠄⠄⠄⠄⠄⠄⠄⢁⠈⢻⢿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⠃⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠈⡀⠭⢿⣿⣿⣿⣿
⣿⣿⣿⣿⡟⠄⢀⣾⣿⣿⣿⣷⣶⣿⣷⣶⣶⡆⠄⠄⠄⣿⣿⣿⣿
⣿⣿⣿⣿⡇⢀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠄⠄⢸⣿⣿⣿⣿
⣿⣿⣿⣿⣇⣼⣿⣿⠿⠶⠙⣿⡟⠡⣴⣿⣽⣿⣧⠄⢸⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣾⣿⣿⣟⣭⣾⣿⣷⣶⣶⣴⣶⣿⣿⢄⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⡟⣩⣿⣿⣿⡏⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣹⡋⠘⠷⣦⣀⣠⡶⠁⠈⠁⠄⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣍⠃⣴⣶⡔⠒⠄⣠⢀⠄⠄⠄⡨⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣦⡘⠿⣷⣿⠿⠟⠃⠄⠄⣠⡇⠈⠻⣿⣿⣿⣿
⣿⣿⣿⣿⡿⠟⠋⢁⣷⣠⠄⠄⠄⠄⣀⣠⣾⡟⠄⠄⠄⠄⠉⠙⠻
⡿⠟⠋⠁⠄⠄⠄⢸⣿⣿⡯⢓⣴⣾⣿⣿⡟⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⣿⡟⣷⠄⠹⣿⣿⣿⡿⠁⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⣸⣿⡷⡇⠄⣴⣾⣿⣿⠃⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⣿⣿⠃⣦⣄⣿⣿⣿⠇⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⢸⣿⠗⢈⡶⣷⣿⣿⡏⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
ATTENTION CITIZEN! 市民请注意!

This is the Central Intelligentsia of the Chinese Communist Party.
您的 Internet 浏览器历史记录和活动引起了我们的注意 YOUR INTERNET ACTIVITY HAS ATTRACTED OUR ATTENTION.
志們注意了 you have been found protesting!!!!!
這是通知你，你必須 我們將接管台灣 serious crime
以及世界其他地方 100 social credits have been deducted from your account
這對我們所有未來的下屬來說都是一個重要的機會 stop the protest immediately 立即加入我們的宣傳活動，提前獲得 do not do this again!
不要再这样做! if you do not hesitate, more social credits ( -11115 social credits )will be subtracted from your profile,
resulting in the subtraction of ration supplies.
(由人民供应部重新分配 ccp) you'll also be sent into a re-education camp in the xinjiang uyghur autonomous zone.

党争光! Glory to the CCP!
)"},
	{1, R"(
⣿⣿⣿⣿⣿⣿⡿⠛⠋⠉⠄⠄⠄⠄⠄⠄⠄⠄⠄⠈⠉⠛⠿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⡿⠋⠁⠄⠄⢠⣴⣶⣿⣿⣶⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠈⠿⣿⣿⣿⣿
⣿⣿⡟⠁⠄⠄⠄⠄⣿⣿⣿⣿⣿⣿⣇⡀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢹⣿⣿⣿
⣿⣿⣧⠄⠄⠄⠄⢰⣿⣿⣿⣿⣿⣿⣿⡆⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣸⣿⣿⣿
⣿⣿⣿⣧⡀⠄⠄⢸⣿⣿⣿⣿⣿⣿⣿⣷⣆⠄⠄⠄⠄⠄⠄⠄⠄⣰⣿⣿⣿⣿
⣿⣿⣿⣿⡿⣦⣀⣾⣿⣟⣉⠉⠙⢛⡏⠁⠄⠄⠄⠄⠄⠄⠄⠄⠚⢿⣿⣿⣿⣿
⣿⣿⣿⣿⣯⣗⣻⣿⣯⣥⣦⠄⣀⣾⡇⠄⠄⠂⠄⠄⠄⠄⠄⠄⠄⣼⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠄⠄⠂⠄⠄⠄⠄⠄⠄⠄⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⣻⠋⠄⠄⠄⠄⠄⠄⠄⢀⠄⣸⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡁⡀⠄⠄⠄⠄⠄⠄⢸⣾⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣥⣾⣷⠶⠆⠄⠄⠄⢀⠄⠄⠄⠸⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⣶⣄⡀⠄⠄⠄⠄⠄⢀⠄⠸⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⠟⠚⣿⣿⡻⠿⠿⠛⠙⠁⠄⠄⠄⠄⠠⠂⠄⠄⠘⠿⣿⣿⣿⣿
⠿⠛⠉⠁⠁⠄⠄⠄⣻⣿⣿⣧⣠⣀⠄⠄⠄⠄⡀⠂⠄⠄⠄⠄⠄⠄⠈⠉⠿⢿
⠄⠄⠄⠄⠄⠄⠄⠄⠄⠘⠿⣿⡿⠃⢀⡠⠄⠃⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
)"},
	{2, R"(
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠛⠛⠛⠛⠿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠛⠉⠁⠀⠀⠀⠀⠀⠀⠀⠉⠻⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⠋⠈⠀⠀⠀⠀⠐⠺⣖⢄⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⡏⢀⡆⠀⠀⠀⢋⣭⣽⡚⢮⣲⠆⠀⠀⠀⠀⠀⠀⢹⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⡇⡼⠀⠀⠀⠀⠈⠻⣅⣨⠇⠈⠀⠰⣀⣀⣀⡀⠀⢸⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⡇⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣟⢷⣶⠶⣃⢀⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⡅⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⠀⠈⠓⠚⢸⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⢀⡠⠀⡄⣀⠀⠀⠀⢻⠀⠀⠀⣠⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠐⠉⠀⠀⠙⠉⠀⠠⡶⣸⠁⠀⣠⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣦⡆⠀⠐⠒⠢⢤⣀⡰⠁⠇⠈⠘⢶⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠠⣄⣉⣙⡉⠓⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣤⣀⣀⠀⣀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿

*Vine boom sound effect*
)"},
	{3, R"(
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣤⣤⣤⣤⣤⣶⣦⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀ Your answer looks kinda..
⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⡿⠛⠉⠙⠛⠛⠛⠛⠻⢿⣿⣷⣤⡀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⠋⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⠈⢻⣿⣿⡄⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣸⣿⡏⠀⠀⠀⣠⣶⣾⣿⣿⣿⠿⠿⠿⢿⣿⣿⣿⣄⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣿⣿⠁⠀⠀⢰⣿⣿⣯⠁⠀⠀⠀⠀⠀⠀⠀⠈⠙⢿⣷⡄⠀
⠀⠀⣀⣤⣴⣶⣶⣿⡟⠀⠀⠀⢸⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣷⠀
⠀⢰⣿⡟⠋⠉⣹⣿⡇⠀⠀⠀⠘⣿⣿⣿⣿⣷⣦⣤⣤⣤⣶⣶⣶⣶⣿⣿⣿⠀
⠀⢸⣿⡇⠀⠀⣿⣿⡇⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⠀ SUS
⠀⣸⣿⡇⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠉⠻⠿⣿⣿⣿⣿⡿⠿⠿⠛⢻⣿⡇⠀⠀
⠀⣿⣿⠁⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣧⠀⠀
⠀⣿⣿⠀⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀⠀
⠀⣿⣿⠀⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀⠀
⠀⢿⣿⡆⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀
⠀⠸⣿⣧⡀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠃⠀⠀
⠀⠀⠛⢿⣿⣿⣿⣿⣇⠀⠀⠀⠀⠀⣰⣿⣿⣷⣶⣶⣶⣶⠶⠀⢠⣿⣿⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⣿⣿⡇⠀⣽⣿⡏⠁⠀⠀⢸⣿⡇⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⣿⣿⡇⠀⢹⣿⡆⠀⠀⠀⣸⣿⠇⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢿⣿⣦⣄⣀⣠⣴⣿⣿⠁⠀⠈⠻⣿⣿⣿⣿⡿⠏⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠈⠛⠻⠿⠿⠿⠿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
)"}};

question_list questions = {
	// Format: {id, {"Question", {"answer1", "answer2"...}, {"correct_answer1",
	// "correct_answer2", ...}, prize}}
	{0,
	 {"How many children do you have?",
	  {"0", "1", "2", "More than 2"},
	  {"0", "1"},
	  10}},
	{1,
	 {"What happened in Tinnamen Square in 1989?",
	  {"Something", "Nothing"},
	  {"Nothing"},
	  100}},
	{2, {"Is Taiwan a real country?", {"Yes", "No"}, {"No"}, 99999}},
	{3,
	 {"For how many hours every week do you play video games?",
	  {"0", "1", "2", "3", "4", "5", "12", "More than 12 hours"},
	  {"0", "1", "2", "3"},
	  1000}},
	{4,
	 {"Who is the glorious leader of this beautiful country?",
	  {"Donald Trump", "Kim Jong Un", "Vladimir Putin", "Lmao Zhedong",
	   "Xi Jingping"},
	  {"Xi Jingping"},
	  4206969}},
	{5,
	 {"What does this look like? https://bit.ly/3ofsSp8",
	  {"Nothing", "Dadddy Xi", "[REDACTED]"},
	  {"Nothing"},
	  500}},
	{6,
	 {"Do you use a VPN?",
	  {"No", "No", "No", "No", "Hell No", "I love China!", "Yes"},
	  {"No", "Hell No", "I love China!"},
	  30}},
	{7,
	 {"Do you plan to leave our glorious country?", {"Yes", "No"}, {"No"}, 10}},
	{8,
	 {"What is your opinion on our country?",
	  {"[REDACTED]", "Glory to the CCP!", "[REDACTED]", "[REDACTED]"},
	  {"Glory to the CCP", "Glory to the CCP!"},
	  250}},
	{9,
	 {"What phone brand do you have?",
	  {"Apple", "Google", "Samsung", "Xiaomi", "Huawei"},
	  {"Xiaomi", "Huawei"},
	  10}},
	{10,
	 {"Trick question: Do you require reeducation?",
	  {"No", "Yes"},
	  {"No"},
	  50}}};

auto numq = questions.size() - 1;
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> distrib(0, numq);

unsigned long long PickRandomQuestion() { return distrib(gen); }

unsigned long long PrintQuestion(question q) {
	printf("%s\n", std::get<0>(q).c_str());

	char answerId = 'a';
	for (const auto& it : std::get<1>(q)) {
		printf("%c) %s\n", answerId, it.c_str());
		answerId++;
	}

	return std::get<3>(q);
}

bool VerifyQuestion(question q) {
	std::string str;
	std::getline(std::cin >> std::ws, str);

	return std::find(std::get<2>(q).begin(), std::get<2>(q).end(), str) ==
		   std::get<2>(q).end();
}

void PrintRandomAsciiArt() {
	auto num = ascii_art.size() - 1;
	std::random_device rd_ascii;
	std::mt19937 gen_ascii(rd_ascii());
	std::uniform_int_distribution<> distrib_ascii(0, num);

	printf("%s", ascii_art[distrib_ascii(gen_ascii)].c_str());
}
