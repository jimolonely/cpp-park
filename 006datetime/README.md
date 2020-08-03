
# 时间

```c++
#include<ctime>

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
     << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl; 
    // year-month-day min:sec=2020-8-3 8:9:40
```

这里主要了解2个结构

## time_t

查看其结构就是long型，代表从1970年1月1日经过的秒数。

```c++
#  define __int32 long
typedef __int32 __time32_t;
typedef __time32_t time_t;
```

## tm

其是一个封装的结构体：

```c++
struct tm
{ /* A structure for storing the attributes of a broken-down time; (once
   * again, it isn't defined elsewhere, so no guard is necessary).  Note
   * that we are within the scope of <time.h> itself, so we must provide
   * the complete structure declaration here.
   */
  int  tm_sec;  	/* Seconds: 0-60 (to accommodate leap seconds) */
  int  tm_min;  	/* Minutes: 0-59 */
  int  tm_hour; 	/* Hours since midnight: 0-23 */
  int  tm_mday; 	/* Day of the month: 1-31 */
  int  tm_mon;  	/* Months *since* January: 0-11 */
  int  tm_year; 	/* Years since 1900 */
  int  tm_wday; 	/* Days since Sunday (0-6) */
  int  tm_yday; 	/* Days since Jan. 1: 0-365 */
  int  tm_isdst;	/* +1=Daylight Savings Time, 0=No DST, -1=unknown */
};
```

