

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

const int BUFFER_SIZE = 4096;

bool isLetter(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

bool isUnderscore(char c)
{
    return c == '_';
}

void processBuffer(const vector<char> &buffer)
{
    char lex[20];
    int i = 0;
    int li = 0;
    int state = 0;

    while (i < BUFFER_SIZE)
    
    {
        switch (state)
        {
        case 0:
            if (isLetter(buffer[i]) || buffer[i] == '_')
            {
                lex[li] = buffer[i];
                li++;
                state = 1;
            }
            break;
        case 1:
            if (isLetter(buffer[i]) || buffer[i] == '_' || isDigit(buffer[i]))
            {
                lex[li] = buffer[i];
                li++;
            }
            else
            {
                lex[li] = '\0';
                li = 0;
                state = 2;
                cout << "Lex: " << lex << endl;
            }
            break;
        case 2:
            state = 0;
            break;
        }
        i++;
    }
}

int main()
{
    ifstream file("C:\\Users\\lenovo\\Desktop\\CC-Lab\\file.txt", ios::binary);

    if (!file.is_open())
    {
        cerr << "Error opening file." << endl;
        return 1;
    }

    vector<char> buffer1(BUFFER_SIZE);
    vector<char> buffer2(BUFFER_SIZE);

    bool toggle
     = true;

    while (!file.eof())
    {
        if (toggle)
        {
            file.read(buffer1.data(), BUFFER_SIZE);
            processBuffer(vector<char>(buffer1.begin(), buffer1.begin() + file.gcount()));
        }
        else
        {
            file.read(buffer2.data(), BUFFER_SIZE);
            processBuffer(vector<char>(buffer2.begin(), buffer2.begin() + file.gcount()));
        }

        toggle= !toggle;
    }

    file.close();

    return 0;
}