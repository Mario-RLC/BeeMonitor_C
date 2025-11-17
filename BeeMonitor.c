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

//Funções para Limpar e Pausar o buffer de entrada

void limparBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void pausar(){
    printf("Pressione ENTER para continuar...");
    limparBuffer();
    getchar();
}

//Funções para Abelhas

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

void alterarDadosAbelha(Abelha tipo_abelha[], int contadorAbelhas){
    int idBusca;
    int encontrado = 0;
    printf("Digite o ID da Abelha para alterar dados: ");
    scanf("%d", &idBusca);
    for(int i = 0; i < contadorAbelhas; i++){
        if(tipo_abelha[i].id == idBusca){
            printf("Alterando dados da Abelha ID %d:\n", idBusca);
            printf("Novo Nome Popular: ");
            scanf("%40s", tipo_abelha[i].nomePopular);
            printf("Novo Nome Científico: ");
            scanf("%50s", tipo_abelha[i].nomeCientifico);
            printf("Nova Região: ");
            scanf("%30s", tipo_abelha[i].regiao);
            printf("Nova Produção Média de Mel (kg/mês): ");
            scanf("%f", &tipo_abelha[i].producaoMel);
            system("clear || cls");
            printf("\nDados da Abelha atualizados com sucesso!\n");
            encontrado = 1;
            break;
        }
    }
    if(encontrado != 1){
        printf("Abelha com o ID '%d' não encontrada.\n", idBusca);
    }
}

int removerAbelha(Abelha tipo_abelha[], int contadorAbelhas){
    int idBusca;
    int encontrado = 0;
    printf("Digite o ID da Abelha para remover: ");
    scanf("%d", &idBusca);
    for(int i = 0; i < contadorAbelhas; i++){
        if(tipo_abelha[i].id == idBusca){
            for(int j = i; j < contadorAbelhas - 1; j++){
                tipo_abelha[j] = tipo_abelha[j + 1];
            }
            contadorAbelhas--;
            for(int k = 0; k < contadorAbelhas; k++){
                tipo_abelha[k].id = k;
            }
            system("clear || cls");
            printf("\nAbelha removida com sucesso!\n");
            encontrado = 1;
            break;
        }
    }
    if(encontrado != 1){
        printf("Abelha com o ID '%d' não encontrada.\n", idBusca);
    }
    return contadorAbelhas;
}

//Funções para Sensores

int cadastrarSensores(Sensor tipo_sensor[], int contadorSensores, Abelha tipo_abelha[], int contadorAbelhas){
    if(contadorAbelhas == 0){
        printf("Nenhuma abelha disponível para associar. Cadastre uma abelha primeiro.\n");
        return contadorSensores;
    }
    if(contadorSensores >= MAX_SENSORES){
        printf("Limite máximo de sensores atingido!\n");
        return contadorSensores;
    }

    int idAbelhaBusca;
    int encontrado = 0;
    printf("Digite o ID da Abelha para associar ao sensor: ");
    scanf("%d", &idAbelhaBusca);
    for(int i = 0; i < contadorAbelhas; i++){
        if(tipo_abelha[i].id == idAbelhaBusca){
            encontrado = 1;
            break;
        }
    }
    if(encontrado == 0){
        printf("Abelha com o ID '%d' não encontrada. Não foi possível cadastrar o sensor.\n", idAbelhaBusca);
        return contadorSensores;
    }

    tipo_sensor[contadorSensores].id = contadorSensores;
    printf("Tipo do Sensor: ");
    scanf("%30s", tipo_sensor[contadorSensores].tipo);
    printf("Valor inicial: ");
    scanf("%f", &tipo_sensor[contadorSensores].valor);
    tipo_sensor[contadorSensores].idAbelha = idAbelhaBusca;
    system("clear || cls");
    printf("\nSensor cadastrado com sucesso!\n");

    return contadorSensores + 1;
}

void listarSensores(Sensor tipo_sensor[], int contadorSensores){
    if(contadorSensores == 0){
        printf("Nenhum sensor cadastrado.\n");
        return;
    }
    printf("Lista de Sensores Cadastrados:\n");
    for(int i = 0; i < contadorSensores; i++){
        printf("ID: %d\n", tipo_sensor[i].id);
        printf("Tipo do Sensor: %s\n", tipo_sensor[i].tipo);
        printf("Valor Atual: %.2f\n", tipo_sensor[i].valor);
        printf("ID da Abelha Associada: %d\n", tipo_sensor[i].idAbelha);
        printf("-------------------------\n");
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
                            printf("Pressione ENTER para continuar...");
                            pausar();
                            system("clear || cls");
                            break;
                        case 7:
                            listarAbelhas(tipo_abelha, contadorAbelhas);
                            printf("Pressione ENTER para continuar...");
                            pausar();
                            system("clear || cls");
                            break;
                        case 8:
                            buscarPorNomePopular(tipo_abelha, contadorAbelhas);
                            printf("Pressione ENTER para continuar...");
                            pausar();
                            system("clear || cls");
                            break;
                        case 9:
                            alterarDadosAbelha(tipo_abelha, contadorAbelhas);
                            printf("Pressione ENTER para continuar...");
                            pausar();
                            system("clear || cls");
                            break;
                        case 10:
                            contadorAbelhas = removerAbelha(tipo_abelha, contadorAbelhas);
                            printf("Pressione ENTER para continuar...");
                            pausar();
                            system("clear || cls");
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
                    printf("8. Buscar por ID da Abelha\n");
                    printf("9. Alterar leitura\n");
                    printf("10. Remover Sensor\n");
                    printf("11. Voltar ao Menu Principal\n");
                    printf("Escolha uma opção: ");
                    scanf("%d", &opcao);

                    system("clear || cls");

                    switch(opcao){
                        case 6:
                            contadorSensores = cadastrarSensores(tipo_sensor, contadorSensores, tipo_abelha, contadorAbelhas);
                            printf("Pressione ENTER para continuar...");
                            pausar();
                            system("clear || cls");
                            break;
                        case 7:
                            listarSensores(tipo_sensor, contadorSensores);
                            printf("Pressione ENTER para continuar...");
                            pausar();
                            system("clear || cls");
                            break;
                        case 8:
                            // Lógica para buscar sensor por tipo de id da Abelha
                            //buscarPorIdAbelha(tipo_sensor, contadorSensores);
                            printf("Pressione ENTER para continuar...");
                            pausar();
                            system("clear || cls");
                            break;
                        case 9:
                            // Lógica para alterar dados
                            //alterarDadosSensor(tipo_sensor, contadorSensores);
                            printf("Pressione ENTER para continuar...");
                            pausar();
                            system("clear || cls");
                            break;
                        case 10:
                            // Lógica para remover sensor
                            //removerSensor(tipo_sensor, &contadorSensores);
                            printf("Pressione ENTER para continuar...");
                            pausar();
                            system("clear || cls");
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

