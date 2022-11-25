#include <iostream>
using namespace std;

struct nbSudoku
{
    short unsigned int valeur;
    bool nbDefini;
}

void afficherTableau(nbSudoku tab[], unsigned short int TAILLE_TAB, unsigned short int TAILLE_ZONE)
//BUT : Afficher le tableau

int main()
{
    unsigned short int TAILLE_TAB = 9;
    unsigned short int TAILLE_ZONE = 3;
    nbSudoku tabSudoku[TAILLE_TAB][TAILLE_TAB] = [[{5,true},{3,true},{0,false},{0,false},{7,true},{0,false},{0,false},{0,false},{0,false}],
                                [{6,true},{0,false},{0,false},{1,true},{9,true},{5,true},{0,false},{0,false},{0,false}],
                                [{0,false},{9,true},{8,true},{0,false},{0,false},{0,false},{0,false},{6,true},{0,false}],
                                [{8,true},{0,false},{0,false},{0,false},{6,true},{0,false},{0,false},{0,false},{3,true}],
                                [{4,true},{0,false},{0,false},{8,true},{0,false},{3,true},{0,false},{0,false},{1,true}],
                                [{7,true},{0,false},{0,false},{0,false},{2,true},{0,false},{0,false},{0,false},{6,true}],
                                [{0,false},{6,true},{0,false},{0,false},{0,false},{0,false},{2,true},{8,true},{0,false}],
                                [{0,false},{0,false},{0,false},{4,true},{1,true},{9,true},{0,false},{0,false},{5,true}],
                                [{0,false},{0,false},{0,false},{0,false},{8,true},{0,false},{0,false},{7,true},{9,true}]];
    
    afficherTableau(tabSudoku, TAILLE_TAB, TAILLE_ZONE);

    return 0;
}

void afficherTableau(nbSudoku tab[], unsigned short int TAILLE_TAB, unsigned short int TAILLE_ZONE)
{

    
}