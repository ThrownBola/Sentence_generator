#include "word.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <time.h>
#include <stdlib.h>

using namespace std;

int findWord(string nextWord, vector<WordList>& list);
string randomNext(vector<WordList>& list, int fiw);
int random_first(vector<WordList>& list);


int main() {
	srand(time(NULL));
	vector<WordList> list;
	vector<WordList> first;
	int result;
	string name;
	string word, word2;
	cout << "불러올 데이터 이름: ";
	cin >> name;
	fstream learning{ name + ".txt", ios::in };
	if (!learning) {
		cerr << "와 샌즈";
		exit(EXIT_FAILURE);
	}
	learning >> word >> word2;
	int nnn{ 0 };
	while (1) {
		if (nnn == 0) {
			result = findWord(word, first);
			if (result == -1) {
				first.push_back({ word, word2 });
			}
			else {
				first[result].increment();
				first[result].plusNext(word2);
			}
			nnn = 1;
		}
		else {
			result = findWord(word, list);
			if (result == -1) {
				list.push_back({ word, word2 });
			}
			else {
				list[result].increment();
				list[result].plusNext(word2);
			}
		}
		
		if (word[word.size() - 1] == '.' || word[word.size() - 1] == '?' || word[word.size() - 1] == '!') {
			nnn = 0;
		}
		word = word2;
		if (!(learning >> word2)) {
			break;
		}
	}
	cout << "불러오기 완료!" << endl;
	string a;
	int fiw;
	int re;

	cout << "반복 횟수: ";
	cin >> re;
	cout << re << "회 반복, 아무 값이나 입력시 시작." << endl;

	while (1) {
		while (cin >> a) {
			if (a == "q") {
				cout << "반복 횟수 수정: ";
				cin >> re;
			}
			fiw = rand() % (first.size());
			cout << first[fiw].getWord() << " ";
			/*if (first[fiw].getWord()[first[fiw].getWord().size() - 1] == '.' || first[fiw].getWord()[first[fiw].getWord().size() - 1] == '?' || first[fiw].getWord()[first[fiw].getWord().size() - 1] == '!') {
				break;
			}*/
			for (int i{}; i < re; i++) {
				if (i > 0) {
					fiw = findWord(randomNext(list, fiw), first);
					if (fiw == -1) fiw = random_first(first);
					cout << first[fiw].getWord() << " ";
					/*if (first[fiw].getWord()[first[fiw].getWord().size() - 1] == '.' || first[fiw].getWord()[first[fiw].getWord().size() - 1] == '?' || first[fiw].getWord()[first[fiw].getWord().size() - 1] == '!') {
						break;
					}*/
				}
				fiw = findWord(randomNext(first, fiw), list);
				if (fiw == -1) fiw = random_first(list);
				while (1) {
					cout << list[fiw].getWord() << " ";
					if (list[fiw].getWord()[list[fiw].getWord().size() - 1] == '.' || list[fiw].getWord()[list[fiw].getWord().size() - 1] == '?' || list[fiw].getWord()[list[fiw].getWord().size() - 1] == '!') {
						break;
					}
					fiw = findWord(randomNext(list, fiw), list);
					if (fiw == -1) fiw = random_first(list);
				}
			}
			cout << endl;
		}
		cin.clear();
	}
}

string randomNext(vector<WordList>& list, int fiw) {
	if (list[fiw].getNextSize() == 0) {
		random_first(list);
		return list[fiw].getWord();
	}
	else {
		int r = rand() % (static_cast<int>(list[fiw].getNextSize()));
		return list[fiw].getNext(r);
	}
}

int findWord(string nextWord, vector<WordList>& list) {
	for (int i{}; i < list.size(); i++) {
		if (list[i].getWord() == nextWord) {
			return i;
		}
	}
	return -1;
}

int random_first(vector<WordList>& list) {
	int fiw;
	fiw = rand() % (list.size());
	return fiw;
}