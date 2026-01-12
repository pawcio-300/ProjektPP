#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Rejestruj();
void Wyszukaj();
void Modyfikuj();
void Sortuj();
void Usun();
void Zapisz();
void Odczytaj();
void Wyswietl();
void WyswietlWszystko();
int Wczytaj(int odN, int doN, char wiadomosc[]);


const char* rasa[] = {"czlowiek", "elf", "krasnolud", "ork"};
const char* klasa[] = {"wojownik", "mag", "kaplan", "lotrzyk", "lowca", "druid"};
const char* status[] = {"aktywny", "na misji", "ranny", "zagniniony", "zawieszony"};

typedef struct Bohater
{
    char imie[100];
    int rasa;
    int klasa;   
    int poziom;
    int reputacja;
    int status;
    struct Bohater* next;
} Bohater;
Bohater* head = NULL;

int iloscB = 0;

int main(){
    int menu;
    while (1)
    {
        printf("\nMenu glowne:\n"
               "1. Rejestruj nowego bohatera\n"
               "2. Wyszukaj bohatera\n");
        if( scanf("%d", &menu) != 1 || menu < 1 || menu > 2) {
            printf("Blad: Wpisz liczbe odpowiadajaca opcji z menu\n");
            while (getchar() != '\n');
            continue;
        }
        switch (menu)
        {
            case 1:
                Rejestruj();
                WyswietlWszystko();
                break;
            case 2:
                Wyszukaj();
                break;
        }
    }
    
    // Rejestruj();    
    // Wyswietl(0);
    // Wyszukaj();
    return 0;
}

void Wyswietl(Bohater* bohater){
    printf("\nImie: %sRasa: %s\nKlasa: %s\nPoziom: %d\nReputacja: %d\nStatus: %s\n",bohater->imie, rasa[bohater->rasa], klasa[bohater->klasa], bohater->poziom, bohater->reputacja, status[bohater->status]);
}
void WyswietlWszystko(){
    Bohater* p;
    p = head;
    while (p != NULL) {
        Wyswietl(p);
        p = p->next;
    }
}
int Wczytaj(int odN, int doN, char wiadomosc[]){
    int liczba;
    while(1){
        printf("%s", wiadomosc);
        if(scanf("%d", &liczba) != 1) {
            printf("Blad: podaj liczbe calkowita!\n");
            while (getchar() != '\n');
            continue;
        }
        if (liczba < odN || liczba > doN) {
            printf("Blad: podaj liczbe z podanego zakresu!\n");
        }
        else {
            return liczba;
        }
    }
}
void Rejestruj(){
    while (getchar() != '\n');
    Bohater* bohater = calloc(1, sizeof(Bohater));
    printf("Podaj imie\n");
    fgets(bohater->imie, sizeof(bohater->imie), stdin);
    bohater->rasa = Wczytaj(1, 4, "Podaj rase 1-4   1(czlowiek) 2(elf) 3(krasnolud) 4(ork)\n") - 1;
    bohater->klasa = Wczytaj(1, 6, "Podaj klase 1-6   1(wojownik) 2(mag) 3(kaplan) 4(lotrzyk) 5(lowca) 6(druid)\n") - 1;
    bohater->poziom = Wczytaj(1, 99999, "Podaj poziom\n");
    bohater->reputacja = Wczytaj(0, 100, "Podaj reputacje 0-100\n");
    bohater->status = Wczytaj(1, 5, "Podaj status 1-5   1(aktywny) 2(na misji) 3(ranny) 4(zagniniony) 5(zawieszony)\n") - 1;
    bohater->next = head;
    head = bohater;
    iloscB++;
}
void Wyszukaj(){
    printf("Wyszukaj na podstawie:\n"
            "1. Imienia\n"
            "2. Poziomu\n");
    int wybor;
    scanf("%d", &wybor);
    switch(wybor){
        case 1:{
            char imieSzukane[100];
            printf("Podaj imie do wyszukania\n");
            getchar();
            fgets(imieSzukane, sizeof(imieSzukane), stdin);
            
            Bohater* p;
            p = head;
            while (p != NULL) {
                if(strcmp(p->imie, imieSzukane) == 0){
                    Wyswietl(p);
                }
                p = p->next;
            }
            break;
        }
        case 2:{
            int poziomSzukany;
            printf("Podaj poziom do wyszukania\n");
            scanf("%d", &poziomSzukany);
            
            Bohater* p;
            p = head;
            while (p != NULL) {
                if(p->poziom == poziomSzukany){
                    Wyswietl(p);
                }
                p = p->next;
            }
            break;
        }
        default:
            printf("Nieprawidlowy wybor\n");
    }
}
void Modyfikuj(){
    
}
