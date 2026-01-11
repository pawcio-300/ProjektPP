#include <stdio.h>
#include <string.h>

void Rejestruj();
void Wyszukaj();
void Modyfikuj();
void Sortuj();
void Usun();
void Zapisz();
void Odczytaj();
void Wyswietl(int index);
int Wczytaj(int odN, int doN, char wiadomosc[]);


const char* rasa[] = {"czlowiek", "elf", "krasnolud", "ork"};
const char* klasa[] = {"wojownik", "mag", "kaplan", "lotrzyk", "lowca", "druid"};
const char* status[] = {"aktywny", "na misji", "ranny", "zagniniony", "zawieszony"};

struct Bohater
{
    char imie[100];
    int rasa;
    int klasa;   
    int poziom;
    int reputacja;
    int status;
};

struct Bohater bohaterowie[1000];
int iloscB = 0;

int main(){
    int menu;
    while (1)
    {
        printf("Menu glowne:\n"
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
                Wyswietl(0);
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
void Wyswietl(int index){
    printf("\nImie: %sRasa: %s\nKlasa: %s\nPoziom: %d\nReputacja: %d\nStatus: %s\n",bohaterowie[index].imie, rasa[bohaterowie[index].rasa], klasa[bohaterowie[index].klasa], bohaterowie[index].poziom, bohaterowie[index].reputacja, status[bohaterowie[index].status]);
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
//dodać opisy liczb
void Rejestruj(){
    while (getchar() != '\n');
    struct Bohater bohater;
    printf("Podaj imie\n");
    fgets(bohater.imie, sizeof(bohater.imie), stdin);
    bohater.rasa = Wczytaj(1, 4, "Podaj rase 1-4\n") - 1;
    bohater.klasa = Wczytaj(1, 6, "Podaj klase 1-6\n") - 1;
    bohater.poziom = Wczytaj(1, 10000, "Podaj poziom\n");
    bohater.reputacja = Wczytaj(0, 100, "Podaj reputacje 0-100\n");
    bohater.status = Wczytaj(1, 5, "Podaj status 1-5\n") - 1;
    bohaterowie[iloscB] = bohater;
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
            for(int i=0; i < iloscB; i++){
                if(strcmp(bohaterowie[i].imie, imieSzukane) == 0){
                    Wyswietl(i);
                }
            }
            break;
        }
        case 2:{
            int poziomSzukany;
            printf("Podaj poziom do wyszukania\n");
            scanf("%d", &poziomSzukany);
            for(int i=0; i < iloscB; i++){
                if(bohaterowie[i].poziom == poziomSzukany){
                    Wyswietl(i);
                }
            }
            break;
        }
        default:
            printf("Nieprawidlowy wybor\n");
    }
}
void Modyfikuj(){
    
}