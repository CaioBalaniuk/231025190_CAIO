#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "romanos.hpp"


TEST_CASE( "Numeros romanos - algarismos únicos", "[romanos]" ) {
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
TEST_CASE( "Numeros romanos - algarismos inválidos", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("G") == -1 );

    REQUIRE( romanos_para_decimal("i") == -1 );


}

