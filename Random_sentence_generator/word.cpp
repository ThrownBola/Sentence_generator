#include "word.h"
#include <iostream>

using namespace std;

WordList::WordList(string w, string n) :word{ w }, nextWord{ n }, count{ 1 } {}

void WordList::setWord(string w) { word = w; }

string WordList::getWord() const { return word; }

void WordList::plusNext(string w) { nextWord.push_back( w ); }

string WordList::getNext(int r) { return nextWord[r]; }

size_t WordList::getNextSize() const { return nextWord.size(); }

void WordList::increment() { count++; }

long int WordList::getCount() const { return count; }
