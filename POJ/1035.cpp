/**
    POJ 1035 Spell Checker
    SW Cert. week 4

    816k 282ms
    */

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

#define DEBUG1 0
#define DEBUG2 0

using namespace std;

int main()
{
#if DEBUG1
    freopen("1035.in", "r", stdin);
#endif
    string in;
    vector<string> dictionary;
    cin >> in;
    while (in != "#")
    {
        dictionary.push_back(std::vector<string>::value_type(in));
        cin >> in;
    }
#if DEBUG2
    for (vector<string>::iterator i = dictionary.begin();
        i != dictionary.end(); ++i)
    {
        cout << *i << endl;
    }
#endif
    cin >> in;
    while (in != "#")
    {
        bool found = false;
        vector<string> candidates;
        for (vector<string>::iterator i = dictionary.begin();
            i != dictionary.end(); ++i)
        {
            if ((*i).length() == in.length())
            {
                if (in.compare(*i) == 0)
                {
                    cout << in << " is correct" << endl;
                    found = true;
                    break;
                }
                int counter = 0;
                for (string::size_type ix = 0; ix != (*i).size(); ++ix)
                {
                    if ((*i)[ix] != in[ix])
                    {
                        counter++;
                    }
                }
                if (counter == 1)
                {
                    candidates.push_back((*i));
                }
            }
            else if ((*i).length() == in.length() + 1 ||
                (*i).length() == in.length() - 1)
            {
                string::size_type inx = 0, ix = 0;
                int counter = 0;
                while (ix <= (*i).size() && inx <= in.size())
                {
                    if ((*i)[ix] == in[inx])
                    {
                        ix++;
                        inx++;
                    }
                    else if (counter == 0)
                    {
                        (*i).length() > in.length() ? ix++ : inx++;
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
            cout << in << ": ";
            for (vector<string>::iterator i = candidates.begin();
                i != candidates.end(); ++i)
            {
                cout << *i << " ";
            }
            cout << endl;
        }
        cin >> in;
    }
}