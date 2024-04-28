#include "romanos.hpp"
#include <iostream>
#include <string>

int valor_num(char num) {
    int numa;
    char apoio[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int apoio1[] = {1, 5, 10, 50, 100, 500, 1000};
    for (int i = 0; i < 7; i += 1) {
        if (apoio[i] == num) {
            numa = apoio1[i];
            break;
        }
    }
    return numa;
}

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
            cont += 1;
        } else {
            cont = 1;
        }
        if (contador == 7) {
            juri = false;
            break;
        }
        if (cont > 3) {
            if (anterior1 == 'I' || anterior1 == 'X') {
                juri = false;
                break;
            }
            if (anterior1 == 'C' || anterior1 == 'M') {
                juri = false;
                break;
            }
        } else if (cont > 1) {
            if (anterior1 == 'V' || anterior1 == 'L' || anterior1 == 'D') {
                juri = false;
                break;
            }
        }
        anterior1 = atual1;
    }
    return juri;
}


int romanos_para_decimal(std::string num_romano) {
    int resp = 0;
    int tam = num_romano.length();
    int atual = 0;
    int anterior = 0;
    bool juri = true;
    if (checar(num_romano) == true) {
        for (int u = (tam-1); u >= 0; u -= 1) {
            atual = valor_num(num_romano[u]);
            if (atual < anterior) {
                if (tam >= 3 && u != 0) {
                    if (valor_num(num_romano[u-1]) > valor_num(num_romano[u])) {
                        int m = valor_num(num_romano[u-1]);
                        int m1 = valor_num(num_romano[u+1]);
                        if (m >= m1) {
                            if (atual == 10) {
                                if (anterior == 1000 || anterior == 500) {
                                    juri = false;
                                    break;
                                }
                            }
                            if (atual == 1) {
                                if (anterior == 1000 || anterior == 500) {
                                    juri = false;
                                    break;
                                }
                                if (anterior == 100 || anterior == 50) {
                                    juri = false;
                                    break;
                                }
                            }
                            if ((anterior - atual == atual) || atual == 5) {
                                juri = false;
                                break;
                            }
                            if (atual == 50 || atual == 500) {
                                juri = false;
                                break;
                            } else {
                                resp -= atual;
                            }
                        } else {
                            juri = false;
                            break;
                        }
                     } else {
                        juri = false;
                        break;
                    }
                } else if (tam < 3) {
                    if (atual == 10 && (anterior == 1000 || anterior == 500)) {
                        juri = false;
                        break;
                    }
                    if (atual == 1) {
                        if (anterior == 1000 || anterior == 500) {
                            juri = false;
                            break;
                        }
                        if (anterior == 100 || anterior == 50) {
                            juri = false;
                            break;
                        }
                    }
                    if ((anterior - atual == atual) || atual == 5) {
                        juri = false;
                        break;
                    }
                    if (atual == 50 || atual == 500) {
                        juri = false;
                        break;
                    } else {
                        resp -= atual;
                    }
                } else if (tam >= 3 && u == 0) {
                    int m2 = valor_num(num_romano[u]);
                    int m3 = valor_num(num_romano[u+2]);
                    if (m2 <= m3) {
                        juri = false;
                        break;
                    }
                    if (atual == 10 && (anterior == 1000 || anterior == 500)) {
                        juri = false;
                        break;
                    }
                    if ((anterior - atual == atual) || atual == 5) {
                        juri = false;
                        break;
                    }
                    if (atual == 50 || atual == 500) {
                        juri = false;
                        break;
                    } else {
                        resp -= atual;
                    }
                }
            } else {
                resp+=atual;
            }
            anterior = atual;
        }
    } else {
        resp = -1;
    }
    if (juri == true) {
        return resp;
    } else {
        return -1;
    }
}

