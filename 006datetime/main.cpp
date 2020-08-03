//
// Created by wangpeng417 on 2020/8/1.
//
#include <iostream>
#include<ctime>

using namespace std;


int main() {

    time_t now = time(nullptr);
    cout << "now is:" << now << endl; // now is:1596416980

    // 转化成字符串
    char *dt = ctime(&now);
    cout << "dt is:" << dt << endl; // dt is:Mon Aug 03 09:09:40 2020

    // 转化成UTC时间
    tm *gmtm = gmtime(&now);
    char *dt1 = asctime(gmtm);
    cout << "dt1=" << dt1 << endl; // dt1=Mon Aug 03 01:09:40 2020

    // 格式化时间
    tm *ltm = localtime(&now);
    cout << "ltm=" << ltm << endl; // ltm=0x1117d28

    cout << "year-month-day hour:min:sec=" << 1900 + ltm->tm_year << "-" << 1 + ltm->tm_mon << "-" << ltm->tm_mday
         << " "
         << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl; // year-month-day min:sec=2020-8-3 8:9:40

    return 0;
}
