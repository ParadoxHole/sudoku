#include <iostream>
using namespace std;
#include "game-tools.h"

struct nbSudoku
{
    short unsigned int valeur;
    bool nbDefini;
};
enum issueDeLaSaisie {compatible, incompatible, abandon, erreureDeSaisie};


void afficherTableau(const nbSudoku tabSudoku[9][9], unsigned short int TAILLE_TAB, unsigned short int TAILLE_ZONE);
//BUT : Afficher le tableau du sudoku

void saisiVerifJoueur(const nbSudoku tabSudoku[9][9], unsigned short int &indiceLigne, unsigned short int &indiceCollone,
                      unsigned short int &valeurSaisie, issueDeLaSaisie &issueDeLaSaisie, bool &valModifie, 
                      unsigned short int TAILLE_TAB, unsigned short int TAILLE_ZONE);
//BUT : Vérifier si la valeur saisie par le joueur est compatible ou non avec la grille


bool tabPlein(const nbSudoku tabSudoku[9][9], unsigned short int TAILLE_TAB);
//BUT : Vérifier si le tableau est plein

bool verifValeur(const nbSudoku tabSudoku[9][9], unsigned short int indiceLigne, unsigned short int indiceCollone,
                 unsigned short int valeur, unsigned short int TAILLE_TAB, unsigned short int TAILLE_ZONE);
//BUT : Vérifier si la valeur est compatible ou non avec la grille

int main()
{
    unsigned short int erreurAutorise;
    unsigned short int nbErreurJoueur;
    unsigned short int TAILLE_TAB;
    unsigned short int TAILLE_ZONE;
    unsigned short int nbTour;
    bool valModifie;
    issueDeLaSaisie issueDeLaSaisie;

    unsigned short int indiceLigne;
    unsigned short int indiceCollone;
    unsigned short int valeurSaisie;

    //calvier >> initialiserLaPartie >> tabSudoku, erreurAutorise, nbTour, TAILLE_TAB, TAILLE_ZONE --------------------------
    
    //calvier >> saisieVerifErreurAutorisees >>  erreurAutorise
    while(true){
        cout << "Veuilliez saisir le nombre maximum d'erreur que vous vous autorisées";
        cin >> erreurAutorise;
        if(erreurAutorise >= 3){
            break;
        }
        cout << "Vous devez choisir une valeur supérieur ou égale à 3";
    }
    // ... >> Initialiser le tableau avec toutes ses valeurs >> tabSudoku
    nbSudoku tabSudoku[9][9] = {{{5,true},{3,true},{0,false},{0,false},{7,true},{0,false},{0,false},{0,false},{0,false}},
                                {{6,true},{0,false},{0,false},{1,true},{9,true},{5,true},{0,false},{0,false},{0,false}},
                                {{0,false},{9,true},{8,true},{0,false},{0,false},{0,false},{0,false},{6,true},{0,false}},
                                {{8,true},{0,false},{0,false},{0,false},{6,true},{0,false},{0,false},{0,false},{3,true}},
                                {{4,true},{0,false},{0,false},{8,true},{0,false},{3,true},{0,false},{0,false},{1,true}},
                                {{7,true},{0,false},{0,false},{0,false},{2,true},{0,false},{0,false},{0,false},{6,true}},
                                {{0,false},{6,true},{0,false},{0,false},{0,false},{0,false},{2,true},{8,true},{0,false}},
                                {{0,false},{0,false},{0,false},{4,true},{1,true},{9,true},{0,false},{0,false},{5,true}},
                                {{0,false},{0,false},{0,false},{0,false},{8,true},{0,false},{0,false},{7,true},{9,true}}};
    // ... >> Initialiser les variables de Tailles >> TAILLE_TAB, TAILLE_ZONE
    TAILLE_TAB = 9;
    TAILLE_ZONE = 3;
    // ... >> initialiserNbTour >> nbtour
    nbTour = 1;
    nbErreurJoueur = 0;

    //tabSudoku, erreurAutorise nbTour, TAILLE_TAB, TAILLE_ZONE >> jouerLaPartie >> issueDeLaSaisie -------------------------
    while(true){
        //tabSudoku, TAILLE_TAB, TAILLE_ZONE >> afficherTableau >> écran                          
        afficherTableau(tabSudoku, TAILLE_TAB, TAILLE_ZONE);

        //nbTour, erreurAutorise, nbErreurJoueur >> afficherResultat >> écran
        cout << "Tour " << nbTour << nbErreurJoueur << "/" << erreurAutorise << endl;

        //tabSudoku >> SaisieVerifJoueur >> issueDeLaSaisie, [valModifie]
        saisiVerifJoueur(tabSudoku, indiceLigne, indiceCollone, valeurSaisie, issueDeLaSaisie, valModifie, TAILLE_TAB, TAILLE_ZONE);
        
        //nbErreurJoueur, erreurAutorise, nbTour, issueDeLaSaisie, valModifie, tabSudoku, valeurSaisie >> jouerLaPartie >> écran
        switch(issueDeLaSaisie)
        {
            case compatible:
                //tabSudoku, indiceLigne, indiceCollone, valeurSaisie, valModifie >> traiterValeurCompatible >> tabSudoku
                cout << "OUI !";
                if (valModifie)
                {
                    cout << "valeur" << tabSudoku[indiceLigne][indiceCollone].valeur << "modifie en" << valeurSaisie << endl;
                }
                // tabSudoku >> verifierVictoire >> bool
                if (tabPlein(tabSudoku, TAILLE_TAB))
                {
                    cout << "Bravo ! ! !";
                    return 0;
                }
                //indiceLigne, indiceCollone, valeurSaisie >> majTableau >> tabSudoku
                tabSudoku[indiceLigne][indiceCollone].valeur = valeurSaisie;
                break;
            case incompatible:
                //nbErreurJoueur >> traiterValeurIncompatible >> nbErreurJoueur
                cout << "ERREUR #";
                if (tabSudoku[indiceLigne][indiceCollone].nbDefini){
                    cout << "Saisie sur la grille de départ #";
                } else {
                    cout << "Valeur compatible";
                }
                
                break;
            case abandon:
                /**/
                break;
            case erreureDeSaisie:
                /**/
                break;
        };

        cout << "Appuyer sur une touche pour continuer... " << endl;
    }
    return 0;
}

