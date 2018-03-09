#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

bool spiel=true;
bool voll[122]={false};
int l=0;

//Kompletter Würfelvorgang (3 mal würfeln und beliebige behalten)
int *wuerfeln(){
    int *wuerfe;
    wuerfe = (int *) malloc(6 * sizeof(int));
    int uebrigWuerfel=0;
    bool ausgabe=true;
    bool behalten[6]={false};
    char auswahlLett [5]= {'a','b','c','d','e'};
//Initialisierung

    for(int durchgang=1; durchgang <= 3 ; durchgang++) {

//Würfeln und Würfe ausgeben
        for (int i = 0; i < 5; i++) {
            if (!behalten[i]) {
                int zahl = (rand() % 6) + 1;
                wuerfe[i] = zahl;
            };
            printf("Würfel %c: %d\n", auswahlLett[i], wuerfe[i]);
        }
        printf("\n\n\n");

//Überprüfen welche Würfel behalten werden
        if (ausgabe==true){

            char choices[5];
            int letters[5] = {0}; //jeder Buchstabe nur einmal array
            if (durchgang == 1)
                printf("Welche Würfel möchtest du behalten?\nSchreibe Buchstaben der Würfel direkt hintereinander\nMöchtest du keinen behalten, schreibe 'k'\n");
            printf("Würfel: ");
            scanf("%s", choices);
            bool reset;
            int lange = strlen(choices);
            int letterToNumber;
            int i = 0;
            while (i != lange) {


                switch (choices[i]) {
                    case 'a':
                        letterToNumber = 0;
                        reset=false;
                        break;

                    case 'b':
                        letterToNumber = 1;
                        reset=false;
                        break;

                    case 'c':
                        letterToNumber = 2;
                        reset=false;
                        break;

                    case 'd':
                        letterToNumber = 3;
                        reset=false;
                        break;

                    case 'e':
                        letterToNumber = 4;
                        reset=false;
                        break;

                    case 'k':
                        letters[5] = 0, 0, 0, 0, 0;
                        reset=true;
                        break;

                    default:
                        break;

                }
                if (reset==true) break;
                if (letters[letterToNumber] < 1) {
                    letters[letterToNumber]++;
                    behalten[letterToNumber] = true;
                }
                i++;
            }
            for (int j = 0; j < 6; j++) {
                if (letters[j] == 0) {
                    behalten[j] = false;
                }
            }
            if (durchgang==2) ausgabe=false;


        }
        printf("\n");
    }
    return wuerfe;
}


int *deklarieren(){
    int *table;
    table = (int *) malloc(123 * sizeof(int));
    for (int i = 99; i <=122 ; ++i) {
        table[i]=NULL;
    }
    return table;
}

int *tabelle(int *table){
    int summeo=table[101]+table[122]+table[100]+table[118]+table[102]+table[115];
    int bonus=0;
    if (summeo>=63) bonus=35;
    int gesamto=summeo+bonus;
    int summeu=table[114]+table[105]+table[104]+table[107]+table[103]+table[121]+table[99];
    int gesamt=gesamto+summeu;
    printf(        "Einser:                    %d\n"
                           "Zweier:                    %d\n"
                           "Dreier:                    %d\n"
                           "Vierer:                    %d\n"
                           "Fünfer:                    %d\n"
                           "Sechser:                   %d\n"
                           "Summe oben:                %d\n"
                           "Bonus oben:                %d\n"
                           "Gesamter oberer Teil:      %d\n\n"
                           "Dreierpasch:               %d\n"                   //tabelle mit punkten ausgeben
                           "Viererpasch:               %d\n"
                           "Full House:                %d\n"
                           "Kleine Straße:             %d\n"
                           "Große Straße:              %d\n"
                           "Kniffel / Yahtzee:         %d\n"
                           "Chance:                    %d\n"
                           "Summe unten:               %d\n\n"
                           "Gesamtsumme                %d\n"
                           "------------------------------\n\n",table[101],table[122],table[100],table[118],table[102],table[115],summeo,bonus,gesamto,table[114],table[105],table[104],table[107],table[103],table[121],table[99],summeu,gesamt);
    return table;
}



