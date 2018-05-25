//
//  fonctions.cpp
//  mot_mystere
//
//  Created by Michaël on 25/05/2018.
//  Copyright © 2018 Mickahell. All rights reserved.
//

#include "fonctions.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

string mixMot(string motMystere){
    string motRandom("");
    int nbRandom (0);
    nbRandom = rand() % motMystere.size();
    do{
        motRandom += motMystere[nbRandom];
        motMystere.erase(nbRandom, 1);
        if (motMystere.size() == 0) {
            break;
        }
        nbRandom = rand() % motMystere.size();
    }while (motMystere.size() != 0);
    
    return motRandom;
}

void moyenne(vector <double>& scores){
    double moyenneScores = 0;
    for(int i = 0 ; i < scores.size() ; i++){
        moyenneScores += scores[i];
    }
    moyenneScores /= scores.size();
    cout << "Moyenne de score : " << moyenneScores << "/3" << endl;
}