void afficherTableau(nbSudoku tabSudoku[9][9],unsigned short int TAILLE_TAB, unsigned short int TAILLE_ZONE)
{

    for (unsigned short int i = 0; i < TAILLE_TAB ; i++)
    {
        if (i % TAILLE_ZONE == 0)
        {
            cout << "  " ;
            if (i == 0)
            {
                cout << " ";
            }
        }
        cout << " " << i+1;
    }
    
    cout << endl;

    for (unsigned short int indiceLigne = 0; indiceLigne < TAILLE_TAB; indiceLigne++)
    {
        if (indiceLigne % TAILLE_ZONE == 0)
        {
                cout << "  -------------------------" << endl;
        }

        cout << indiceLigne+1 << " ";

        for (unsigned short int indiceColonne = 0; indiceColonne < TAILLE_TAB; indiceColonne++)
        {
            if (indiceColonne % TAILLE_ZONE == 0)
            {
                cout << "| ";
            }
            if (tabSudoku[indiceLigne][indiceColonne].valeur == 0) // Si la valeur est nulle mettre un point
            {
                cout << ".";
            }
            else
            {
                if (tabSudoku[indiceLigne][indiceColonne].nbDefini == true)
                {
                    afficherNombreEnCouleur(tabSudoku[indiceLigne][indiceColonne].valeur, rouge, false);
                }
                else
                {
                    afficherNombreEnCouleur(tabSudoku[indiceLigne][indiceColonne].valeur, bleu, false);
                }
                
            }
            
            cout << " ";
        }

        cout << "| " << indiceLigne+1 << endl;
    } 
    cout << "  -------------------------" << endl;

    for (unsigned short int i = 0; i < TAILLE_TAB ; i++)
    {
        if (i % TAILLE_ZONE == 0)
        {
            cout << "  " ;
            if (i == 0)
            {
                cout << " ";
            }
        }
        cout << " " << i+1;
    }
}

