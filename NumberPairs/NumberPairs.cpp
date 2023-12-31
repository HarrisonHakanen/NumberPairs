// NumberPairs.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
using std::cout;
using std::cin;


#include <string>
using std::getline;
using std::string;


#include <vector>
using std::vector;


void numberPairs(string numbersStr);


int main()
{
    numberPairs("4 2 3 4 1");
}



void numberPairs(string numbersStr) {

    
    vector <int> numbersInt;
    vector <int> jaPassou;
    vector<int>numerosReais;
    vector<int>quantidades;
    string strNumber = "";
    string texto = "";



    for (int i = 0; i < numbersStr.size(); i++) {

        if (numbersStr[i] != ' ') {
            texto += numbersStr[i];
        }
        else {
            numbersInt.push_back(stoi(texto));
            texto = "";
        }
    }
    if (texto != "") {
        numbersInt.push_back(stoi(texto));
    }


    for (int i = 0; i < numbersInt.size(); i++) {

        bool passou = false;

        for (int j = 0; j < jaPassou.size(); j++) {

            if (numbersInt[i] == jaPassou[j]) {
                passou = true;
            }
        }

        if (!passou) {


            jaPassou.push_back(numbersInt[i]);

            if (i + 1 < numbersInt.size()) {

                numerosReais.push_back(numbersInt[i]);
                int qtdRepeticoes = 1;

                for (int j = i + 1; j < numbersInt.size(); j++) {

                    if (numbersInt[i] == numbersInt[j]) {
                        qtdRepeticoes += 1;
                    }
                }
                quantidades.push_back(qtdRepeticoes);
            }
            else {
                numerosReais.push_back(numbersInt[i]);
                quantidades.push_back(1);
            }
        }
    }


    float qtdPares = 0;
    for (int i = 0; i < quantidades.size(); i++) {


        int discontado = quantidades[i];

        if (discontado != 0) {

            if (discontado % 2 == 0) {

                qtdPares += discontado / 2;
            }
            else {
                discontado -= 1;

                if (discontado != 0) {

                    if (discontado > 2) {
                        qtdPares += discontado / 2;
                    }
                    else {
                        qtdPares += 1;
                    }
                }
            }
        }

    }

    cout << qtdPares;

}