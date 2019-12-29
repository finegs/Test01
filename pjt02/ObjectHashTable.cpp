#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <ctime>


using namespace std;


class Word {

private:
    string word;

public:
    Word(string word) : word(word) { }

    const string& getWord() const{
        return this->word;
    }

    bool operator==(const Word &other) const {
        return this->word == other.getWord();
    }

};

namespace std {

    template<>
    struct hash<Word> {
        std::size_t operator()(const Word &k) const {
            return hash<string>()(k.getWord());
        }
    };

}

vector <Word> *getAllWords() {
    vector <Word> *allWords = new vector<Word>;

    string filename = "cmudict-0.7b";
    ifstream dataFile;
    dataFile.open(filename);
    string line;

    while (getline(dataFile, line)) {
        string word = line.substr(0, line.find_first_of(" "));
        if (word == "") {
            continue;
        }
        allWords->push_back(Word(word));
    }

    return allWords;
}


int main() {
    clock_t startTime;
    clock_t endTime;
    double elapsedTime;

    vector <Word> *dictionary = getAllWords();
    unordered_set<Word> hashSet;


    startTime = clock();

    for(vector<Word>::const_iterator it = dictionary->begin();
        it != dictionary->end();
        it++){

        hashSet.insert(*it);
    }


    elapsedTime = (double(clock() - startTime) / CLOCKS_PER_SEC) * 1000.0;
    cout << elapsedTime << "ms to populate\n";
    startTime = clock();

    for(vector<Word>::const_iterator it = dictionary->begin();
                                it != dictionary->end();
                                it++){

        if(hashSet.find(*it) == hashSet.end()){
            cout << "Didn't find element" << endl;
        }
    }


    elapsedTime = (double(clock() - startTime) / CLOCKS_PER_SEC) * 1000.0;
    cout << elapsedTime << "ms to search\n";

    return 0;
}
