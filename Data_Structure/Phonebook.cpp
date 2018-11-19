#include <iostream>
#include <string>
#include <map>

using namespace std;


void findRecord( map<string,string> &Phonebook)
{
string phone;
cin>>phone;
map<string, string>::iterator it;
it = Phonebook.find(phone);
    
    if(it != Phonebook.end())
        cout<<it->second<<endl;

else cout<<"not found"<<endl;

}

void deleteRecord(map<string,string> &Phonebook)
{
string phone;
cin >> phone;
map<string, string>::iterator it;
it = Phonebook.find(phone);

if(it != Phonebook.end())
    {
        Phonebook.erase(it);
    }   
}

void insertRecord( map<string,string> &Phonebook)
{
string phone, name;
map<string, string>::iterator it;
cin>>phone>>name;
it = Phonebook.find(phone);

    if(it == Phonebook.end())
        Phonebook.insert(pair<string,string>(phone,name));

    else it->second = name;

}
int main()
{
    int iPair;
    cin>>iPair;
    map<string, string> Phonebook;
    string operation;
    
    for(int i=0; i<iPair;++i)
    {
        cin>> operation;

        if(operation == "add")
            insertRecord(Phonebook);

        if(operation == "del")
            deleteRecord(Phonebook);

        if(operation == "find")
            findRecord(Phonebook);
        
    }

    return 0;
}