#include <iostream>
#include <string>
#include <map>
using namespace std;

string notes[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
map<string, int> notemap;
void solve(string arr[]);
bool root(string arr[]);
void shift(string arr[]);

int main()
{
    for (int i = 0; i < 12; i++)
    {
        notemap[notes[i]] = i;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string arr[4];
        for (int j = 0; j < 4; j++)
        {
            cin >> arr[j];
        }
        if (root(arr))
        {
            cout << "root" << endl;
            
        }
        else
        {
            shift(arr);
            if (root(arr)) {
                cout<<"first"<<endl;
            }
            else {
                shift(arr);
                if (root(arr)) {
                    cout<<"second"<<endl;
                }
                else {
                    shift(arr);
                    if (root(arr)) {
                        cout<<"third"<<endl;
                    }
                    else {
                        cout<<"invalid"<<endl;
                    }
                }
            }
        }
    }
}

void shift(string arr[])
{
    for (int i = 3; i > 0; i--)
    {
        swap(arr[i], arr[i - 1]);
    }
}
bool root(string arr[])
{
    int ix1 = notemap[arr[0]];
    int ix2 = notemap[arr[1]];
    int ix3 = notemap[arr[2]];
    int ix4 = notemap[arr[3]];
    int major, minor, minor2;
    if (ix1 + 4 < 12)
    {
        major = ix1 + 4;
    }
    else
    {
        major = ix1 - 8;
    }
    if (ix2 + 3 < 12)
    {
        minor = ix2 + 3;
    }
    else
    {
        minor = ix2 - 9;
    }
    if (ix3 + 3 < 12)
    {
        minor2 = ix3 + 3;
    }
    else
    {
        minor2 = ix3 - 9;
    }
    if (notes[major] == notes[ix2])
    {
        if (notes[minor] == notes[ix3])
        {
            if (notes[minor2] == notes[ix4])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
