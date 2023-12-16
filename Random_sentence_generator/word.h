#ifndef word_h
#define word_h

#include <iostream>
#include <vector>

class WordList {
public:
	WordList(std::string, std::string);
	void setWord(std::string);
	std::string getWord() const;
	void plusNext(std::string);
	std::string getNext(int);
	void setCount(int);
	long int getCount() const;
	void increment();
	size_t getNextSize() const;
private:
	std::vector<std::string> nextWord;
	std::string word;
	long int count;
};

#endif