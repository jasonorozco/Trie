#include "Trie.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

Trie::Trie()
{
	root = new Node("thedummiestvalueyouwilleverfind", -1);
	hiDegree;
	hiDegreeVal = -1;
}

Trie::~Trie()
{
    //dtor
}

void Trie::addSentence(vector<string> sentence, int weight){
		Node* it = root;
		Node* papa = it;
		vector<string> candidates;
		for(int i = 0; i < sentence.size(); i++){
			candidates.clear();
			for(int i = 0; i < it->children.size(); i++){
				candidates.push_back(it->children[i]->data);
			}
			if(find(candidates.begin(), candidates.end(), sentence[i]) == candidates.end()|| candidates.size()==0){
				papa = it;
				it = it->addChild(it, sentence[i], -1);
				if(i!=0)
					papa->numOfChildren++;
				if(papa->numOfChildren/2 > hiDegreeVal){
					hiDegree = papa->data;
					hiDegreeVal = papa->numOfChildren/2;
				}
			}
			else{
				vector<string>::iterator iter;
				iter = find(candidates.begin(), candidates.end(), sentence[i]);
				int pos = distance(candidates.begin(), iter);
				it = papa = it->getChild(pos);
			
			}
			if(i == sentence.size()-1) {it->weight = weight; it->isLeaf = true;}	
		}		
}
Trie::Node* Trie::treeDFS(Node* top, string main){
	for(int i = 0; i < top->children.size(); i++){
		string origMain = main;
		main.append(top->children[i]->data);
		main.append(" ");
		if(top->children[i]->isLeaf==true && top->children[i]->weight >= 0 )
			answer.push_back( make_pair(top->children[i]->weight, main));
		treeDFS(top->getChild(i), main);
		if(top->getChild(i)->isLeaf == true || top->children.size()>0)
			main = origMain;
		else
			main = "";
	}
}

void Trie::getSubStrings(vector<string> target){
	Node* it = root;
	Node* start = root;
	vector<string> candidates;
		for(int j = 0; j < target.size(); j++){
			it = start;
			for(int i = 0; i < it->children.size(); i++){
				if(it->children[i]->data == target[j]) start = start->getChild(i);
				
			}
		}
	if(start->data==root->data){
		cout << "No valid completion1" << "\n";
		cout << hiDegree << " " << hiDegreeVal << "\n";
		return;
	}
	treeDFS(start, "");
	sort(answer.begin(),answer.end());
	for(int i = answer.size()-1; i >=0; i--){
		answer[i].second.pop_back();
		cout << answer[i].second << endl;
}
	cout << hiDegree << " " << hiDegreeVal << "\n";
	

}




Trie::Node* Trie::getHead(){
	return root;
}

Trie::Node* Trie::Node::addChild(Node* it,string data, int weight){
	Node* newit = it;
	newit->numOfChildren++;
	it = new Node(data, weight);
	newit->children.push_back(it);
	return it;	
}

Trie::Node* Trie::Node::getChild(int child){
	return children[child];
}

Trie::Node::Node(string data, int weight){
	this->weight = weight;
	this->data = data;
	this->numOfChildren = 0;
}

