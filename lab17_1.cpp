#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename,vector<string> &names,vector<int> &scores,vector<char> &grades)
{

    ifstream source;
    string text;
    source.open(filename);
    while (getline(source,text))
    {
        char format[] = "%[^:]: %d %d %d";
        char name[100];
        int a,b,c;
        sscanf(text.c_str(),format,name,&a,&b,&c);
        int score=a+b+c;
        names.push_back(name); 
        scores.push_back(score);
        grades.push_back(score2grade(score));

    } 
}


void getCommand(string &command,string &key)
{
    cout<<"Please input your command: ";
    getline(cin,command);
    char format[] ="%s %[^\n]";
    char text_1[100];
    char text_2[100];
    sscanf(command.c_str(),format,text_1,text_2);
    command=text_1;
    key=text_2;
}

void searchName(vector<string> names,vector<int> scores,vector<char> grades,string key)
{
    bool found = 0;
    cout<<"---------------------------------"<<"\n";
    
    for(unsigned int i = 0;i<names.size();i++)
    {
          
        if(toUpperStr(names[i]) ==key)
        {
            found = 1;
            cout<<names[i]<<"'s "<<"score "<<"= "<<scores[i]<<"\n";
            cout<<names[i]<<"'s "<<"grade "<<"= "<<grades[i]<<"\n";
        }
        
    }
    if (found == 0)
    {
            cout<<"Cannot found.\n"; 

    }
    
    cout<<"---------------------------------"<<"\n";
    
}

void searchGrade(vector<string> names,vector<int> scores,vector<char> grades,string key)
{
     bool found = 0;
    cout<<"---------------------------------"<<"\n";
    for(unsigned int i = 0; i<names.size();i++)
    {
        if(grades[i]==key[0])
        {
            found = 1;
            cout<<names[i]<<" "<<"("<<scores[i]<<")"<<"\n";
        }
    }
        if (found == 0)
    {
            cout<<"Cannot found.\n"; 

    }
    cout<<"---------------------------------"<<"\n";
}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}