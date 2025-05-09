#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <vector>
using namespace std;

class Compare {
public:
    bool operator() (pair<string, int>& p1, pair<string, int>& p2) {
        if (p1.second < p2.second)
            return true;
        if (p1.second > p2.second)
            return false;
        if (p1.first > p2.first)
            return false;
        return true;
    }
};
void toUpper(string& s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = s[i] - 32;
    }
}
int main()
{

    string myString;
    ifstream myFile("input.txt");
    string sep = "!,?. ";
    string word;
    if (!myFile)
    {
        printf("error la deschiderea fisierului: input.txt");
        return 0;
    }
    if (!getline(myFile, myString)) {
        printf("error la citirea din fisier: input.txt");
        return 0;
    }
    map<string, int> myMap;
    printf("Sirul de caractere citit este: %s\n", myString.c_str());
    toUpper(myString);
    printf("Sirul de caractere citit este: %s\n", myString.c_str());
    for (int i = 0; i < myString.size(); i++)
    {
        if (sep.find(myString[i]) == string::npos)
            word += myString[i];
        else
        {
            if (!word.empty()) {
                myMap[word]++;
                word.clear();
            }


        }
    }
    for (auto mapIterator = myMap.begin(); mapIterator != myMap.end(); mapIterator++) {
        printf("cuvantul: %s apare de %d ori\n", mapIterator->first.c_str(), mapIterator->second);
    }
    priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> myQueue;
    for (auto mapIterator = myMap.begin(); mapIterator != myMap.end(); mapIterator++) {
        myQueue.push(pair<string, int>(mapIterator->first, mapIterator->second));
    }
    printf("\n\nSortate\n");
    while (!myQueue.empty())
    {
        printf("%s => %d\n", myQueue.top().first.c_str(), myQueue.top().second);
        myQueue.pop();
    }
}