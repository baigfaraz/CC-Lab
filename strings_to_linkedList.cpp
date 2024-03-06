#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string word;
    Node *next;
};

void insertNode(Node *&head, string word)
{
    Node *newWord = new Node();
    newWord->word = word;
    newWord->next = nullptr;

    if (head == nullptr)
    {
        head = newWord;
    }
    else
    {
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }

        temp->next = newWord;
    }
}

void printLL(Node *&head)
{
    Node *temp = head;

    while (temp)
    {
        cout << temp->word << " -> ";
        temp = temp->next;
    }
}

int main()
{
    string sentence;
    cout << "Enter the complete sentence = ";
    getline(cin, sentence);

    Node *head = nullptr;

    string word;

    for (int i = 0; i < sentence.length(); i++)
    {
        if (sentence[i] == ' ' || i == sentence.length() - 1 || sentence[i] == '.')
        {
            if (i == sentence.length() - 1)
            {
                word += sentence[i];
            }
            insertNode(head, word);
            word = "";
        }
        else
        {
            word += sentence[i];
        }
    }

    cout << "The sentence is: " << endl;
    printLL(head);

    return 0;
}
