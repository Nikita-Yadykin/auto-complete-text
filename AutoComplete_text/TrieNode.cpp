#include"TrieNode.h"

// ������� �������� ������ TrieNode
TrieNode* TrieNode::getNewNode()
{
	TrieNode* node = new TrieNode;
	node->isEndOfWord = false;
	for (int i = 0; i < ALPHABET_SIZE; i++)
		node->children[i] = nullptr;
	return node;
}

// ����������� ������� ��� ������ Trie � ������ ���� ���� � �������� ���������
void TrieNode::findWordsInTrie(TrieNode* node, const string& prefix, vector<string>& suggestions)
{
	if (node->isEndOfWord)
		suggestions.push_back(prefix); // ��������� ����� � ������ ����������

	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (node->children[i])
		{
			char ch = static_cast<char>('a' + i);
			findWordsInTrie(node->children[i], prefix + ch, suggestions); // ����������� ����� ������� ��� ��������� ����
		}
	}
}

// ������� ��� ������� ����� � Trie
void TrieNode::insert(TrieNode* root, const string& word)
{
	TrieNode* node = root;
	for (char ch : word)
	{
		int index = ch - 'a'; // ���������� ������ ��������� ����
		if (!node->children[index])
			node->children[index] = getNewNode(); // ���� �������� ���� �� ���������, ������� ���
		node = node->children[index];
	}
	node->isEndOfWord = true; // �������� ��������� ���� ��� ����� �����
}

// ������� ����������� ���� ���� � �������
void TrieNode::displayDictionary(TrieNode* root, string word)
{
	if (root->isEndOfWord)
	{
		cout << word << endl; // ���� ��� ����� �����, ���������� ���.
	}

	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (root->children[i])
		{
			char ch = static_cast<char>('a' + i);
			displayDictionary(root->children[i], word + ch); // ����������� ����� ������� ��� ��������� ����
		}
	}
}

// ������� ��� ������ ���� � �������� ��������� � Trie
void TrieNode::search(TrieNode* root, const string& prefix, vector<string>& suggestions)
{
	TrieNode* node = root;
	for (char ch : prefix)
	{
		int index = ch - 'a';
		if (!node->children[index])
			return; //���� ������ �� ������ � Trie, ���������� ��������
		node = node->children[index];
	}
	TrieNode::findWordsInTrie(node, prefix, suggestions); // �������� ����� � ����, ���������������� ��������
}
