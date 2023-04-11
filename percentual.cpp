#include <stdio.h>

int main() {

    float sp = 67836.43;
    float rj = 36678.66;
    float mg = 29229.88;
    float es = 27165.48;
    float outros = 19849.53;
        float Total = sp + rj + mg + es + outros;
            float pSP = (sp / Total) * 100;
            float pRJ = (rj / Total) * 100;
            float pMG = (mg / Total) * 100;
            float pES = (es / Total) * 100;
            float pOutros = (outros / Total) * 100;
     
    printf("Percentual de representação por estado:\n");
    printf("SP: %.2f%%\n", pSP);
    printf("RJ: %.2f%%\n", pRJ);
    printf("MG: %.2f%%\n", pMG);
    printf("ES: %.2f%%\n", pES);
    printf("Outros: %.2f%%\n", pOutros);

    return 0;
}
