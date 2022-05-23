/*
Modelo de Classificação com Naive Bayes para Classificação de Assinatura Digital em C++
*/

//Warning Suppression
#pragma GCC diagnostic push
#pragma GCC diagnotisc ignored "-Wsign-compare"

//Importando bibliotecas
#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <math.h>

//Namespace
using namespace std;
using namespace std::chrono;

//Indice de ínicio dos dados de teste
const int startTest = 900;

//Previsões a serem mostradas
const int numIterations = 5;

//Carregando e abrindo o dataset
int main() {

    // Definindo o nome do arquivo como String
    string fileName = "dados/dataset.csv";

    // Objeto para receber o contéudo do arquivo
    ifstream inputFile;

    // Abrindo o arquivo
    inputFile.open(fileName);

    // Verificando erros
    if(!inputFile.is_open()) {
        cout << "Falha ao abrir o arquivo." << endl;
        return 0;
    }

    // Declarando variáveis para tratar valores (Val)
    // Double pelo ponto flutuante, melhor precisão
    double idVal;
    double tipo_docVal;
    double classeVal;
    double certificado_validoVal;
    double uso_diasVal;

    // Variáveis do tipo vetor para todos os elementos de cada coluna do dataset
    vector<double> id;
    vector<double> tipo_doc;
    vector<double> classe;
    vector<double> certificado_valido;
    vector<double> uso_dias;

    // Variável cabeçalho do arquivo
    string header;

    // Variável célula do csv
    string cell;

    // Recupera cabeçalho para desconsiderar a linha
    getline(inputFile, header);

    // Loop carga e limpeza inicial
    while(inputFile.good()){

        // Leitura da coluna id
        getline(inputFile, cell, ',');

        // Remove aspas
        cell.erase(remove(cell.begin(), cell.end(), '\"'),cell.end());

        // Leitura células com valores
        if(!cell.empty()){

            // Converte id de string para double
            // Ref: https://www.cplusplus.com/reference/string/stod/
            idVal = stod(cell);

            // Append do valor de x no vetor
            // Ref: https://www.cplusplus.com/reference/vector/vector/push_back/
            id.push_back(idVal);

            // Leitura coluna tipo_doc
            getline(inputFile, cell, ',');

            // Converte string para double
            tipo_docVal = stod(cell);

            // Append no vetor
            tipo_doc.push_back(tipo_docVal);

            // Leitura da coluna classe
            getline(inputFile, cell, ',');

            // Converte para double
            classeVal = stod(cell);

            // Append no vetor
            classe.push_back(classeVal);

            // Leitura da coluna certificado_valido
            getline(inputFile, cell, ',');

            // Converte para double
            certificado_validoVal = stod(cell);

            // Append no vetor
            certificado_valido.push_back(certificado_validoVal);

            // Leitura da coluna uso_dias
            getline(inputFile, cell, ',');

            // Converte para double
            uso_diasVal = stod(cell);

            // Append no vetor
            uso_dias.push_back(uso_diasVal);
        }
        else {
            // Caso linha vazia, finaliza o loop
            break;
        }
    }
}
