#include"TrieNode.h"

int main()
{
	TrieNode* root = TrieNode::getNewNode();

	// Чтение файла со словарем и вставка слов в Trie
	ifstream dictionaryFile("dictionary.txt");
	string word;
	while (getline(dictionaryFile, word))
	{
		TrieNode::insert(root, word);
	}
	dictionaryFile.close();

	while (true)
	{
		cout << "Enter the beginning of the word to get the complement or" << endl
			<< "'1' to quit" << endl
			<< "'2' to display all words" << endl
			<< ": ";
		string input;
		cin >> input;

		if (input == "1")
		{
			break;
		}
		else if (input == "2")
		{
			cout << "Dictionary words:" << endl;
			TrieNode::displayDictionary(root, "");
			cout << endl;
		}
		else
		{
			vector<string> suggestions;
			TrieNode::search(root, input, suggestions);

			if (suggestions.empty())
			{
				cout << "No additions found." << endl << endl;
			}
			else
			{
				cout << endl << "Additions:" << endl;
				for (const string& suggestion : suggestions)
				{
					cout << suggestion << endl;
				}
				cout << endl;
			}
		}
	}

	return 0;
}
