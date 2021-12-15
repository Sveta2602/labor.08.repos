#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
// Для строк!!!
#include <string>

// Для 3х функций
// #include <cstring>

using namespace std;

// Iteration example!
// Расскоментировать для использования

/*
int Count (char* str)
{
    if (strlen(str) <= 3)
        return 0;

    int k = 0;
    for (int i = 1; str[i] != 0; i++)
        if (str[i]  == 'a' && str[i + 1] == 'b' && str[i + 2] == 'c')
            k++;
    return k;
}

char* Change(char* str)
{
    if (strlen(str) < 3)
        return str;
    char* tmp = new char[strlen(str) * 4 / 3 + 1];
    char* t = tmp;
    tmp[0] = '\0';
    int i = 0;
    while (str[i] != 0)
    {
        if (str[i] == 'a' && str[i+1] ==  'b' && str[i+2] == 'c')
        {
            strcat(t, "**");
            t += 2;
            i += 3;
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
        }
    }
    *t++ = str[i++];
    *t++ = str[i++];
    *t = '\0';
    strcpy(str, tmp);
    return tmp;
}
*/

// Recursive example!
// Расскоментировать для использования

/*
int Count (char* str, int i)
{
    if (strlen(str) <= 3)
        return 0;

    if (str[i] != 0)
        if (str[i]  == 'a' && str[i + 1] == 'b' && str[i + 2] == 'c')
            return 1 + Count(str, i+1);
        else
            return Count(str, i+1);
    return 0;
}

char* Change(char* dest, const char * str, char * t, int i)
{
    if (str[i] != 0)
    {
        if (str[i] == 'a' && str[i+1] ==  'b' && str[i+2] == 'c')
        {
            strcat(t, "**");
            return Change(dest, str, t+4, i+3);
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
            return Change(dest, str, t, i);
        }
    } else {
        *t++ = str[i++];
        *t++ = str[i++];
        *t = '\0';
        return dest;
    }
}
*/

// Char example!
// Расскоментировать для использования
/*
int Count(char * s)
{
    int k = 0;
    int pos = 0;
    char *t;
    while (t = strchr(s + pos, 'a'))
    {
        pos = t - s + 1;
        if (s[pos] == 'b' && s[pos+1] == 'c')
            k++;
    }
    return k;
}

char * Change(char * s)
{
    char * t = new char[strlen(s)];
    char * p;
    int pos1 = 0;
    int pos2 = 0;
    *t = 0;
    while (p = strchr(s + pos1, 'a'))
    {
        if (s[p-s+1] == 'b' && s[p-s+2] == 'c')
        {
            pos2 = p-s+3;
            strncat(t, s+pos1, pos2-pos1-3);
            strcat(t, "**");
            pos1 = pos2;
        }
    }
    strcat(t, s+pos1);
    strcpy(s, t);
    return t;
}
*/

// String example!
// Расскоментировать для использования

int Count(const string s)
{
    int    k = 0;
    size_t pos = 0;
    while ((pos = s.find('a', pos)) != -1)
    {
        pos++;
        if (s[pos] == 'b' && s[pos + 1] == 'c')
            k++;
    }
    return k;
}

string Change(string& s)
{
    size_t pos = 0;
    while ((pos = s.find('a', pos)) != -1)
    {
        if (s[pos + 1] == 'b' && s[pos + 2] == 'c')
            s.replace(pos, 3, "**");
    }
    return s;
}

int main()
{
    //Iteration + Recursive + Char 
    //Переменные сразу для трех функций для String закомментировать
    //char str[100];
    //cin.getline(str,100);



    // Iteration example: 
    // cout << "Count abc > " << Count(str);
    // cout << endl;
    // cout << "Replce abc on string to ** > " << Change(str);


    // Recursive example:
    // cout << "Count abc > " << Count(str);
    // cout << endl;
    // char * dest1 = new char[151];
    // dest1[0] = '\0';
    // char * dest2;
    // dest2 = Change(dest1, str, dest1, 0);
    // cout << "Replce abc on string to ** > " << dest2;


    //Char example:
    // cout << "Count abc > " << Count(str);
    // cout << endl;
    // char * dest = new char[151];
    // dest = Change(str);
    // cout << "Replce abc on string to ** > " << dest;


    //String example:
    string str;
    cout << "Enter string > ";
    getline(cin, str);
    cout << "Count abc > " << Count(str);
    cout << endl;
    string dest = Change(str);
    cout << "Replce abc on string to ** > " << dest;

    return 0;
}
