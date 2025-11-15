#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//chcp 65001 no terminal para virar português

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

void limparBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void pausar(){
    printf("Pressione ENTER para continuar...");
    limparBuffer();
    getchar();
}

void cadastrarAbelha(Abelha tipo_abelha[], int contadorAbelhas){
    for(int i = contadorAbelhas; i <= contadorAbelhas; i++){
        if(contadorAbelhas < MAX_ABELHAS){
            tipo_abelha[i].id = contadorAbelhas;
            printf("Nome Popular: ");
            scanf("%40s", tipo_abelha[i].nomePopular);
            printf("Nome Científico: ");
            scanf("%50s", tipo_abelha[i].nomeCientifico);
            printf("Região: ");
            scanf("%30s", tipo_abelha[i].regiao);
            printf("Produção Média de Mel (kg/mês): ");
            scanf("%f", &tipo_abelha[i].producaoMel);
            system("clear || cls");
            printf("\nAbelha cadastrada com sucesso!\n");
        } else {
            system("clear || cls");
            printf("Limite máximo de abelhas atingido!\n");
        }
    }    
}

void listarAbelhas(Abelha tipo_abelha[], int contadorAbelhas){
    if(contadorAbelhas == 0){
        printf("Nenhuma abelha cadastrada.\n");
        return;
    }
    printf("Lista de Abelhas Cadastradas:\n");
    for(int i = 0; i < contadorAbelhas; i++){
        printf("ID: %d\n", tipo_abelha[i].id);
        printf("Nome Popular: %s\n", tipo_abelha[i].nomePopular);
        printf("Nome Científico: %s\n", tipo_abelha[i].nomeCientifico);
        printf("Região: %s\n", tipo_abelha[i].regiao);
        printf("Produção Média de Mel (kg/mês): %.2f\n", tipo_abelha[i].producaoMel);
        printf("-------------------------\n");
    }
}

void buscarPorNomePopular(Abelha tipo_abelha[], int contadorAbelhas){
    char nomeBusca[40];
    int encontrado = 0;
    printf("Digite o Nome Popular da Abelha para busca: ");
    getchar();
    scanf("%s", nomeBusca);
    for(int i = 0; i < contadorAbelhas; i++){
        if(strcmp(tipo_abelha[i].nomePopular, nomeBusca) == 0){
            printf("Abelha Encontrada:\n");
            printf("ID: %d\n", tipo_abelha[i].id);
            printf("Nome Popular: %s\n", tipo_abelha[i].nomePopular);
            printf("Nome Científico: %s\n", tipo_abelha[i].nomeCientifico);
            printf("Região: %s\n", tipo_abelha[i].regiao);
            printf("Produção Média de Mel (kg/mês): %.2f\n", tipo_abelha[i].producaoMel);
            encontrado = 1;
            break;
        }
    }
    if(encontrado != 1){
        printf("Abelha com o Nome Popular '%s' não encontrada.\n", nomeBusca);
    }
}

