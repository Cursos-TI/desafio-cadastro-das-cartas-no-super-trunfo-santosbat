#include <stdio.h>

typedef struct {
    char estado[30];
    char codigo[5];
    char nome[50];
    unsigned long int populacao; // agora suporta números maiores
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
    float superPoder;
} Carta;

void calcularIndicadores(Carta *c) {
    // densidade populacional
    c->densidadePopulacional = c->populacao / c->area;

    // PIB per capita
    c->pibPerCapita = c->pib / c->populacao;

    // Super Poder = soma de todos atributos numéricos relevantes
    // incluindo o inverso da densidade
    c->superPoder = (float)c->populacao
                  + c->area
                  + c->pib
                  + c->pontosTuristicos
                  + c->pibPerCapita
                  + (1.0f / c->densidadePopulacional);
}

int main() {
    Carta c1, c2;

    printf("Digite os dados da Carta 1:\n");
    printf("Estado: ");
    scanf(" %[^\n]", c1.estado);
    printf("Codigo: ");
    scanf(" %s", c1.codigo);
    printf("Nome: ");
    scanf(" %[^\n]", c1.nome);
    printf("Populacao: ");
    scanf("%lu", &c1.populacao);
    printf("Area: ");
    scanf("%f", &c1.area);
    printf("PIB: ");
    scanf("%f", &c1.pib);
    printf("Numero de pontos turisticos: ");
    scanf("%d", &c1.pontosTuristicos);

    printf("\nDigite os dados da Carta 2:\n");
    printf("Estado: ");
    scanf(" %[^\n]", c2.estado);
    printf("Codigo: ");
    scanf(" %s", c2.codigo);
    printf("Nome: ");
    scanf(" %[^\n]", c2.nome);
    printf("Populacao: ");
    scanf("%lu", &c2.populacao);
    printf("Area: ");
    scanf("%f", &c2.area);
    printf("PIB: ");
    scanf("%f", &c2.pib);
    printf("Numero de pontos turisticos: ");
    scanf("%d", &c2.pontosTuristicos);

    // calcular indicadores derivados
    calcularIndicadores(&c1);
    calcularIndicadores(&c2);

    printf("\nComparacao de Cartas:\n");

    // Comparações: 1 = Carta 1 venceu, 0 = Carta 2 venceu
    printf("Populacao: Carta %d venceu (%d)\n",
           (c1.populacao > c2.populacao) ? 1 : 2,
           (c1.populacao > c2.populacao) ? 1 : 0);

    printf("Area: Carta %d venceu (%d)\n",
           (c1.area > c2.area) ? 1 : 2,
           (c1.area > c2.area) ? 1 : 0);

    printf("PIB: Carta %d venceu (%d)\n",
           (c1.pib > c2.pib) ? 1 : 2,
           (c1.pib > c2.pib) ? 1 : 0);

    printf("Pontos Turisticos: Carta %d venceu (%d)\n",
           (c1.pontosTuristicos > c2.pontosTuristicos) ? 1 : 2,
           (c1.pontosTuristicos > c2.pontosTuristicos) ? 1 : 0);

    // regra especial: menor densidade vence
    printf("Densidade Populacional: Carta %d venceu (%d)\n",
           (c1.densidadePopulacional < c2.densidadePopulacional) ? 1 : 2,
           (c1.densidadePopulacional < c2.densidadePopulacional) ? 1 : 0);

    printf("PIB per Capita: Carta %d venceu (%d)\n",
           (c1.pibPerCapita > c2.pibPerCapita) ? 1 : 2,
           (c1.pibPerCapita > c2.pibPerCapita) ? 1 : 0);

    printf("Super Poder: Carta %d venceu (%d)\n",
           (c1.superPoder > c2.superPoder) ? 1 : 2,
           (c1.superPoder > c2.superPoder) ? 1 : 0);

    return 0;
}
