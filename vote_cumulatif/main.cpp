#include <iostream>
#include <vector>

using namespace std;

struct glace {
    string nom;
    int note;
};

struct participant {
    string nom;
    string prenom;
    vector<int> NoteGlace;
};

//fonction Inspiré par M casali
string litUneString (){
    string uneChaine;
    while (true){
        getline (cin, uneChaine);
        if ((!cin) || (uneChaine.substr(0,2) != "//")) break;
    }
    return uneChaine;
}

//fonction Inspiré par M casali
vector<int> litNote (){
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

string vote_cumulatif(vector<glace> vGlacePref, vector<participant> vParticipant)
{
    string result;
    for (size_t i = 0; i < size(vParticipant) - 1; ++i) {
        for (size_t j = 0; j < size(vParticipant[i].NoteGlace); ++j) {
            vGlacePref[j].note += vParticipant[i].NoteGlace[j];
        }
    }
    int indexnoteplus = 0;
    for (size_t i = 0; i < size(vGlacePref); ++i) {
        int noteplus = vGlacePref[0].note;
        if (vGlacePref[i].note > noteplus) {
            noteplus = vGlacePref[i].note;
            indexnoteplus = i;
        }
    }
    result = vGlacePref[indexnoteplus].nom;
    return result;
}

int main()
{
    //fonction Inspiré par M casali
    vector<glace> vGlacePref;
    for (unsigned i (0); i < 4; ++i) {
        string nom = litUneString();
        vGlacePref.push_back(glace{nom, 0});
    }

    //fonction Inspiré par M casali
    vector<participant> vParticipant;
    for (unsigned i (0); i < 115; ++i){
        string nom (litUneString());
        string prenom  (litUneString());
        vector<int> NoteGlace = litNote();
        vParticipant.push_back(participant{nom, prenom, NoteGlace});
    }
    cout << "c'est la glace " << vote_cumulatif(vGlacePref, vParticipant) << " qui a gagne\n";
    return 0;
}
