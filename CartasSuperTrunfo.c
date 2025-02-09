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
    printf("Digite o estado: ");
    scanf(" %2s", carta->estado);  // Ler 2 caracteres para o estado

    // Solicitar o código da carta
    printf("Digite o código da carta (exemplo: A01, B02): ");
    scanf(" %4s", carta->codigo);  // Ler até 4 caracteres para o código

    // Solicitar o nome da cidade
    printf("Digite o nome da cidade: ");
    scanf(" %49[^\n]", carta->cidade); // Ler o nome da cidade com espaços

    // Solicitar a população
    printf("Digite a população da cidade: ");
    scanf("%lu", &carta->populacao);  // Usar unsigned long int para população

    // Solicitar a área da cidade
    printf("Digite a área da cidade (km²): ");
    scanf("%f", &carta->area);

    // Solicitar o PIB da cidade
    printf("Digite o PIB da cidade (em bilhões): ");
    scanf("%f", &carta->pib);

    // Solicitar o número de pontos turísticos
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", 
