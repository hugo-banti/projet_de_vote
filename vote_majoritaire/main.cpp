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
    int glacePref;
};

//void recup_info(vector<glace> &vGlacePref, vector<participant> &vParticipant);
void recup_info_participant(vector<participant>& vParticipant);

//Fonctions pris dans le code de Mr.Casali
string litUneString (){
    string uneChaine;
    while (true){
        getline (cin, uneChaine);
        if (!cin) break;
        if (uneChaine.size() < 2 || uneChaine.substr(0, 2) != "//") break;
        //if ((!cin) || (uneChaine.substr(0,2) != "//")) break;
    }
    return uneChaine;
}

int litUnEntier (){
    string uneChaine;
    while (true){
        getline (cin, uneChaine);
        if (!cin) break;
        if (uneChaine.size() < 2 || uneChaine.substr(0, 2) != "//") break;
        //if ((!cin) || (uneChaine.substr(0,2) != "//")) break;
    }

    try {
        return stoi(uneChaine);
    } catch (...) {
        return -1;
    }
}

//On récupere les infos des participant avec leurs notes
void recup_info_participant(vector<participant> &vParticipant)
{
    vParticipant.clear();
    for (int i = 0; i < 105; ++i) {
        string nom (litUneString());
        string prenom  (litUneString());
        int glacePref (litUnEntier());
        vParticipant.push_back(participant{nom, prenom, glacePref});
    }
}



string vote_majoritaire( vector<glace>& vGlacePref, vector<participant>& vParticipant)
{
    //Il faut avoir le nombre de participants
    int nbParticipants = vParticipant.size();
    //On définie la majorité absolue
    int majoriteAbsolue = nbParticipants / 2 + 1;

    /* -Préparation du premier tour- */
    //On initialise le nombre de vote à 0
    for (auto& g : vGlacePref) g.note = 0;

    //On compte les votes des participants
    for (int i = 0; i < nbParticipants; ++i) {
        vGlacePref[vParticipant[i].glacePref - 1].note += 1;
    }



    //On vérifie la majorité absolue
    for (size_t i = 0; i < size(vGlacePref); ++i) {
        if (vGlacePref[i].note >= majoriteAbsolue) {
            return vGlacePref[i].nom;
        }
    }

    //Si résultat n'atteint pas la majorité absolue on cherche les finalistes


    /* -Préparation du second tour- */
    //On initialise le nombre de vote à 0
    for (auto& g : vGlacePref) g.note = 0;

    //On récupère les infos des finalistes puis on recompte les notes
    recup_info_participant(vParticipant);
    for (int i = 0; i < nbParticipants; ++i) {
        vGlacePref[vParticipant[i].glacePref - 1].note += 1;
    }

    int indexnoteplus = 0;
    int noteplus = 0;
    for (size_t i = 0; i < size(vGlacePref); ++i) {
        if (vGlacePref[i].note > noteplus) {
            noteplus = vGlacePref[i].note;
            indexnoteplus = i;
        }
    }
    return vGlacePref[indexnoteplus].nom;

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
    for (unsigned i (0); i < 105; ++i){
        string nom (litUneString());
        string prenom  (litUneString());
        int glacePref = litUnEntier();
        vParticipant.push_back(participant{nom, prenom, glacePref});
    }
    cout << "C'est la glace " << vote_majoritaire(vGlacePref, vParticipant) << " qui a gagné .\n";
    return 0;
}
