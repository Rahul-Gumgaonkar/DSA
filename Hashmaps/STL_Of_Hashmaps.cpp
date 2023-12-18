#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{

    // Creation
    unordered_map<string, int> map;

    // Insertion
    pair<string, int> p = make_pair("Rahul", 20);
    map.insert(p);

    pair<string, int> p2("Yash", 21);
    map.insert(p2);

    map["Aman"] = 19;

    // Accessing
    cout << map.at("Rahul") << endl;
    cout << map["Yash"] << endl;

    // Search
    cout << map.count("Rahul") << endl;
    cout << map.count("Prathemesh") << endl;

    if (map.find("Rahul") != map.end())
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    cout << map.size() << endl;
    cout << map["prathemesh"] << endl;
    cout << map.size() << endl;

    cout << "Printing All Entries" << endl;
    for (auto i : map)
    {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}