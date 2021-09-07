#include <windows.h>
#include <iostream>
#include <conio.h>
#include <thread>
#include <WinUser.h>
#include <string>
#include <vector>

using namespace std;

int nameingNumber = 0;
// interger that defines at what value comes after the name of the profile then plus itsself after it is creates, if unsure leave at zero

// YOU MIGHT NEED TO INCREASE SLEEP TIMES X2 IF YOUR COMPUTER IS SLOW

// GO TO LINEs 91 - 109

bool programActive = false;
bool CursorDebugActive = false;
string FirefoxWindowName = "Firefox - Choose User Profile";



string gen_random(int length) {

    string randomstring;
    string characters = "1234567890abcdefghijklmnoprstuvyzxwq";

    for (int i = 0; i < length; ++i) {
        randomstring += characters[rand() % (characters.size())];
    }

    return randomstring;
}




void ProgramActivation()
{

    while (true)
    {
        
        Sleep(1000);               
        if (GetAsyncKeyState('T'))
        {
            programActive = !programActive;
            cout << "TEST MODULE IS SET TO: " << programActive << "\n";

        }
        if (GetAsyncKeyState('Y'))
        {
            CursorDebugActive = !CursorDebugActive;
            cout << "CURSOR POSITION DEBUG IS SET TO: " << CursorDebugActive << "\n";

        }
        if (GetAsyncKeyState('R'))
        {
            cout << "\nTEST MODULE STATUS: " << programActive << "\n" << "CURSOR POSITION DEBUG STATUS: " << CursorDebugActive << "\n\n";
        }

    }

}



void Creator1()
{   
    while (true)
    {
        Sleep(1000);
        if (GetAsyncKeyState('U'))
        {
            cout << "Opening FireFurry" << "\n";
            system("cd C:\\Program Files\\Mozilla Firefox");
            system("start firefox.exe -P");
            Sleep(3000);
            
        }
    }

    cout << "Done0";
}

void Creator2()
{
    while (true)
    {
        while (programActive == true)
        {
           
            //=====================================================
            //=====================================================
            //=====================================================
            // POSITION OF THE CREATE PROFILE BUTTON
            int x1 = 747;
            int y1 = 439;
            // POSITION OF THE NEXT BUTTON
            int x2 = 987;
            int y2 = 693;
            //=====================================================
            //=====================================================
            //=====================================================

            // 8====== > {()}
            // Sex jokes = funny


            // IF YOU WANT TO CHAGE THE NAME OF THE USERS THATGE THE WORDS IN THE " " BELOW
            std::wstring msg = L"BotUser";
            msg += to_wstring(nameingNumber);
                        
                      
            std::vector<INPUT> vec;
            for (auto ch : msg)
            {
                INPUT input = { 0 };
                input.type = INPUT_KEYBOARD;
                input.ki.dwFlags = KEYEVENTF_UNICODE;
                input.ki.wScan = ch;
                vec.push_back(input);

                input.ki.dwFlags |= KEYEVENTF_KEYUP;
                vec.push_back(input);
            }


            Sleep(1000);   

            HWND FirefoxWindow = FindWindowA(NULL, FirefoxWindowName.c_str()); 

            SetForegroundWindow(FirefoxWindow);

            Sleep(1000);

            SetCursorPos(x1, y1);

            mouse_event(MOUSEEVENTF_LEFTDOWN, x1, y1, 0, 0);

            mouse_event(MOUSEEVENTF_LEFTUP, x1, y1, 0, 0);

            Sleep(500);

            SetCursorPos(x2, y2);

            mouse_event(MOUSEEVENTF_LEFTDOWN, x2, y2, 0, 0);

            mouse_event(MOUSEEVENTF_LEFTUP, x2, y2, 0, 0);

            Sleep(500);

            SendInput(vec.size(), vec.data(), sizeof(INPUT));

            Sleep(1000);

            SetCursorPos(x2, y2);

            mouse_event(MOUSEEVENTF_LEFTDOWN, x2, y2, 0, 0);

            mouse_event(MOUSEEVENTF_LEFTUP, x2, y2, 0, 0);
            
            wcout << msg << "Has Been Made" << "\n";
            Sleep(500);
            nameingNumber++;



        }
    }

    // fucking pointless lol
    cout << "Done1";
}



void CursorPosDebug() 
{
    while (true)
    {
        while (CursorDebugActive == true) 
        {
            POINT coord;
            GetCursorPos(&coord);
            cout << "Xpos:" << coord.x << "Ypos:" << coord.y << "\n";
            Sleep(500);

        }
    }
}






int main()
{   
    
    cout << "Created by Tubaplayer#8315 on Discord, tubaplayerdis on GitHub.\n\n";
    Sleep(500);
    cout << "This program will not return any errors so make sure you reed the README.TXT file on how to use, if you didnt read it READ IT NOW\n\n";
    Sleep(2000);
    // TWELVE IS A GOOD NUMBER STFU
    cout << "Porgram Will start in 12 seconds\n";
    Sleep(2000);
    // I am NOT doing counting with vars anymore for fucks sake
    cout << "10\n";
    Sleep(1000);
    cout << "9\n";
    Sleep(1000);
    cout << "8\n";
    Sleep(1000);
    cout << "7\n";
    Sleep(1000);
    cout << "6\n";
    Sleep(1000);
    cout << "5\n";
    Sleep(1000);
    cout << "4\n";
    Sleep(1000);
    cout << "3\n";
    Sleep(1000);
    cout << "2\n";
    Sleep(1000);
    cout << "1\n";
    Sleep(1000);
    cout << "0\n";
    // Writing that was Calming
    cout << "\n\n\nPRESS T TO TOGGLE CREATOR MODULE - YOU NEED FIREFOX OPEN TO START OTHERWISE IT WILL START TO CLICK IN RANDOM LOCATIONS\nPRESS Y TO TOGGLE CURSOR POSITION DEBUG\nPRESS R TO VIEW CURRENT STATUS OF MODULES\nPRESS U TO OPEN FIREFOX PROFILE MANAGER\n\n\n";
    
    

    thread thread_object(Creator1);
    thread thread_object1(Creator2);
    thread thread_object2(CursorPosDebug);
    thread thread_object3(ProgramActivation);
    
    thread_object3.join();
    thread_object.join();
    thread_object1.join();
    thread_object2.join();
    

    return 0;
}



