#include "romanos.hpp"
#include <iostream>
#include <string>
bool checar(std::string n) {
    char apoio[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    bool juri = true;
    char anterior1 = 0;
    char atual1 = 0;
    int cont = 0;
    for (char i : n) {
        int contador = 0;
        for (char u : apoio) {
            if (u == i) {
                atual1 = u;
                break;
            }
            contador += 1;
        }
        if (atual1 == anterior1) {
            cont +=1;
        } else {
            cont=1;
        }
        if (contador == 7) {
            juri = false;
            break;
        }
        if (cont > 3 && (anterior1=='I'||anterior1=='X'||anterior1=='C'||anterior1=='M')) {
            juri=false;
            break;
        } else if (cont > 1 && (anterior1=='V'||anterior1=='L'||anterior1=='D')) {
            juri=false;
            break;
        }
        anterior1=atual1;
    }
    return juri;
}
int romanos_para_decimal(std::string num_romano) {
    char apoio[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    long apoio1[] = {1, 5, 10, 50, 100, 500, 1000};
    long resp = 0;
    long tam = num_romano.length();
    int atual = 0;
    int anterior = 0;
    bool juri = true;
    if (checar(num_romano) == true) {
        for (int u = (tam-1); u >= 0; u -= 1) {
            for (int i = 0; i < 7; i += 1) {
                if (apoio[i] == num_romano[u]) {
                    atual = apoio1[i];
                    break;
                }
            }
            if (atual < anterior) {
                 if (anterior - atual == atual) {
                    juri=false;
                    break;
                } else {
                    resp -= atual;
                }
            } else {
                resp+=atual;
            }
            anterior = atual;
        }
    } else {
        resp = -1;
    }
    if (juri==true) {
        return resp;
    } else {
        return -1;
    }

}


