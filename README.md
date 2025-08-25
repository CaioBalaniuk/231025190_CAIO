# Projeto em C++ e desenvolvimetno orientado a testes

O trabalho consiste em um código que recebe um valor em número romano, e retorna essa valor em número arábico, utilizando a metodologia de desenvolvimento orientado a teste.

São necessários instalados no computador os seguintes ferramentas, gcov, gcvor, cpplint, make, mingw, GCC, valgrind, cppcheck.

O código foi desenvolvido com os seguintes arquivos, romanos.hpp, que foi utilizado para declarar as funções, romanos.cpp, usado para implementar as funções, testa_romanos, para escrever os casos testes, catch.hpp, framkework dos testes.

A fim de rodar o codigo, abra o terminal de comando, navegue até o diretório com os arquivos fonte, use o comando make para inicializar
use o comando make test para ver os resultados dos testes.
use o comando make gcov, seguido de gcovr para visualizar a porcentagem de cobertura dos testes.
use o comando make cpplint para visualizar se o codigo esta seguindo o molde do cpplint
use o comando make valgrind para fazer a verificação dinâmica do codigo.
use o comando make cppcheck para fazer a verificação estática do codigo.
