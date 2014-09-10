#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define min(a, b) (((a) < (b)) ? (a) : (b))

std::vector<std::string> wordList;
bool wordCompare(std::string word1, std::string word2);
bool friends(std::string word1, std::string word2);

int main(int argc, char** argv)
{
	std::ifstream infile;
	//std::string inputWord;
	std::string iWord1, iWord2;
	infile.open("randomlist.txt");
	//while (infile >> inputWord)
	//	wordList.push_back(inputWord);

	//std::sort(wordList.begin(), wordList.end(), wordCompare);

	//for (auto i = wordList.begin(); i != wordList.end(); i ++)
	//	std::cout << (*i) << std::endl;
	std::cin >> iWord1;
	while (iWord1 != "exit")
	{
		std::cin >> iWord2;
		if (friends(iWord1, iWord2))
			std::cout << "FRIENDS!\n";
		else
			std::cout << "ENEMIES!\n";
			
		std::cin >> iWord1;
	}

	return 0;
}

bool wordCompare(std::string word1, std::string word2)
{
	if (word1.size() < word2.size()) return true;
	if (word2.size() < word1.size()) return false;
	return (word1 < word2);
}

bool friends(std::string word1, std::string word2)
{
	if (abs(word1.size() - word2.size()) > 1)
		return false;
	
	std::string tw1, tw2; // temp words for manipulating
	// Testing words in reverse after sorting increases efficiency
	for (int i = min(word1.size(), word2.size()) - 1; i >= 0; i --)
	{	
		tw1 = word1;
		tw2 = word2;
		tw1.erase(i, 1);
		tw2.erase(i, 1);
		std::cout << "TESTING:\t" << word1 << "\t" << word2 << "\n\t\t" 
			<< tw1 << "\t" << tw2 << "\n";
		if (word1 == tw2)
			return true;
		if (word2 == tw1)
			return true;
		if (tw1 == tw2)
			return true;
	}
	
	return false;
}
