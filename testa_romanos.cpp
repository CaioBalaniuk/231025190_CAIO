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

    REQUIRE( romanos_para_decimal("MMMCCCLXIII") == 3363);

    REQUIRE( romanos_para_decimal("DCCCXXXIII") == 833);
}

TEST_CASE( "Numeros romanos - algarismos multiplos com subtração válida", "[romanos]") {

    REQUIRE( romanos_para_decimal("IV") == 4);

    REQUIRE( romanos_para_decimal("IX") == 9);

    REQUIRE( romanos_para_decimal("CMXCIX") == 999);

    REQUIRE( romanos_para_decimal("CMXC") == 990);

    REQUIRE( romanos_para_decimal("XL") == 40);

    REQUIRE( romanos_para_decimal("MMMCMXLIX") == 3949);

    REQUIRE( romanos_para_decimal("MMCCCXLVII") == 2347);

    REQUIRE( romanos_para_decimal("CIX") == 109);

    REQUIRE( romanos_para_decimal("CXL") == 140);

    REQUIRE( romanos_para_decimal("LIX") == 59);

    REQUIRE( romanos_para_decimal("XC") == 90);

    REQUIRE( romanos_para_decimal("CD") == 400);

    REQUIRE( romanos_para_decimal("CM") == 900);

}

TEST_CASE( "Numeros romanos - algarismos inválidos", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("G") == -1 );

    REQUIRE( romanos_para_decimal("i") == -1 );

    REQUIRE( romanos_para_decimal("x") == -1);

    REQUIRE( romanos_para_decimal("A") == -1);

    REQUIRE( romanos_para_decimal("O") == -1);

    REQUIRE( romanos_para_decimal("MMCCCXLViII") == -1);

    REQUIRE( romanos_para_decimal("MMMCMXLOX") == -1);

    REQUIRE( romanos_para_decimal("CMXPIX") == -1);
}
TEST_CASE( "Numeros romanos - repetições inválidas", "[romanos]") {

    REQUIRE( romanos_para_decimal("VV") == -1);

    REQUIRE( romanos_para_decimal("IIII") == -1);

    REQUIRE( romanos_para_decimal("VIIII") == -1);

    REQUIRE( romanos_para_decimal("IIIIV") == -1);

    REQUIRE( romanos_para_decimal("XVIIII") == -1);

    REQUIRE( romanos_para_decimal("MMMDD") == -1);

    REQUIRE( romanos_para_decimal("LL") == -1);

    REQUIRE( romanos_para_decimal("XXXX") == -1);

    REQUIRE( romanos_para_decimal("CCCC") == -1);

    REQUIRE( romanos_para_decimal("DD") == -1);
}

TEST_CASE( "Numeros romanos - subtração inválida", "[romanos]") {
    REQUIRE( romanos_para_decimal("VX") == -1);

    REQUIRE( romanos_para_decimal("DM") == -1);

    REQUIRE( romanos_para_decimal("LC") == -1);

    REQUIRE( romanos_para_decimal("IIV") == -1);

    REQUIRE( romanos_para_decimal("IIX") == -1);

    REQUIRE( romanos_para_decimal("IIIX") == -1);

    REQUIRE( romanos_para_decimal("VL") == -1);

    REQUIRE( romanos_para_decimal("VIX") == -1);

    REQUIRE( romanos_para_decimal("XD") == -1);

    REQUIRE( romanos_para_decimal("IM") == -1);

    REQUIRE( romanos_para_decimal("IL") == -1);

    REQUIRE( romanos_para_decimal("IC") == -1);

    REQUIRE( romanos_para_decimal("ID") == -1);

    REQUIRE( romanos_para_decimal("XM") == -1);

    REQUIRE( romanos_para_decimal("MMMIM") == -1);

    REQUIRE( romanos_para_decimal("DID") == -1);

    REQUIRE( romanos_para_decimal("CCIC") == -1);

    REQUIRE( romanos_para_decimal("LIL") == -1);

    REQUIRE( romanos_para_decimal("MMXM") == -1);

    REQUIRE( romanos_para_decimal("MXD") == -1);

    REQUIRE( romanos_para_decimal("MVX") == -1);

    REQUIRE( romanos_para_decimal("MLC") == -1);

    REQUIRE( romanos_para_decimal("MDM") == -1);

    REQUIRE( romanos_para_decimal("XCX") == -1);

    REQUIRE( romanos_para_decimal("XDI") == -1);

    REQUIRE( romanos_para_decimal("ICX") == -1);

    REQUIRE( romanos_para_decimal("VXI") == -1);

    REQUIRE( romanos_para_decimal("CCM") == -1);

    REQUIRE( romanos_para_decimal("LCM") == -1);
}


