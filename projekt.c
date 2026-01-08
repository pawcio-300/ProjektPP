#include <stdio.h>

void Rejestruj();
void Wyszukaj();
void Modyfikuj();
void Sortuj();
void Usun();
void Zapisz();
void Odczytaj();

//dodać tablice
enum Rasa{czlowiek, elf, krasnolud, ork};
enum Klasa{wojownik, mag, kaplan, lotrzyk, lowca, druid};
enum Status{aktywny, na_misji, ranny, zagniniony, zawieszony};

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
    Rejestruj();    
    puts(bohaterowie[0].imie);
    printf("%d\n%d\n%d\n%d\n%d\n", bohaterowie[0].rasa, bohaterowie[0].klasa, bohaterowie[0].poziom, bohaterowie[0].reputacja, bohaterowie[0].status);
    
    return 0;
}

void Rejestruj(){
    struct Bohater bohater;
    printf("Podaj imie\n");
    fgets(bohater.imie, sizeof(bohater.imie), stdin);
    printf("Podaj rase 1-4\n");
    scanf("%d", &bohater.rasa);
    printf("Podaj klase 1-6\n");
    scanf("%d", &bohater.klasa);
    printf("Podaj poziom\n");
    scanf("%d", &bohater.poziom);
    printf("Podaj reputacja 0-100\n");
    scanf("%d", &bohater.reputacja);
    printf("Podaj status 1-5\n");
    scanf("%d", &bohater.status);
    bohaterowie[iloscB] = bohater;
    iloscB++;
}