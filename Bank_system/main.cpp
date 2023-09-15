
#include <iostream>
#include <fstream>
#include <iomanip>
#include "C:/Users/AD/CodeBlocks/Bank_System/Screens/User/clsLoginScreen.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Core/clsCurrency.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Lib/clsInputValidate.h"
#include "C:/Users/AD/CodeBlocks/Bank_System/Lib/clsDate.h"



int main()
{

    system("color 1F");
    system("pause>0");

    while(true)
    {
       if(!clsLoginScreen::ShowLoginScreen())
        {
            break;
        }
    }

    system("pause>0");
    return 0;

};

