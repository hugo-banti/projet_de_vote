#include <vector>
#include <iostream>

using namespace std;

struct glace 
{
    string nom;
    int note;
};

struct participant 
{
    string nom;
    string prenom;
    vector<int> NoteGlace;
};

//fonction Inspiré par M casali
string litUneString ()
{
    string uneChaine;
    while (true){
        getline (cin, uneChaine);
        if ((!cin) || (uneChaine.substr(0,2) != "//")) break;
    }
    return uneChaine;
}

//fonction Inspiré par M casali
vector<int> litNote ()
{
    vector<int> Note;
    for (int i = 0; i < 4; ++i) {
        string uneChaine;
        while (true){
            getline (cin, uneChaine);
            if ((!cin) || (uneChaine.substr(0,2) != "//")) break;
        }
        Note.push_back(stoi(uneChaine));
    }
    return Note;
}


int main()
{

}