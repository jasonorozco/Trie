#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <stdlib.h>
#include "Trie.h"


using namespace std;

	template<typename Out>
	void split(const std::string &s, char delim, Out result) {
	    std::stringstream ss(s);
	    std::string item;
	    while (std::getline(ss, item, delim)) {
		*(result++) = item;
	    }
	}

	std::vector<std::string> split(const std::string &s, char delim) {
	    std::vector<std::string> elems;
	    split(s, delim, std::back_inserter(elems));
	    return elems;
	}


int main()
{
	string next;
	string target;
	vector<string> sentences;

	getline(cin, next);
	while(next != ""){
		sentences.push_back(next);
		getline(cin, next);
}
	getline(cin, target);
	vector<string> targets = split(target, ' ');

	//process and parse string
	

	Trie trie;
	for(int i = 0; i < sentences.size(); i++){
		vector<string> tokens = split(sentences[i], ' ');
		int weight = atoi(tokens[0].c_str());
		tokens.erase(tokens.begin());
		trie.addSentence(tokens, weight);
		tokens.clear();
}
	trie.getSubStrings(targets);
	return 0;
}
