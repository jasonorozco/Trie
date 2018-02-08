#ifndef TRIE_H
#define TRIE_H

#include <vector>
#include <string>
#include <utility>

using namespace std;


class Trie
{
    public:

        struct Node {
            vector<Node*> children;
            string data;
            int weight;
            int numOfChildren;
	    bool isLeaf;

            Node* addChild(Node* it,string data, int weight);
            Node* getChild(int child);
	    Node(string data, int weight);
        };
            Trie();
            ~Trie();
            void addSentence(vector<string> sentence, int weight);
            void getMaxDegrees();
	    Node* listContents(Node* parent);
	    Node* getHead();
	    void getSubStrings(vector<string> target);

    private:
        vector < pair<int, string> > answer;
        Node* root;
        string hiDegree;
        int hiDegreeVal;
	Node* treeDFS(Node* top, string main);
		
        };

#endif // TRIE_H
