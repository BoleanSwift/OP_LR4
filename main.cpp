#include<Windows.h>
#include "UserInterface.h"


int main() {
    SetConsoleOutputCP(CP_UTF8);
    UserInterface myInterface{};
    myInterface.makeMenu();
    return 0;
}