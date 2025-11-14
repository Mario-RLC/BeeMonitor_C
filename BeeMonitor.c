#include <stdio.h>
#include <stdlib.h>
#define MAX_ABELHAS 50 
#define MAX_SENSORES 100 

typedef struct { 
        int id; 
        char tipo[30];       // temperatura, umidade, luminosidade 
        float valor;         // leitura atual
        int idAbelha;        // vínculo com a abelha 
    } Sensor;

    typedef struct { 
        int id; 
        char nomePopular[40]; 
        char nomeCientifico[50]; 
        char regiao[30]; 
        float producaoMel;    // produção média em kg/mês 
    } Abelha; 

int main(){
    Abelha tipo_abelha;
    Sensor tipo_sensor;
    return 0;
}