
//Aqui só estou estudando algumas coisas que talvez utilize depois


// ...existing code...
void buscarPorNomePopular(Abelha tipo_abelha[], int contadorAbelhas){
    char nomeBusca[40];
    char nomeBuscaLower[40];
    char nomeLower[40];
    int encontrado = 0;

    printf("Digite o Nome Popular da Abelha para busca: ");
    if (scanf(" %39[^\n]", nomeBusca) != 1) {
        printf("Entrada invalida.\n");
        return;
    }

    /* converte termo de busca para minusculas (seguro quanto a overflow) */
    size_t lenBusca = strlen(nomeBusca);
    size_t i = 0;
    for (; i < sizeof(nomeBuscaLower) - 1 && i < lenBusca; i++) {
        nomeBuscaLower[i] = (char) tolower((unsigned char) nomeBusca[i]);
    }
    nomeBuscaLower[i] = '\0';

    /* percorre abelhas, converte cada nomePopular para minusculas e usa strstr */
    for (int idx = 0; idx < contadorAbelhas; idx++) {
        size_t lenNome = strlen(tipo_abelha[idx].nomePopular);
        size_t j = 0;
        for (; j < sizeof(nomeLower) - 1 && j < lenNome; j++) {
            nomeLower[j] = (char) tolower((unsigned char) tipo_abelha[idx].nomePopular[j]);
        }
        nomeLower[j] = '\0';

        if (strstr(nomeLower, nomeBuscaLower) != NULL) { /* substring case-insensitive */
            printf("Abelha Encontrada:\n");
            printf("ID: %d\n", tipo_abelha[idx].id);
            printf("Nome Popular: %s\n", tipo_abelha[idx].nomePopular);
            printf("Nome Cientifico: %s\n", tipo_abelha[idx].nomeCientifico);
            printf("Regiao: %s\n", tipo_abelha[idx].regiao);
            printf("Producao Media de Mel (kg/mes): %.2f\n", tipo_abelha[idx].producaoMel);
            printf("-------------------------\n");
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Abelha com o Nome Popular '%s' nao encontrada.\n", nomeBusca);
    }
}
// ...existing code...