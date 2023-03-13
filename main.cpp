#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>

using namespace std;

//Для перменной N
bool input_int(double n) {
    string line = to_string(n),line2;
    unsigned char a[256],b;
    bool digits = true,negative = false, tochka, all_check;
    int minus = 0,dot = 0,i_tochka,count_zero = 0;

    line2 = line;
    strcpy((char *) a, line.c_str());
    for (int i = 0; i < strlen((char *) a); i++) {
        if (line2[i] == '.'){
            dot = dot + 1;
            i_tochka = i;
        }
        if (line2[i] == '-'){
            minus = minus + 1;
        }
    }
    for (int i = i_tochka; i < strlen((char *) a); i++){
        if (line2[i] == '0'){
            count_zero = count_zero + 1;
        }
    }
    if (count_zero + (line2.length()-i_tochka-1) == 12){
        dot = 0;
    }

    for (char c: ".") {
        line.erase(remove(line.begin(), line.end(), c), line.end());
    }
    for (char c: "-") {
        line.erase(remove(line.begin(), line.end(), c), line.end());
    }

    strcpy((char *) a, line.c_str());
    for (int i = 0; i < strlen((char *) a); i++) {
        if (isdigit(a[i]) == false){
            digits = false;
            break;
        }
    }

    if ((minus == 1 and line2[0] == '-') or (minus == 0)){
        negative = true;
    }
    if (dot == 0) {
        tochka = true;
    }
    if (dot >= 1){
        tochka = false;
    }
    if (negative == true and  digits == true and tochka == true){
        all_check = true;
    }
    else all_check = false;
    return all_check;
}

//Для переменной X
bool input_double(double x) {
    string line = to_string(x),line2;
    unsigned char a[256],b;
    bool digits = true,negative = false, tochka, all_check;
    int minus = 0,dot = 0,i_tochka,count_zero = 0;

    line2 = line;
    strcpy((char *) a, line.c_str());
    for (int i = 0; i < strlen((char *) a); i++) {
        if (line2[i] == '.'){
            dot = dot + 1;
        }
        if (line2[i] == '-'){
            minus = minus + 1;
        }
    }

    for (char c: ".") {
        line.erase(remove(line.begin(), line.end(), c), line.end());
    }
    for (char c: "-") {
        line.erase(remove(line.begin(), line.end(), c), line.end());
    }

    strcpy((char *) a, line.c_str());
    for (int i = 0; i < strlen((char *) a); i++) {
        if (isdigit(a[i]) == false){
            digits = false;
            break;
        }
    }

    if ((minus == 1 and line2[0] == '-') or (minus == 0)){
        negative = true;
    }
    if ((dot == 1) and (line2[line.length()] != '.' or line2[0] != '.') or (dot == 0)) {
        tochka = true;
    }
    if ((dot > 1) or (line2[0] == '-') and (line2[1] == '.')){
        tochka = false;
    }

    if (negative == true and  digits == true and tochka == true){
        all_check = true;
    }
    else all_check = false;
    return all_check;
}

bool check_lg(double x, int n){
    bool check = true;
    for (int i = 4; i <= n; i++) {
        if (1 + x / (7 + x) * sqrt(i) <= 0) {
            check = false;
            break;
        }
    }
    return check;
}

int main(){
    int i;
    double n,x,ln = 1, y;
    bool goodbit1 = false, goodbit2 = false;

    while(true)
    {
        cout << "Введите N >= 4" << endl;
        cin >> n;
        if ((cin.fail()) or (n < 4) or input_int(n) == false)
        {
            cout << "Не верно введено число, повторите ввод\n";
            cin.clear();
            while (cin.get() != '\n');
        }
        else {
            goodbit1 = true;
            break;}
    }

    if (goodbit1){
        while(true)
        {
            cout << "Введите X" << endl;
            cin >> x;
            if ((cin.fail()) or !input_double(x))
            {
                cout << "Не верно введено число, повторите ввод\n";
                cin.clear();
                while (cin.get() != '\n');
            }
            else {
                goodbit2 = true;
                break;
            }
        }
    }

    if (goodbit2){
        if (check_lg(x, n) and x != -7){
            for (int i = 4; i <= int(n); i++) {
                ln *=log(1 + x / (7 + x) * sqrt(i));
            }
            y = x + x / (7 + x) * ln;
            cout << "Y = " << y;
        }
        else{
            cout << "Ваш X = " << x << " не удовлетворяет ОДЗ уравнения! Запустите программу заново и введите другой X..." << endl;
        }
    }
    return 0;
}