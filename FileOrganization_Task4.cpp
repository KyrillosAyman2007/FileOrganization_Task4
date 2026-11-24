#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Person
{
    string name;
    int age;
};

int main()
{
    int n;

    // Part 1: Save persons data in file

    cout << "Enter number of persons: ";
    cin >> n;

    ofstream outFile("persons.txt");

    if (!outFile.is_open())
    {
        cout << "Cannot open file!" << endl;
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        Person p;

        cout << "\nEnter person " << i + 1 << " name: ";
        cin >> ws;
        getline(cin, p.name);

        cout << "Enter person " << i + 1 << " age: ";
        cin >> p.age;

        outFile << p.name << endl;
        outFile << p.age << endl;
    }

    outFile.close();

    // Part 2: Read data into vector

    vector<Person> persons;

    ifstream inFile("persons.txt");

    if (!inFile.is_open())
    {
        cout << "Cannot read file!" << endl;
        return 1;
    }

    Person p;

    while (getline(inFile, p.name))
    {
        if (!(inFile >> p.age))
            break;

        inFile.ignore();

        persons.push_back(p);
    }

    inFile.close();

    // Find youngest and oldest persons

    if (persons.empty())
    {
        cout << "No persons found!" << endl;
        return 1;
    }

    int youngest = persons[0].age;
    int oldest = persons[0].age;

    for (int i = 0; i < persons.size(); i++)
    {
        if (persons[i].age < youngest)
            youngest = persons[i].age;

        if (persons[i].age > oldest)
            oldest = persons[i].age;
    }

    // Save results in results.txt

    ofstream resultFile("results.txt");

    resultFile << "Youngest Person(s):" << endl;

    for (int i = 0; i < persons.size(); i++)
    {
        if (persons[i].age == youngest)
        {
            resultFile << "Name: " << persons[i].name
                << ", Age: " << persons[i].age << endl;
        }
    }

    resultFile << "\nOldest Person(s):" << endl;

    for (int i = 0; i < persons.size(); i++)
    {
        if (persons[i].age == oldest)
        {
            resultFile << "Name: " << persons[i].name
                << ", Age: " << persons[i].age << endl;
        }
    }

    resultFile.close();

    cout << "\nData saved successfully!" << endl;
    cout << "Results saved in results.txt" << endl;

    return 0;
}