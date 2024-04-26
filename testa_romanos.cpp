#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "romanos.hpp"


TEST_CASE( "Numeros romanos - algarismos �nicos", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("I") == 1 );

    REQUIRE( romanos_para_decimal("V") == 5 );

    REQUIRE( romanos_para_decimal("X") == 10);

    REQUIRE( romanos_para_decimal("L") == 50);

    REQUIRE( romanos_para_decimal("C") == 100);

    REQUIRE( romanos_para_decimal("D") == 500);

    REQUIRE( romanos_para_decimal("M") == 1000);
}
TEST_CASE( "Numeros romanos - algarismos multiplos", "[romanos]") {
    REQUIRE( romanos_para_decimal("III") == 3 );

    REQUIRE( romanos_para_decimal("II") == 2);

    REQUIRE( romanos_para_decimal("XX") == 20);

    REQUIRE( romanos_para_decimal("XV") == 15);

    REQUIRE( romanos_para_decimal("CL") == 150);

    REQUIRE( romanos_para_decimal("MD") == 1500);

    REQUIRE( romanos_para_decimal("MDCLXIII") == 1663);
}

TEST_CASE( "Numeros romanos - algarismos multiplos com subtra��o v�lida", "[romanos]") {

    REQUIRE( romanos_para_decimal("IV") == 4);

    REQUIRE( romanos_para_decimal("IX") == 9);

    REQUIRE( romanos_para_decimal("CMXCIX") == 999);

    REQUIRE( romanos_para_decimal("CMXC") == 990);

    REQUIRE( romanos_para_decimal("CMXC") == 990);

    REQUIRE( romanos_para_decimal("XL") == 40);
}

TEST_CASE( "Numeros romanos - algarismos inv�lidos", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("G") == -1 );

    REQUIRE( romanos_para_decimal("i") == -1 );

    REQUIRE( romanos_para_decimal("x") == -1);

    REQUIRE( romanos_para_decimal("A") == -1);

    REQUIRE( romanos_para_decimal("O") == -1);
}
TEST_CASE( "Numeros romanos - repeti��es inv�lidas", "[romanos]") {

    REQUIRE( romanos_para_decimal("VV") == -1);

    REQUIRE( romanos_para_decimal("IIII") == -1);

    REQUIRE( romanos_para_decimal("VIIII") == -1);

    REQUIRE( romanos_para_decimal("IIIIV") == -1);

    REQUIRE( romanos_para_decimal("XVIIII") == -1);
}

TEST_CASE( "Numeros romanos - subtra��o inv�lida", "[romanos]") {
    REQUIRE( romanos_para_decimal("VX") == -1);

    REQUIRE( romanos_para_decimal("DM") == -1);

    REQUIRE( romanos_para_decimal("LC") == -1);
}


