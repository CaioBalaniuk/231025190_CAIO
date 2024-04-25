#include "romanos.hpp"
#include <iostream>
#include <string>
bool checar(std::string n) {
    char apoio[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    bool juri = true;
    int contador = 0;
    for (char i : n) {
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
    int apoio1[] = {1, 5, 10, 50, 100, 500, 1000};
    int resp = -1;
    if (checar(num_romano)==true) {
        for (int i = 0; i < 7; i+=1) {
            if (apoio[i] == num_romano[0]) {
                resp = apoio1[i];
                break;
            }
        }
    }
    return resp;
}
