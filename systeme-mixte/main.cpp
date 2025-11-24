#include <iostream>
#include <vector>

using namespace std;

struct glace {
    string nom;
    int nb_siege;
    int note;
};

struct participant {
    string nom;
    string prenom;
    int NoteGlace;
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

int litUnEntier () {
    string uneChaine;
    while (true){
	getline (cin, uneChaine);
        if ((!cin) || (uneChaine.substr(0,2) != "//")) break;
    }
    return stoi(uneChaine);
}

void recup_info(vector<glace> &vGlacePref, vector<participant> &vParticipant)
{
    vector<participant> tmp;
    for (unsigned i (0); i < 105; ++i)
    {
        string nom (litUneString());
        string prenom (litUneString());
        int NoteGlace (litUnEntier());
        tmp.push_back(participant{nom, prenom, NoteGlace});
    }
    vParticipant = tmp;
}
void vote_proportionel(vector<glace> &vGlacePref, vector<participant> &vParticipant)
{
    for (size_t i = 0; i < size(vGlacePref); ++i) {
        vGlacePref[i].note = 0;
    }
    for (size_t i = 0; i < size(vParticipant); ++i) {
        vGlacePref[vParticipant[i].NoteGlace - 1].note += 1;
    }
    for (int i = 0; i < 4; i += 1) {
        int max_quotient = -1;
        int parti_gagnant = -1;

        for (int j = 0; j < size(vGlacePref); j += 1) {
            int quotient = vGlacePref[j].note / (vGlacePref[j].nb_siege + 1);
            if (quotient > max_quotient) {
                max_quotient = quotient;
                parti_gagnant = j;
            }
        }
        vGlacePref[parti_gagnant].nb_siege += 1;
    }
}

void vote_majoritaire(vector<glace> &vGlacePref, vector<participant> &vParticipant)
{
    for (size_t i = 0; i < size(vParticipant); ++i) {
        vGlacePref[vParticipant[i].NoteGlace - 1].note += 1;
    }
    int indexnoteplus = 0;
    int noteplus = 0;
    for (size_t i = 0; i < size(vGlacePref); ++i) {
        if (vGlacePref[i].note > noteplus) {
            noteplus = vGlacePref[i].note;
            indexnoteplus = i;
        }
    }
    vGlacePref[indexnoteplus].nb_siege += 1;  
}

void vote_mixte(vector<glace> &vGlacePref, vector<participant> &vParticipant)
{
    vote_majoritaire(vGlacePref, vParticipant);
    vote_proportionel(vGlacePref, vParticipant);
    for (size_t i = 0; i < size(vGlacePref); ++i) {
        cout << vGlacePref[i].nom << " a obtenu " << vGlacePref[i].nb_siege << " siege" << endl;
    }
}

int main()
{   
    //fonction Inspiré par M casali
    vector<glace> vGlacePref;
    for (unsigned i (0); i < 4; ++i) {
        string nom = litUneString();
        vGlacePref.push_back(glace{nom, 0, 0});
    }
    
    //fonction Inspiré par M casali
    vector<participant> vParticipant;
    for (unsigned i (0); i < 105; ++i) {
        string nom (litUneString());
        string prenom  (litUneString());
        int NoteGlace (litUnEntier());
        vParticipant.push_back(participant{nom, prenom, NoteGlace});
    }
    vote_mixte(vGlacePref, vParticipant);
    return 0;
}