bool verifValeur(const nbSudoku tabSudoku[9][9], unsigned short int indiceLigne, unsigned short int indiceCollone,
                 unsigned short int valeur, unsigned short int TAILLE_TAB, unsigned short int TAILLE_ZONE){

    // indiceLigne, tabSudoku, valeur, TAILLE_TAB >> verification Horizontale >> bool
    for(unsigned short int i = 0; i < TAILLE_TAB; i++){
        if (tabSudoku[indiceLigne][i].valeur == valeur){
            return false;
        }
    }

    // indiceCollone, tabSudoku, valeur, TAILLE_TAB >> verification Verticale >> bool
    for(unsigned short int i = 0; i < TAILLE_TAB; i++){
        if (tabSudoku[i][indiceCollone].valeur == valeur){
            return false;
        }
    }

    // indiceLigne, indiceCollone, tabSudoku, valeur, TAILLE_TAB, TAILLE_ZONE >> verification Zone >> bool

        // indiceLigne, indiceCollone, TAILLE_ZONE >> calculerCoinGaucheZone >> indiceLigneZone, indiceColonneZone
    indiceLigne = (cdecl((indiceLigne/TAILLE_ZONE))-1)*TAILLE_ZONE;
    indiceCollone = (cdecl((indiceCollone/TAILLE_ZONE))-1)*TAILLE_ZONE;

        // indiceLigne, indiceColonne, tabSudoku, valeur, TAILLE_ZONE >> verification Zone >> bool
    for(unsigned short int i = indiceLigne; i < indiceLigne+TAILLE_ZONE - 1; i++){
        for(unsigned short int j = indiceCollone; j < indiceCollone+TAILLE_ZONE - 1; j++){
            if (tabSudoku[i][j].valeur == valeur){
                return false;
            }
        }
    }

    return true;
}

void saisiVerifJoueur(const nbSudoku tabSudoku[9][9], unsigned short int &indiceLigne, unsigned short int &indiceCollone,
                      unsigned short int &valeurSaisie, issueDeLaSaisie &issueDeLaSaisie, bool &valModifie, 
                      unsigned short int TAILLE_TAB, unsigned short int TAILLE_ZONE){

    // clavier >> saisieUtilisateur >> indiceLigne, indiceCollone, valeurSaisie
    cout << "Proposition (cf. x y i) ? ";
    cin >> indiceLigne >> indiceCollone >> valeurSaisie;

    // ... >> intialisation >> issueDeLaSaisie, valModifie
    issueDeLaSaisie = compatible;
    valModifie = false;

    // indiceLigne, indiceCollone, valeurSaisie >> traiterCasSpeciaux >> [issueDeLaSaisie]
    if(indiceLigne == 0 || indiceCollone == 0 || valeurSaisie == 0){
        issueDeLaSaisie = abandon;
    }
    else if((isalpha(indiceLigne) || isalpha(indiceCollone) || isalpha(valeurSaisie)) || (indiceLigne > TAILLE_TAB || indiceCollone > TAILLE_TAB || valeurSaisie > 9) || (indiceLigne < 1 || indiceCollone < 1 || valeurSaisie < 1)){
        issueDeLaSaisie = erreureDeSaisie;
    }

    // indiceLigne, indiceCollone, valeurSaisie, tabSudoku, issueDeLaSaisie >> verifValeur >> [valModifie], [issueDeLaSaisie]
    if(tabSudoku[indiceLigne][indiceCollone].nbDefini == true){
        issueDeLaSaisie = incompatible;
    }
    else if(tabSudoku[indiceLigne][indiceCollone].valeur != 0){
        valModifie = true;
    }

    // indiceLigne, indiceCollone, valeurSaisie, tabSudoku, issueDeLaSaisie >> verifValeur >> issueDeLaSaisie
    if (issueDeLaSaisie == compatible){
        if(verifValeur(tabSudoku, indiceLigne, indiceCollone, valeurSaisie, TAILLE_TAB, TAILLE_ZONE) == false){
           issueDeLaSaisie = incompatible;
        }
    }    
}

bool tabPlein(nbSudoku tabSudoku[9][9],unsigned short int TAILLE_TAB)
{
    for (unsigned short int indiceLigne = 0; indiceLigne < TAILLE_TAB; indiceLigne++)
    {
        for (unsigned short int indiceColonne = 0; indiceColonne < TAILLE_TAB; indiceColonne++)
        {
            if (tabSudoku[indiceLigne][indiceColonne].valeur == 0)
            {
                return false;
            }
        }
    }
    return true;
}