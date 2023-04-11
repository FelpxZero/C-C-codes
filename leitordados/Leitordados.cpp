#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// Função para fazer o parse do JSON
void parseJson(const std::string& jsonStr, std::vector<double>& faturamentoDiario) {
    // Neste exemplo, estamos lendo os valores de faturamento diário como números de ponto flutuante
    // de uma string de JSON que segue o formato {"faturamento": [1.2, 3.4, 5.6, ...]}
    // É importante implementar as verificações de erro e validações necessárias para garantir
    // a integridade dos dados de entrada.
    // Exemplo simplificado:
    size_t inicio = jsonStr.find('[');
    size_t fim = jsonStr.find(']');
    std::string valores = jsonStr.substr(inicio + 1, fim - inicio - 1);
    size_t pos = 0;
    while ((pos = valores.find(',')) != std::string::npos) {
        std::string valorStr = valores.substr(0, pos);
        double valor = std::stod(valorStr);
        faturamentoDiario.push_back(valor);
        valores.erase(0, pos + 1);
    }
    double valor = std::stod(valores);
    faturamentoDiario.push_back(valor);
}

int main() {
    // Leitura do arquivo JSON
    std::ifstream file("faturamento.json");
    if (!file.is_open()) {
        std::cout << "Erro ao abrir o arquivo JSON!" << std::endl;
        return 1;
    }
    std::string jsonStr((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    // Leitura dos dados de faturamento diário
    std::vector<double> faturamentoDiario;
    parseJson(jsonStr, faturamentoDiario);

    // Cálculo do menor valor de faturamento
    double menorFaturamento = *min_element(faturamentoDiario.begin(), faturamentoDiario.end());

    // Cálculo do maior valor de faturamento
    double maiorFaturamento = *max_element(faturamentoDiario.begin(), faturamentoDiario.end());

    // Cálculo da média mensal de faturamento
    double somaFaturamento = 0.0;
    for (double valor : faturamentoDiario) {
        somaFaturamento += valor;
    }
    double mediaMensal = somaFaturamento / faturamentoDiario.size();

    // Cálculo do número de dias com faturamento diário superior à média mensal
    int numDiasSuperiorMedia = 0;
    for (double valor : faturamentoDiario) {
        if (valor > mediaMensal) {
            numDiasSuperiorMedia++;
        }
    }

    // Exibição dos resultados
    std::cout << "Menor valor de faturamento: R$" << menorFaturamento << std::endl;
    std::cout << "Maior valor de faturamento: R$" << maiorFaturamento << std::endl;
    std::cout << "Média mensal de faturamento: R$" << mediaMensal << std::endl;
    std::cout << "Número de dias com faturamento diário superior à média mensal: " << numDiasSuperiorMedia << std::endl;

    return 0; 

}