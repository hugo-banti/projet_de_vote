#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*Partie du code pris dans sur le fichier main.cpp de Casali */
string litUneString (){
    string uneChaine;
    while (true){
        getline (cin, uneChaine);
        if ((!cin) || (uneChaine.substr(0,2) != "//")) break;
    }
    return uneChaine;
}

int litUnEntier (){
    string uneChaine;
    while (true){
        getline (cin, uneChaine);
        if ((!cin) || (uneChaine.substr(0,2) != "//")) break;
    }
    return stoi(uneChaine);
}

struct participant {
    string nom;
    string prenom;
    int glacePref;
};

bool compare2part (const participant & p1, const participant & p2){
    return p1.prenom < p2.prenom;
}

void affichVectString (const vector<string> & v){
    for (const string & val : v)
        cout << val << '\t';
    cout << endl;
}

void affichVectParticipants (const vector<participant> & vPart){
    for (const participant & part : vPart){
        cout << part.nom << endl;
        cout << part.prenom << endl;
        cout << part.glacePref << endl;
    }
}


string vote_majoritaire (vector<string> vGlacePref, vector<participant> vParticipant ){
    //Il faut avoir le nombre de participants
    int nbParticipant = vParticipant.size();
    //On définie la majorité absolue
    int majorAbsolue = nbParticipant / 2 ; 
    
    //Préparation du premier tour
    for (size_t i = 0; i < nbParticipant; i = i + 1)
    {
        
    }
    

}

int main(){

    vector <string> vGlacePref;
    for (unsigned i (0); i < 4; ++i)
        vGlacePref.push_back(litUneString());

    vector<participant> vParticipant;

    for (unsigned i (0); i < 10; ++i){
        string nom (litUneString());
        string prenom  (litUneString());
        int numGlace (litUnEntier());
        //cout << nom << endl << prenom << endl << numGlace << endl;
        vParticipant.push_back(participant{nom, prenom, numGlace});
              //  vJoueur[numEquipe-1].push_back(joueur {nom, prenom, numEquipe});
    }

    affichVectParticipants(vParticipant);
    cout << string (15, '-') << endl;
    sort(vParticipant.begin(), vParticipant.end(), compare2part);
    affichVectParticipants(vParticipant);

    cout << "c'est la glace " << vote_majoritaire(vGlacePref, vParticipant) << " qui a gagne\n";
    return 0;
}