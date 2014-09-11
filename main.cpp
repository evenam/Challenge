#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

// social network graph
struct WordNode
{
	std::string word;
	std::vector<WordNode*> friends;
};

// enough parenthesis to keep basic expression safe
#define min(a, b) (((a) < (b)) ? (a) : (b))

bool wordCompare(std::string word1, std::string word2);
bool friends(std::string word1, std::string word2);
WordNode* socialize(std::string word);
void print();

// globals
WordNode* socialNetwork;
std::vector<std::string> wordList;
std::vector<WordNode*> networkGraph;

int main(int argc, char** argv)
{
	std::ifstream infile;
	std::string inputWord;
	infile.open("randomlist.txt");
	while (infile >> inputWord)
		wordList.push_back(inputWord);

	std::sort(wordList.begin(), wordList.end(), wordCompare);
	std::cin >> inputWord;
	socialNetwork = socialize(inputWord);
	print();

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
		if (word1 == tw2)
			return true;
		if (word2 == tw1)
			return true;
		if (tw1 == tw2)
			return true;
	}
	
	return false;
}

// build social network graph
WordNode* socialize(std::string word)
{
	WordNode* node = new WordNode();
	node->word = word;
	networkGraph.push_back(node);
	std::cout << "added " << word << "\n checking rest of word list...\n";
	for (auto i = wordList.begin(); i != wordList.end();)
	{
		if (friends(*i, word))
		{
			std::string friendWord = *i;
			wordList.erase(i);
			node->friends.push_back(socialize(friendWord));
		}
		else i++;
	}
	std::cout << "checking rest of social graph...\n";
	// grab the rest of the connections
	for (auto i = networkGraph.begin(); i != networkGraph.end(); i++)
	{
		if ((*i)->word == word) continue;
		if (friends((*i)->word, word))
			node->friends.push_back(*i);
	}
	return node;
}

void print()
{
	for (auto i = networkGraph.begin(); i != networkGraph.end(); i ++)
	{
		std::cout << "WORD: "<< (*i)->word << "\nFRIENDS:\n";
		for (auto j = (*i)->friends.begin(); j != (*i)->friends.end(); j ++)
			std::cout << "\t" << (*j)->word << "\n";
	}
}
