#include <iostream>
using namespace std;
#include "game-tools.h"
struct nbSudoku
{
    short unsigned int valeur;
    bool nbDefini;
};

void afficherTableau(nbSudoku tabSudoku[9][9], unsigned short int TAILLE_TAB, unsigned short int TAILLE_ZONE);
//BUT : Afficher le tableau

int main()
{
    unsigned short int TAILLE_TAB = 9;
    unsigned short int TAILLE_ZONE = 3;
    nbSudoku tabSudoku[9][9] = {{{5,true},{3,true},{0,false},{0,false},{7,true},{0,false},{0,false},{0,false},{0,false}},
                                {{6,true},{0,false},{0,false},{1,true},{9,true},{5,true},{0,false},{0,false},{0,false}},
                                {{0,false},{9,true},{8,true},{0,false},{0,false},{0,false},{0,false},{6,true},{0,false}},
                                {{8,true},{0,false},{9,false},{0,false},{6,true},{0,false},{0,false},{0,false},{3,true}},
                                {{4,true},{0,false},{0,false},{8,true},{3,false},{3,true},{0,false},{0,false},{1,true}},
                                {{7,true},{0,false},{0,false},{0,false},{2,true},{0,false},{0,false},{0,false},{6,true}},
                                {{0,false},{6,true},{0,false},{0,false},{0,false},{0,false},{2,true},{8,true},{0,false}},
                                {{0,false},{0,false},{0,false},{4,true},{1,true},{9,true},{0,false},{0,false},{5,true}},
                                {{8,false},{0,false},{0,false},{0,false},{8,true},{0,false},{0,false},{7,true},{9,true}}};
    
    afficherTableau(tabSudoku, TAILLE_TAB, TAILLE_ZONE);

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
