//
// Created by wangpeng417 on 2020/8/1.
//
#include <iostream>

using namespace std;

#include <fstream>

#include<sstream>

#include<string>

//#include<boost/lexical_cast.hpp>

int main() {

    int i1 = 11;
    float f1 = 12.4;
    cout << "to_string(i1)=" << to_string(i1) << ", to_string(f1)=" << to_string(f1) << endl;
    //to_string(i1)=11, to_string(f1)=12.400000

    int k = 100;
    stringstream ss;
    ss << k;
    string s;
    ss >> s;
    cout << "s=" << s << endl;
    ss.clear();
    // 也是可以转回来的
    string num = "1000";
    ss << num;
    int i;
    ss >> i;
    cout << "i=" << i << endl;


    ofstream fout("out.txt");

    if (fout.is_open()) {
        fout << "这是内容1\n";
        fout << "这是内容2\n";
        fout.close();
    }

    ifstream fin("out.txt");

    if (fin.is_open()) {
        string line;
        while (getline(fin, line)) {
            cout << line << endl;
        }
        fin.close();
    }
    return 0;
}
