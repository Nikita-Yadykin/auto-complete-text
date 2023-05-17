#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#define ALPHABET_SIZE 26

struct TrieNode
{
public:

	static TrieNode* getNewNode();
	static void findWordsInTrie(TrieNode* node, const string& prefix, vector<string>& suggestions);
	static void insert(TrieNode* root, const string& word);
	static void displayDictionary(TrieNode* root, string word);
	static void search(TrieNode* root, const string& prefix, vector<string>& suggestions);

private:

	TrieNode* children[ALPHABET_SIZE]; //  Массив указателей на дочерние узлы
	bool isEndOfWord; // Если true, то это конец слова

};
