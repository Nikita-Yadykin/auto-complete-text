#include"TrieNode.h"

// Функция создания нового TrieNode
TrieNode* TrieNode::getNewNode()
{
	TrieNode* node = new TrieNode;
	node->isEndOfWord = false;
	for (int i = 0; i < ALPHABET_SIZE; i++)
		node->children[i] = nullptr;
	return node;
}

// Рекурсивная функция для обхода Trie и поиска всех слов с заданным префиксом
void TrieNode::findWordsInTrie(TrieNode* node, const string& prefix, vector<string>& suggestions)
{
	if (node->isEndOfWord)
		suggestions.push_back(prefix); // Добавляем слово в список дополнений

	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (node->children[i])
		{
			char ch = static_cast<char>('a' + i);
			findWordsInTrie(node->children[i], prefix + ch, suggestions); // Рекурсивный вызов функции для дочернего узла
		}
	}
}

// Функция для вставки слова в Trie
void TrieNode::insert(TrieNode* root, const string& word)
{
	TrieNode* node = root;
	for (char ch : word)
	{
		int index = ch - 'a'; // Определяем индекс дочернего узла
		if (!node->children[index])
			node->children[index] = getNewNode(); // Если дочерний узел не существет, создаем его
		node = node->children[index];
	}
	node->isEndOfWord = true; // Отмечаем последний узел как конец слова
}

// Функция отображения всех слов в словаре
void TrieNode::displayDictionary(TrieNode* root, string word)
{
	if (root->isEndOfWord)
	{
		cout << word << endl; // Если это конец слова, отображаем его.
	}

	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (root->children[i])
		{
			char ch = static_cast<char>('a' + i);
			displayDictionary(root->children[i], word + ch); // Рекурсивный вызов функции для дочернего узла
		}
	}
}

// Функция для поиска слов с заданным префиксом в Trie
void TrieNode::search(TrieNode* root, const string& prefix, vector<string>& suggestions)
{
	TrieNode* node = root;
	for (char ch : prefix)
	{
		int index = ch - 'a';
		if (!node->children[index])
			return; //Если символ не найден в Trie, возвращаем значение
		node = node->children[index];
	}
	TrieNode::findWordsInTrie(node, prefix, suggestions); // Начинаем обход с узла, соответствующего префиксу
}
