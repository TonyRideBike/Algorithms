/**
 * POJ 2934
 * need to use dictionary tree.
 */

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

#define DEBUG1 1
#define DEBUG2 0

using namespace std;

int main()
{
#if DEBUG1
    freopen("2934.in", "r", stdin);
#endif
    int in;
    vector<string> dictionary;
    cin >> in;
    while(in--)
    {
        string input;
        cin >> input;
        dictionary.push_back(std::vector<string>::value_type(input));
    }
#if DEBUG2
    for (vector<string>::iterator i = dictionary.begin();
            i != dictionary.end(); ++i)
    {
        cout << *i << endl;
    }
#endif
    cin >> in;
    while (in--)
    {
        string input;
        cin >> input;
        bool found = false;
        vector<string> candidates;
        for (vector<string>::iterator i = dictionary.begin();
                i != dictionary.end(); ++i)
        {
            if ((*i).length() == input.length())
            {
                if (input.compare(*i) == 0)
                {
                    cout << input << " is correct" << endl;
                    found = true;
                    break;
                }
                int counter = 0;
                for (string::size_type ix = 0; ix != (*i).size(); ++ix)
                {
                    if ((*i)[ix] != input[ix])
                    {
                        counter++;
                    }
                }
                if (counter == 1)
                {
                    candidates.push_back((*i));
                }
            }
            else if ((*i).length() == input.length() + 1 ||
                     (*i).length() == input.length() - 1)
            {
                string::size_type inx = 0, ix = 0;
                int counter = 0;
                while (ix <= (*i).size() && inx <= input.size())
                {
                    if ((*i)[ix] == input[inx])
                    {
                        ix++;
                        inx++;
                    }
                    else if (counter == 0)
                    {
                        (*i).length() > input.length() ? ix++ : inx++;
                        counter++;
                    }
                    else
                    {
                        ix++;
                        inx++;
                        counter++;
                    }
                }
                if (counter == 1)
                {
                    candidates.push_back(*i);
                }
            }
        }
        if (!found)
        {
            if (candidates.empty())
            {
                cout << input << " is unknown" << endl;
            }
            else
            {
                cout << input << " is a misspelling of ";
                for (vector<string>::iterator i = candidates.begin();
                        i != candidates.end(); ++i)
                {
                    cout << *i << " ";
                }
                cout << endl;
            }
        }
    }
}

