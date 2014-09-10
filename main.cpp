#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

std::vector<std::string> wordList;
int wordCompare(std::string word1, std::string word2);

int main(int argc, char** argv)
{
	std::ifstream infile;
	std::string inputWord;
	infile.open("randomlist.txt");
	while (infile >> inputWord)
		wordList.push_back(inputWord);

	std::sort(&wordList, wordList.size(), sizeof(std::string), wordCompare);

	for (std::vector<std::string>::iterator i = wordList.begin(); i != wordList.end(); i ++)
		std::cout << (*i) << std::endl;

	std::cin.get();
	return 0;
}

int wordCompare(std::string word1, std::string word2)
{
	if (word1.size() < word2.size()) return true;
	if (word2.size() < word1.size()) return false;
	return (word1.compare(word2));
}
