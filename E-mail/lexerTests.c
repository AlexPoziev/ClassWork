#include "lexerTests.h"
#include "lexer.h"

bool falseTests(void) {
    bool firstTest = !isEmailAddress("");
    bool secondTest = !isEmailAddress(" ");
    bool thirdTest = !isEmailAddress("@");
    bool fourthTest = !isEmailAddress(".");
    bool fifthTest = !isEmailAddress(".R");
    bool sixthTest = !isEmailAddress("@R");
    bool seventhTest = !isEmailAddress("R");
    bool eighthTest = !isEmailAddress("123@123.AB");
    bool ninthTest = !isEmailAddress("123@123.r");
    bool tenthTest = !isEmailAddress("r@123.A");
    bool eleventhTest = !isEmailAddress("r@123.ABC123.AAA");
    bool twelfthTest = !isEmailAddress("123@123.%.AAA");
    bool thirteenthTest = !isEmailAddress("123@@123.A");
    bool fourteenthTest = !isEmailAddress("123@123.1");

    return firstTest && secondTest && thirdTest && fourthTest && fifthTest
            && sixthTest && seventhTest && eighthTest && ninthTest && tenthTest
            && eleventhTest && twelfthTest && thirteenthTest && fourteenthTest;
}

bool trueTests(void) {
    bool firstTest = isEmailAddress("%@-.R");
    bool secondTest = isEmailAddress("A123-Z0_@A1-.R");
    bool thirdTest = isEmailAddress("UNCLEBOB@GMAIL.C");
    bool fourthTest = isEmailAddress("ST107206@STUDENTS.1.SPBU.R");

    return firstTest && secondTest && thirdTest && fourthTest;
}

bool lexerTest(void) {
    return trueTests() && falseTests();
}