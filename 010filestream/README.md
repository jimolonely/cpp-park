
# file stream

* fstream：创建文件、写入和读取文件信息
    * ifstream：读取文件信息
    * ofstream：创建文件，写入文件信息

## 都写一个文件
 
```c++
#include <fstream>

int main() {

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
```

# 整型转字符串

## 使用 stringstream

```c++
#include<sstream>

int main() {
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
}
```

## 使用to_string

```c++
#include<string>

int main() {

    int i1 = 11;
    float f1 = 12.4;
    cout << "to_string(i1)=" << to_string(i1) << ", to_string(f1)=" << to_string(f1) << endl;
    //to_string(i1)=11, to_string(f1)=12.400000
}
```

## 使用boost库

不过要额外安装

```c++
#include <boost/lexical_cast.hpp>  
using namespace std;  
int main()  
{  
    string s="1234";  
    int k = boost::lexical_cast<int>(s);  
    cout<<"Integer value of string s is : "<<k<<"\n";  

    string s1="1234";  
    int k1 = boost::lexical_cast<int>(s1);  
    cout<<"Integer value of string s1 is : "<<k1<<"\n";  
}  
```
