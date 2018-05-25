//
//  main.cpp
//  mot_mystere
//
//  Created by Michaël on 25/05/2018.
//  Copyright © 2018 Mickahell. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <cstdlib>
#include "fonctions.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    string motMystere("Bob"), motFinal(""), continuer("o"), partieSolo(""), motMelange(""), motSecret("");
    vector<double> scores;
    
    
    srand(time(0));
    
    do{
        do{
            cout << "Joues-tu tout seul ? (o/n) : ";
            cin >> partieSolo;
        }while (partieSolo != "o" && partieSolo != "n");
        
        //1
        if(partieSolo == "o"){
            int i = 0, ligne = 0;
            string const dico("dico.txt");
            ifstream fluxLire(dico.c_str()); //ouvrir le fichier en lecture
            
            if(fluxLire){
                while(getline(fluxLire, motMystere)){
                    i++;
                }
                ligne = rand() % i;
                i = 1;
                fluxLire.close(); //Forcer la fermeture pour pallier au bug du curseur
                
                string const dico("dico.txt");
                ifstream fluxLire(dico.c_str()); //ouvrir le fichier en lecture
                while (getline(fluxLire, motMystere)){
                    if (i == ligne) {
                        break;
                    }
                    i++;
                }
            }
        }
        else{
            cout << "Entre le mot à deviner : ";
            cin >> motMystere;
            cout << " " << endl;
            int t = 0;
            do{
                cout << " " << endl;
                t++;
            }while(t != 50);
        }
        motFinal = motMystere;
        motMelange = mixMot(motMystere); //2
        
        //3
        string devine("");
        int compteur = 3;
        do{
            cout << "Quel est ce mot " << motMelange << " : " << endl;
            cin >> devine;
            
            if(devine == motFinal){
                cout << "Bravo tu as trouvé le mot !" << endl;
                break;
            }
            else{
                compteur--;
                cout << "Et non, ce n'est pas ca... Nombre de coups : " << compteur << endl;
                if(compteur == 0){
                    cout << "Perdu, le mot était : " << motFinal << endl;
                    cout << " " << endl;
                    break;
                }
                cout << " " << endl;
            }
        }while (devine != motFinal || compteur == 0);
        do{
            cout << "Veux tu rejouer ? (o/n) : ";
            cin >> continuer;
        }while(continuer != "o" && continuer != "n");
        
        scores.push_back(compteur);
        
    }while (continuer == "o");
    
    moyenne(scores);
    
    
    return 0;
}
