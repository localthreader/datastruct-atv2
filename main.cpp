#include <iostream>
#include <string.h>
#include <math.h>

//Disciplina: Estrutura de Dados
//Assunto: Vetores e Estruturas Compostas
//Professor: José Alberto Matioli
//Aluno: Victor Hugo Betoni
//Data: 09/06/2021

using namespace std;

struct Cidade {
    char nome[30];
    int x;
    int y;
};

Cidade cidades[6];
void copyCidade(char* name, int x, int y, int index);

int main() {

    Cidade currentCity;
    Cidade previousCity;

    copyCidade((char*) "Cidade Um", 2, 2, 0);
    copyCidade((char*) "Cidade Dois", 10, 4, 1);
    copyCidade((char*) "Cidade Tres", 19, 8, 2);
    copyCidade((char*) "Cidade Quatro", 16, 15, 3);
    copyCidade((char*) "Cidade Cinco", 5, 19, 4);
    copyCidade((char*) "Cidade Seis", 8, 10, 5);

    float sum = 0.0;
    int times = 0;
    for(int i = 0; i< 7; i++) {
        times++;

        previousCity = currentCity;
        currentCity = i == 6 ? cidades[0] : cidades[i];

        if(times == 1) {
            continue;
        }

        int relativeX = currentCity.x - previousCity.x;
        int relativeY = currentCity.y - previousCity.y;

        float distance = sqrt(pow(relativeX, 2) + pow(relativeY, 2));

        printf("De %s a %s: %.2f\n", previousCity.nome, currentCity.nome, distance);
        sum+=distance;
    }

    printf("\nDistancia total percorrida: %.2f\n", sum);

    return 0;
}

void copyCidade(char* name, int x, int y, int index) {
    strcpy(cidades[index].nome, name);
    cidades[index].x = x;
    cidades[index].y = y;
}
