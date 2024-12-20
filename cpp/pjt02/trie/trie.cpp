#include <vector>
#include <iostream>
#include <string>
#include "trie.h"
using namespace std;

Node::Node()                        { mContent = ' '; mMarker = false; }
Node::~Node()                       {}
char Node::Content()                { return mContent; }
void Node::SetContent(char c)       { mContent = c; }
bool Node::WordMarker()             { return mMarker; }
void Node::SetWordMarker()          { mMarker = true; }
void Node::AppendChild(Node* child) { mChildren.push_back(child); }

Trie::Trie()    { root = new Node(); }
Trie::~Trie()   {}

Node* Node::FindChild(char c) {
    for ( size_t i = 0; i < mChildren.size(); i++ ) {
        Node* tmp = mChildren.at(i);
        if ( tmp->Content() == c ) {
            return tmp;
        }
    }
    return NULL;
}


void Trie::AddWord(string s) {
	Node* current = root;
	
	if ( s.length() == 0 ) {
	    current->SetWordMarker(); // an empty word
	    return;
	}    
	if ( SearchWord(s) ) {
	    cout << s << " already exists in Trie. Skipping." << endl;
	    return;
	}
	for ( size_t i = 0; i < s.length(); i++ ) { 
        Node* child = current->FindChild(s[i]);
        if ( child != NULL ) {
            current = child;
        } else {
            Node* tmp = new Node();
            tmp->SetContent(s[i]);
            current->AppendChild(tmp);
            current = tmp;
        }
        if ( i == s.length() - 1 ) {
            current->SetWordMarker();
        }
    }
}

bool Trie::SearchWord(string s) {
    Node* current = root;

    while ( current != NULL ) {
        for ( size_t i = 0; i < s.length(); i++ ) {
            Node* tmp = current->FindChild(s[i]);
            if ( tmp == NULL ) {
                return false;
            }
            current = tmp;
        }

        if ( current->WordMarker() ) {
            return true;
        } else {
            return false;
        }
    }
    return false;
}
