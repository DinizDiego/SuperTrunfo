#include <stdio.h>

typedef struct {
    char estado[50];
    int codigo;
    char nome[100];
    unsigned long int populacao;
    float area;
    double pib;
    int pontosTuristicos;
    float densidadePopulacional;
    double pibPerCapita;
    float superPoder;
} Carta;

// Função para calcular a densidade populacional
float calcularDensidade(unsigned long int populacao, float area) {
    return populacao / area;
}

// Função para calcular o PIB per capita
double calcularPIBPerCapita(double pib, unsigned long int populacao) {
    return pib / populacao;
}

// Função para calcular o Super Poder
float calcularSuperPoder(Carta c) {
    float inversoDensidade = 1.0f / c.densidadePopulacional;
    return (float)c.populacao + c.area + (float)c.pib + (float)c.pontosTuristicos +
           (float)c.pibPerCapita + inversoDensidade;
}

// Função para ler os dados de uma carta
void lerCarta(Carta *c) {
    printf("\nDigite os dados da carta:\n");

    printf("Estado: ");
    scanf(" %[^\n]", c->estado);

    printf("Código: ");
    scanf("%d", &c->codigo);

    printf("Nome: ");
    scanf(" %[^\n]", c->nome);

    printf("População: ");
    scanf("%lu", &c->populacao);

    printf("Área (km²): ");
    scanf("%f", &c->area);

    printf("PIB (em reais): ");
    scanf("%lf", &c->pib);

    printf("Número de pontos turísticos: ");
    scanf("%d", &c->pontosTuristicos);

    // Cálculos automáticos
    c->densidadePopulacional = calcularDensidade(c->populacao, c->area);
    c->pibPerCapita = calcularPIBPerCapita(c->pib, c->populacao);
    c->superPoder = calcularSuperPoder(*c);
}

// Função para comparar e exibir os resultados
void compararCartas(Carta c1, Carta c2) {
    printf("\nComparação de Cartas:\n");

    printf("População: Carta 1 venceu (%d)\n", c1.populacao > c2.populacao);
    printf("Área: Carta 1 venceu (%d)\n", c1.area > c2.area);
    printf("PIB: Carta 1 venceu (%d)\n", c1.pib > c2.pib);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", c1.pontosTuristicos > c2.pontosTuristicos);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", c1.densidadePopulacional < c2.densidadePopulacional);
    printf("PIB per Capita: Carta 1 venceu (%d)\n", c1.pibPerCapita > c2.pibPerCapita);
    printf("Super Poder: Carta 1 venceu (%d)\n", c1.superPoder > c2.superPoder);
}

int main() {
    Carta carta1, carta2;

    printf("=== Cadastro da Carta 1 ===");
    lerCarta(&carta1);

    printf("\n=== Cadastro da Carta 2 ===");
    lerCarta(&carta2);

    compararCartas(carta1, carta2);

    return 0;
}
