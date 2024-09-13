#include <stdio.h>

void substituir_paginas(int paginas[], int total_paginas, int molduras) {
    int memoria[molduras];  
    int falhas = 0;     
    int proxima_posicao = 0; 

    for (int i = 0; i < molduras; i++) {
        memoria[i] = -1;
    }

    for (int i = 0; i < total_paginas; i++) {
        int pagina_atual = paginas[i];
        int ja_existe = 0;

        for (int j = 0; j < molduras; j++) {
            if (memoria[j] == pagina_atual) {
                ja_existe = 1;
                break;
            }
        }


        if (!ja_existe) {
            memoria[proxima_posicao] = pagina_atual;
            proxima_posicao = (proxima_posicao + 1) % molduras;  
            falhas++;

            printf("Falha! Página %d inserida: [", pagina_atual);
            for (int j = 0; j < molduras; j++) {
                if (memoria[j] == -1)
                    printf("_");  
                else
                    printf("%d", memoria[j]);

                if (j < molduras - 1)
                    printf(", ");
            }
            printf("]\n");
        }
    }

    printf("Total de falhas: %d\n", falhas);
    printf("Estado final da memória: [");
    for (int i = 0; i < molduras; i++) {
        if (memoria[i] == -1)
            printf("_");
        else
            printf("%d", memoria[i]);

        if (i < molduras - 1)
            printf(", ");
    }
    printf("]\n");
}

int main() {
    int paginas_1[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int molduras_1 = 3;
    int total_paginas_1 = sizeof(paginas_1) / sizeof(paginas_1[0]);

    printf("Exemplo 1:\n");
    substituir_paginas(paginas_1, total_paginas_1, molduras_1);

    int paginas_2[] = {4, 1, 2, 4, 5, 1, 2, 3, 4};
    int molduras_2 = 2;
    int total_paginas_2 = sizeof(paginas_2) / sizeof(paginas_2[0]);

    printf("\nExemplo 2:\n");
    substituir_paginas(paginas_2, total_paginas_2, molduras_2);

    return 0;
}