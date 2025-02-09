#include <stdio.h>
#include <string.h>

// Definindo a estrutura para representar uma carta de cidade
struct CartaCidade {
    char estado[3];               // Estado, com 2 caracteres e o terminador de string '\0'
    char codigo[5];               // Código da carta, 4 caracteres + o terminador
    char cidade[50];              // Nome da cidade
    unsigned long int populacao;  // População da cidade (usando unsigned long int)
    float area;                   // Área da cidade (km²)
    float pib;                    // PIB da cidade (em bilhões)
    int pontosTuristicos;         // Número de pontos turísticos
    float densidadePopulacional;  // Densidade populacional (população / área)
    float pibPerCapita;           // PIB per capita (PIB / população)
    float superPoder;             // Super Poder da carta, que é a soma de todas as propriedades
};

// Função para cadastrar uma carta
void cadastrarCarta(struct CartaCidade* carta) {
    // Solicitar o estado
    printf("Digite o estado (2 caracteres): ");
    scanf(" %2s", carta->estado);  // Ler 2 caracteres para o estado

    // Solicitar o código da carta
    printf("Digite o código da carta (exemplo: A01, B02): \n");
    scanf(" %4s", carta->codigo);  // Ler até 4 caracteres para o código

    // Solicitar o nome da cidade
    printf("Digite o nome da cidade: \n");
    scanf(" %49[^\n]", carta->cidade); // Ler o nome da cidade com espaços

    // Solicitar a população
    printf("Digite a população da cidade: \n");
    scanf("%lu", &carta->populacao);  // Usar unsigned long int para população

    // Solicitar a área da cidade
    printf("Digite a área da cidade (km²): \n");
    scanf("%f", &carta->area);

    // Solicitar o PIB da cidade
    printf("Digite o PIB da cidade (em bilhões): \n");
    scanf("%f", &carta->pib);

    // Solicitar o número de pontos turísticos
    printf("Digite o número de pontos turísticos: \n");
    scanf("%d", &carta->pontosTuristicos);

    // Cálculos das propriedades adicionais
    // Densidade populacional é calculada como população / área
    if (carta->area > 0) {
        carta->densidadePopulacional = carta->populacao / carta->area;
    } else {
        carta->densidadePopulacional = 0;
    }

    // PIB per capita é calculado como PIB / população
    if (carta->populacao > 0) {
        carta->pibPerCapita = carta->pib / carta->populacao;
    } else {
        carta->pibPerCapita = 0;
    }

    // Cálculo do super poder da carta, que é a soma de todas as propriedades
    carta->superPoder = carta->populacao + carta->area + carta->pib + carta->pontosTuristicos +
                        (carta->densidadePopulacional > 0 ? 1.0 / carta->densidadePopulacional : 0) +
                        carta->pibPerCapita;  // Soma das propriedades, com verificação para evitar divisão por zero
}

// Função para comparar duas cartas com base nas propriedades
void compararCartas(struct CartaCidade carta1, struct CartaCidade carta2) {
    printf("\n===== COMPARAÇÃO DE CARTAS =====\n");

    // Comparando as propriedades individuais da primeira carta com a segunda
    printf("\n1. Comparação de População: \n");
    if (carta1.populacao > carta2.populacao)
        printf("Carta 1 vence\n");
    else if (carta1.populacao < carta2.populacao)
        printf("Carta 2 vence\n");
    else
        printf("Empate\n");

    // Comparando as áreas das cidades
    printf("\n2. Comparação de Área: \n");
    if (carta1.area > carta2.area)
        printf("Carta 1 vence\n");
    else if (carta1.area < carta2.area)
        printf("Carta 2 vence\n");
    else
        printf("Empate\n");

    // Comparando o PIB das cidades
    printf("\n3. Comparação de PIB: ");
    if (carta1.pib > carta2.pib)
        printf("Carta 1 vence\n");
    else if (carta1.pib < carta2.pib)
        printf("Carta 2 vence\n");
    else
        printf("Empate\n");

    // Comparando a densidade populacional, onde a carta com menor densidade vence
    printf("\n4. Comparação de Densidade Populacional (menor vence): \n");
    if (carta1.densidadePopulacional < carta2.densidadePopulacional)
        printf("Carta 1 vence\n");
    else if (carta1.densidadePopulacional > carta2.densidadePopulacional)
        printf("Carta 2 vence\n");
    else
        printf("Empate\n");

    // Comparando o PIB per capita das cidades
    printf("\n5. Comparação de PIB per Capita: \n");
    if (carta1.pibPerCapita > carta2.pibPerCapita)
        printf("Carta 1 vence\n");
    else if (carta1.pibPerCapita < carta2.pibPerCapita)
        printf("Carta 2 vence\n");
    else
        printf("Empate\n");

    // Comparando o super poder das cartas, que é a soma das propriedades
    printf("\n6. Comparação de Super Poder: \n");
    if (carta1.superPoder > carta2.superPoder)
        printf("Carta 1 vence\n");
    else if (carta1.superPoder < carta2.superPoder)
        printf("Carta 2 vence\n");
    else
        printf("Empate\n");
}

// Função principal
int main() {
    struct CartaCidade carta1, carta2;  // Declaração de duas cartas

    // Cadastro da primeira carta
    printf("Cadastro da Primeira Carta:\n");
    cadastrarCarta(&carta1);  // Chama a função de cadastro da carta 1

    // Cadastro da segunda carta
    printf("\nCadastro da Segunda Carta:\n");
    cadastrarCarta(&carta2);  // Chama a função de cadastro da carta 2

    // Comparar as duas cartas
    compararCartas(carta1, carta2);  // Chama a função de comparação das cartas

    return 0;  // Fim do programa

}