int *rechnen(int w[5],int table[123]){          //Berechnen wie oft jede Zahl vorkommt
    int richtig;

    do {
        richtig=1;
        int anzahl[6] = {0};
        unsigned char c = 'a';

        for (int i = 0; i < 5; ++i) {
            anzahl[w[i] - 1]++;
        }


        printf("\nIn welches Feld soll das Ergebnis eingetragen werden? (Buchstabe eingeben)\n\n");
        printf("Einser:             e\n");
        printf("Zweier:             z\n");
        printf("Dreier:             d\n");
        printf("Vierer:             v\n");
        printf("Fünfer:             f\n");
        printf("Sechser:            s\n\n");                                        //man gibt den Buchstaben ein wo man seinen Punkte eintragen will
        printf("Dreierpasch:        r\n");
        printf("Viererpasch:        i\n");
        printf("Full House:         h\n");
        printf("Kleine Straße:      k\n");
        printf("Große Straße:       g\n");
        printf("Kniffel / Yahtzee:  y\n");
        printf("Chance:             c\n-----> ");


        char feld;

        scanf(" %c", &feld);

        int punkte=0;


        switch (feld) {

            case 'e':
                punkte = anzahl[0] * 1;
                break;

            case 'z':
                punkte = anzahl[1] * 2;
                break;

            case 'd':
                punkte = anzahl[2] * 3;                                     //Berechnungen der Punkte je nachdem wo man einträgt
                break;

            case 'v':
                punkte = anzahl[3] * 4;
                break;

            case 'f':
                punkte = anzahl[4] * 5;
                break;

            case 's':
                punkte = anzahl[5] * 6;
                break;

            case 'r':
                if (anzahl[0] >= 3 || anzahl[1] >= 3 || anzahl[2] >= 3 || anzahl[3] >= 3 || anzahl[4] >= 3 || anzahl[5] >= 3)

                    punkte = 1 * anzahl[0] + 2 * anzahl[1] + 3 * anzahl[2] + 4 * anzahl[3] + 5 * anzahl[4] + 6 * anzahl[5];
                break;

            case 'i':
                if (anzahl[0] >= 4 || anzahl[1] >= 4 || anzahl[2] >= 4 || anzahl[3] >= 4 || anzahl[4] >= 4 || anzahl[5] >= 4)

                    punkte = 1 * anzahl[0] + 2 * anzahl[1] + 3 * anzahl[2] + 4 * anzahl[3] + 5 * anzahl[4] + 6 * anzahl[5];

                break;

            case 'h':
                for (int i = 0; i <= 5; ++i) {
                    if (anzahl[i] == 5) {
                        punkte = 25;
                        break;
                    }
                    if (anzahl[i] == 3) {
                        for (int j = 0; j <= 5; ++j) {
                            if (anzahl[j] == 2) {
                                punkte = 25;
                                break;
                            }
                        }
                    }
                }
                break;

            case 'k':
                for (int j = 0; j < 4; ++j) {
                    if (anzahl[j] >= 1 && anzahl[j + 1] >= 1 && anzahl[j + 2] >= 1 & anzahl[j + 3] >= 1) {
                        punkte = 30;
                        break;
                    }
                }
                break;

            case 'g':
                for (int j = 0; j < 5; ++j) {
                    if (anzahl[j] >= 1 && anzahl[j + 1] >= 1 && anzahl[j + 2] >= 1 & anzahl[j + 3] >= 1 &&
                        anzahl[j + 4]) {
                        punkte = 40;
                        break;
                    }
                }
                break;

            case 'y':
                for (int i = 0; i <= 5; ++i) {
                    if (anzahl[i] == 5) {
                        punkte = 50;
                        break;
                    }
                }
                break;

            case 'c':
                punkte = 1 * anzahl[0] + 2 * anzahl[1] + 3 * anzahl[2] + 4 * anzahl[3] + 5 * anzahl[4] + 6 * anzahl[5];
                break;

            default:
                printf("\nFalsche Eingabe bitte einen richtigen Buchstaben eingeben\n\n");
                rechnen(w, table);
                break;
        }


        printf("%d Punkte\n\n", punkte);

        if (voll[feld] == false) {
            table[feld] = punkte;                 //überprüfen ob des ausgewählte feld schon voll ist und Speicherung der Punkte mithilfe der ascii Werte
            voll[feld] = true;
        } else {
            richtig=0;
            printf("\nFeld ist schon voll oder wurde gestrichen\n\n");
        }

    }while(richtig==0);

    return table;
}


void bewertung(int *w, int *table){

        tabelle(rechnen(w, table));


}

bool pruefen(int *table, bool spiel){
    int j=0;
    for (int i = 99; i <=122 ; ++i) {                  //Prüfe ob alle Felder voll sind bzw. ob eins noch leer ist, wenn alle voll sind wird das spiel beendet
        if (voll[i]==true) j++;
    }
    if (j==13)spiel=false;
    else spiel=true;
    return spiel;
}


void spielVorgang(){
    int *table=deklarieren();
    while(spiel==true){
        //TODO: Spielvorgang durchlaufen
        int *w = wuerfeln();

        bewertung(w,table);

        spiel=pruefen(table,spiel);
    }
    printf("fertig");
}



int main() {
    srand(time(NULL));

    spielVorgang();
    return 0;
}