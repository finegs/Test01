#pragma once
#include <vector>
#include <string>

using namespace std;
class Node {
    public:
        Node();                           
        ~Node();                          
        char  Content();                   // Returns mContent
        void  SetContent(char c);          // Set Node content to char c
        bool  WordMarker();                // A boolean flag if a word has formed
        void  SetWordMarker();             // Sets Word marker in Node
        void  AppendChild( Node* child );  // Appends an element into array
        Node* FindChild(char c);           // Locates character and returns Node

        //vector<Node*> children( { return mChildren; }
        //Node *children() { return mChildren

    private:
        char mContent;
        bool mMarker;
        vector<Node*> mChildren;
};

class Trie {
    public:
        Trie();
        ~Trie();
        void AddWord(string s);           // Adds string to the trie 
        bool SearchWord(string s);        // Finds word in trie
    private:
        Node* root;
};