int main(){
    system("clear || cls");

    Abelha tipo_abelha[MAX_ABELHAS];
    Sensor tipo_sensor[MAX_SENSORES];
    int contadorAbelhas = 0;
    int contadorSensores = 0;

    int opcao;

    do{
        printf("===== SISTEMA BEE MONITOR =====\n");
        printf("1. Gerenciar Abelhas\n");
        printf("2. Gerenciar Sensores\n");
        printf("3. Relatórios\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        system("clear || cls");

        switch(opcao){
            case 1:
                do{
                    printf("===== SUBMENU 1 - GERENCIAR ABELHAS =====\n");
                    printf("6. Cadastrar Abelha\n");
                    printf("7. Listar Abelhas\n");
                    printf("8. Buscar por Nome Popular\n");
                    printf("9. Alterar Dados\n");
                    printf("10. Remover Abelha\n");
                    printf("11. Voltar ao Menu Principal\n");
                    printf("Escolha uma opção: ");
                    scanf("%d", &opcao);

                    system("clear || cls");

                    switch(opcao){
                        case 6:
                            cadastrarAbelha(tipo_abelha, contadorAbelhas);
                            contadorAbelhas++;
                            getchar();
                            printf("Pressione ENTER para continuar...");
                            getchar();
                            system("clear || cls");
                            break;
                        case 7:
                            listarAbelhas(tipo_abelha, contadorAbelhas);
                            getchar();
                            printf("Pressione ENTER para continuar...");
                            getchar();
                            system("clear || cls");
                            break;
                        case 8:
                            buscarPorNomePopular(tipo_abelha, contadorAbelhas);
                            getchar();
                            printf("Pressione ENTER para continuar...");
                            getchar();
                            system("clear || cls");
                            break;
                        case 9:
                            // Lógica para alterar dados
                            //alterarDadosAbelha(tipo_abelha, contadorAbelhas);
                            break;
                        case 10:
                            // Lógica para remover abelha
                            //removerAbelha(tipo_abelha, &contadorAbelhas);
                            break;
                        case 11:
                            // Voltar ao menu principal
                            break;
                        default:
                            printf("Opção inválida! Tente novamente.\n");        
                    }
                }while(opcao != 11);
                break;    
            case 2:
                do{
                    printf("===== SUBMENU 2 - GERENCIAR SENSORES =====\n");
                    printf("6. Cadastrar Sensor\n");
                    printf("7. Listar Sensores\n");
                    printf("8. Buscar por Tipo de Sensor\n");
                    printf("9. Alterar Dados\n");
                    printf("10. Remover Sensor\n");
                    printf("11. Voltar ao Menu Principal\n");
                    printf("Escolha uma opção: ");
                    scanf("%d", &opcao);

                    system("clear || cls");

                    switch(opcao){
                        case 6:
                            // Lógica para cadastrar sensor
                            //gerenciarSensores(tipo_sensor, contadorSensores);
                            contadorSensores++;
                            break;
                        case 7:
                            // Lógica para listar sensores
                            //listarSensores(tipo_sensor, contadorSensores);
                            break;
                        case 8:
                            // Lógica para buscar por tipo de sensor
                            //buscarPorTipoSensor(tipo_sensor, contadorSensores);
                            break;
                        case 9:
                            // Lógica para alterar dados
                            //alterarDadosSensor(tipo_sensor, contadorSensores);
                            break;
                        case 10:
                            // Lógica para remover sensor
                            //removerSensor(tipo_sensor, &contadorSensores);
                            break;
                        case 11:
                            // Voltar ao menu principal
                            break;
                        default:
                            printf("Opção inválida! Tente novamente.\n");        
                    }
                }while(opcao != 11);
                break;
            case 3:
                do{
                    printf("===== SUBMENU 3 - RELATÓRIOS =====\n");
                    printf("4. Média Geral de Produção de Mel\n");
                    printf("5. Média de Temperatura dos Sensores\n");
                    printf("6. Quantidade de Abelhas por Região\n");
                    printf("7. Voltar ao Menu Principal\n");
                    printf("Escolha uma opção: ");
                    scanf("%d", &opcao);

                    system("clear || cls");

                    switch(opcao){
                        case 4:
                            // Lógica para relatório de produção de mel
                            //relatorioProducaoMel(tipo_abelha, contadorAbelhas);
                            break;
                        case 5:
                            // Lógica para relatório de média de temperatura
                            //relatorioMediaTemperatura(tipo_sensor, contadorSensores);
                            break;
                        case 6:
                            // Lógica para relatório de quantidade de abelhas por região
                            //relatorioQuantidadeAbelhasPorRegiao(tipo_abelha, contadorAbelhas);
                            break;
                        case 7:
                            // Voltar ao menu principal
                            break;
                        default:
                            printf("Opção inválida! Tente novamente.\n");        
                    }
                }while(opcao != 7);
                break;
            case 4:
                printf("SISTEMA ENCERRADO!\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }while(opcao != 4);
    return 0;
}

