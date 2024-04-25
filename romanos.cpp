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
    if (checar(num_romano) == true) {
        if (num_romano[0] == 'I') {
            return 1;
        } else if (num_romano[0] == 'V') {
            return 5;
        }
    } else if (checar(num_romano) == false) {
        return -1;
    }
    return 0;
}
