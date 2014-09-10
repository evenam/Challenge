#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

std::vector<std::string> wordList;
bool wordCompare(std::string word1, std::string word2);

int main(int argc, char** argv)
{
	std::ifstream infile;
	std::string inputWord;
	infile.open("randomlist.txt");
	while (infile >> inputWord)
		wordList.push_back(inputWord);

	std::sort(wordList.begin(), wordList.end(), wordCompare);

	for (std::vector<std::string>::iterator i = wordList.begin(); i != wordList.end(); i ++)
		std::cout << (*i) << std::endl;

	return 0;
}

bool wordCompare(std::string word1, std::string word2)
{
	if (word1.size() < word2.size()) return true;
	if (word2.size() < word1.size()) return false;
	std::reverse(word1.begin(), word1.end());
	std::reverse(word2.begin(), word2.end());
	return (word1 < word2);
}
