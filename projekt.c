#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Bohater
{
    int id;
    char imie[100];
    int rasa;
    int klasa;   
    int poziom;
    int reputacja;
    int status;
    struct Bohater* next;
} Bohater;

void Rejestruj();
void Wyszukaj();
void Modyfikuj();
void Sortuj();
void Usun();
void Zapisz();
void Odczytaj();
void Wyswietl(Bohater* bohater);
void WyswietlWszystko();
int Wczytaj(int odN, int doN, char wiadomosc[]);
void Generuj(int n);


const char* rasa[] = {"czlowiek", "elf", "krasnolud", "ork"};
const char* klasa[] = {"wojownik", "mag", "kaplan", "lotrzyk", "lowca", "druid"};
const char* status[] = {"aktywny", "na misji", "ranny", "zagniniony", "zawieszony"};

Bohater* head = NULL;

int iloscB = 0;

int main(){
    int menu;
    
    while (1)
    {
        printf( "\nMenu glowne:\n"
                "1. Rejestruj nowego bohatera\n"
                "2. Wyszukaj bohatera\n"
                "3. Wyswietl wszystkich bohaterow\n");
        if( scanf("%d", &menu) != 1 || menu < 0 || menu > 3) {
            printf("Blad: Wpisz liczbe odpowiadajaca opcji z menu\n");
            while (getchar() != '\n');
            continue;
        }
        switch (menu)
        {
            case 1:
                Rejestruj();
                break;
            case 2:
                Wyszukaj();
                break;
            case 3:
                WyswietlWszystko();
                break;
            case 0:
                Generuj(50);
                break;
        }
    }
    return 0;
}

void Wyswietl(Bohater* bohater){
    printf("\nId:\t\t%d\nImie:\t\t%sRasa:\t\t%s\nKlasa:\t\t%s\nPoziom:\t\t%d\nReputacja:\t%d\nStatus:\t\t%s\n",bohater->id,bohater->imie, rasa[bohater->rasa], klasa[bohater->klasa], bohater->poziom, bohater->reputacja, status[bohater->status]);
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
    bohater->id = iloscB + 1;
    printf("Podaj imie\n");
    fgets(bohater->imie, sizeof(bohater->imie), stdin);
    bohater->rasa = Wczytaj(1, 4, "Podaj rase 1-4   1(czlowiek) 2(elf) 3(krasnolud) 4(ork)\n") - 1;
    bohater->klasa = Wczytaj(1, 6, "Podaj klase 1-6   1(wojownik) 2(mag) 3(kaplan) 4(lotrzyk) 5(lowca) 6(druid)\n") - 1;
    bohater->poziom = Wczytaj(1, 99999, "Podaj poziom\n");
    bohater->reputacja = Wczytaj(0, 100, "Podaj reputacje 0-100\n");
    bohater->status = Wczytaj(1, 5, "Podaj status 1-5   1(aktywny) 2(na misji) 3(ranny) 4(zagniniony) 5(zawieszony)\n") - 1;
    iloscB++;
    if (head == NULL) {
        head = bohater;
        return;
    }
    Bohater* p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = bohater;
    bohater->next = NULL;
}
void Wyszukaj(){
    printf("Wyszukaj na podstawie:\n"
            "1. Imienia\n"
            "2. Poziomu (minimum)\n"
            "3. Id\n");
    int wybor;
    while (scanf("%d", &wybor) != 1)
    {
        while (getchar() != '\n');
        printf("Blad: Wpisz liczbe odpowiadajaca opcji z menu\n");
    }
    
    switch(wybor){
        case 1: {
            char imieSzukane[100];
            printf("Podaj imie (prefiks) do wyszukania:\n");
            getchar();
            fgets(imieSzukane, sizeof(imieSzukane), stdin);

            imieSzukane[strcspn(imieSzukane, "\n")] = '\0';

            Bohater* p = head;
            while (p != NULL) {
                if (strncmp(p->imie, imieSzukane, strlen(imieSzukane)) == 0) {
                    Wyswietl(p);
                }
                p = p->next;
            }
            break;
        }
        case 2:{
            int poziomSzukany;
            printf("Podaj od ktorego poziomu wyszukac\n");
            while (scanf("%d", &poziomSzukany) != 1)
            {
                while (getchar() != '\n');
                printf("Blad: Wpisz liczbe calkowita\n");
            }
            
            Bohater* p;
            p = head;
            while (p != NULL) {
                if(p->poziom >= poziomSzukany){
                    Wyswietl(p);
                }
                p = p->next;
            }
            break;
        }
        case 3:{
            int idSzukane;
            printf("Podaj Id do wyszukania\n");
            while (scanf("%d", &idSzukane) != 1)
            {
                while (getchar() != '\n');
                printf("Blad: Wpisz liczbe calkowita\n");
            }
            
            Bohater* p;
            p = head;
            while (p != NULL) {
                if(p->id == idSzukane){
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
    int wybor;
    printf("Wpisz Id bohatera ktorego dane chcesz edytowac\n");
    scanf("%d", &wybor);
}
void Usun(){
    int wybor;
    printf("Wpisz Id bohatera ktorego chcesz usunac (Ilosc bohaterow: %d)\n", iloscB);
    while(scanf("%d", &wybor) != 1 || wybor > iloscB || wybor < 1){
        while (getchar() != '\n');
        printf("Blad: Wpisz prawidlowe Id\n");
    }

    Bohater* p;
    Bohater* poprzedni = NULL;
    p = head;
    
    while (p != NULL) {
        if(p->id == wybor){
           
        }
        poprzedni = p;
        p = p->next;
    }
}
void Generuj(int n){
    char* imiona[] = {"Aragorn\n", "Legolas\n", "Gimli\n", "Frodo\n", "Gandalf\n", "Boromir\n", "Samwise\n", "Pippin\n", "Merry\n", "Elrond\n"};
    for(int i = 0; i < n; i++){
        Bohater* bohater = calloc(1, sizeof(Bohater));
        bohater->id = iloscB + 1;
        strcpy(bohater->imie, imiona[rand() % 10]);
        bohater->rasa = rand() % 4;
        bohater->klasa = rand() % 6;
        bohater->poziom = rand() % 101;
        bohater->reputacja = rand() % 101;
        bohater->status = rand() % 5;
        iloscB++;
        if (head == NULL) {
            head = bohater;
            continue;
        }
        Bohater* p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = bohater;
        bohater->next = NULL;
    }
}
