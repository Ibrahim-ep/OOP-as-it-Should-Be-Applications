#include <iostream>
#include "clsLoginScreen.h"

using namespace std;

int main()
{   

    while (!clsLoginScreen::ShowLoginScreen())
    {
        break;
    }   

    return 0;
}