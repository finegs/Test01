#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <cstring>
#include <set>

#include "trie.h"

std::set <char> CharSet ( char oldArr[4][4], const int n ) { 
    std::set <char> uniqueCharSet;
    for( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < n; j++ ) {
            uniqueCharSet.insert( oldArr[i][j] );
        }
    }
    return uniqueCharSet;
}

bool IsWordInCharSet(std::set<char> charSet, const std::string& word) {
	for(auto iter = word.cbegin();iter != word.cend();iter++) {
		if(charSet.find(*iter) != charSet.cend()) return true;
	}
	return false;
}

void LoadTrie( std::set <char> charSet, int limit ) {
    Trie *trie = new Trie();
    std::string filename = "enable1.txt";
    std::string word;
    std::ifstream dict1;
    dict1.open( filename, std::ios::in );
    if( dict1.is_open() ) {
        bool wordInCharSet = false;
        int i = 0;
        int wordLength = 0;
        while( getline( dict1, word ) ) {
            wordLength = word.length();
            wordInCharSet = IsWordInCharSet( charSet, word);    
            if ( wordLength <= limit && wordInCharSet && i < 10 ) {
                std::cout << "Inserting: " << word << endl;
                trie->AddWord( word );
                i++;

                std::cout << "Searching for " << word << "\n";
                if (trie->SearchWord(word) ) {
                    std::cout << "Found " << word << " \n";
                } else {
                    std::cout << "NOT FOUND " << word << "\n";
                }
            }
        }
        std::cout << i << " words with <= " << limit << " characters transferred\n";
    }

    std::string newTestWord = "AHA!";
    trie->AddWord(newTestWord);
    std::cout << "Searching for " << newTestWord << "\n";
    if (trie->SearchWord(newTestWord) ) {
        std::cout << "Found " << newTestWord << " \n";
    } else {
        std::cout << "NOT FOUND " << newTestWord << "\n";
    }

    dict1.close();
}

int main( int argc, char *argv[] ) {
	if(argc>1) {
		cout << argv[1] << endl;
	}

    char matrixArr[4][4] = {{'s','t','n','g'},
                            {'e','i','a','e'},
                            {'d','r','l','s'},
                            {'s','e','p','o'}};

    std::set<char> charSet = CharSet ( matrixArr, 4 );
    LoadTrie ( charSet, 16);

    return 0;
}
