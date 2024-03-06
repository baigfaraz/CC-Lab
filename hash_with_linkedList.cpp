#include <iostream>
#include <string>

using namespace std;

const int hash_table_size = 10;

struct Node
{
    string word;
    Node *next;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(NULL) {}

    void insert(const string &word)
    {
        Node *newNode = new Node;
        newNode->word = word;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    Node *getHead() const
    {
        return head;
    }
};

class HashTable
{
private:
    LinkedList table[hash_table_size];

    int hashFunction(const string &word)
    {
        int sum = 0;
        for (char c : word)
        {
            sum += static_cast<int>(c);
        }
        return sum % hash_table_size;
    }

public:
    void insert(const string &word)
    {
        int index = hashFunction(word);
        table[index].insert(word);
    }

    void printTable()
    {
        for (int i = 0; i < hash_table_size; i++)
        {
            cout << i << " | ";
            Node *curr = table[i].getHead();
            while (curr != NULL)
            {
                cout << curr->word << " -> ";
                curr = curr->next;
            }
            cout << "NULL" << endl;
        }
    }

    bool searchWord(const string &word)
    {
        int index = hashFunction(word);
        Node *curr = table[index].getHead();
        while (curr != NULL)
        {
            if (curr->word == word)
            {
                cout << "Word '" << word << "' found at index " << index << endl;
                return true;
            }
            curr = curr->next;
        }
        cout << "Word '" << word << "' not found" << endl;
        return false;
    }
};

int main()
{
    HashTable hashTable;

    string sentence;
    cout << "Paragrapgh : ";
    getline(cin, sentence);

    string word;
    for (char c : sentence)
    {
        if (c == ' ' || c == '.' || c == ',' || c == '!' || c == '?')
        {
            if (!word.empty())
            {
                hashTable.insert(word);
                word.clear();
            }
        }
        else
        {
            word += c;
        }
    }

    hashTable.printTable();

    string searchWord;
    cout << "Enter a word to search: ";
    cin >> searchWord;
    hashTable.searchWord(searchWord);

    return 0;
}
