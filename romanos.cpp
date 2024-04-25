#include "romanos.hpp"
#include <iostream>
#include <string>
bool checar(std::string n) {
    char apoio[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    bool juri = true;
    for (char i : n) {
        int contador = 0;
        for (char u : apoio) {
            if (u == i) {
                break;
            }
            contador += 1;
        }
        if (contador == 7) {
            juri = false;
            break;
        }
    }
    return juri;
}
int romanos_para_decimal(std::string num_romano) {
    char apoio[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    long apoio1[] = {1, 5, 10, 50, 100, 500, 1000};
    long resp = 0;
    long tam = num_romano.length();
    if (checar(num_romano) == true) {
        for (int u = 0; u < tam; u += 1) {
            for (int i = 0; i < 7; i += 1) {
                if (apoio[i] == num_romano[u]) {
                    resp += apoio1[i];
                    break;
                }
            }
        }
    } else {
        resp = -1;
    }
    return resp;
}


