#include <iostream>
using namespace std;


// #define 宏名 替换文本 -> 宏名是您希望定义的宏的名称，替换文本是在程序中遇到宏名时要替换的内容。#define 指令通常放在源文件的开头，且不需要以分号结尾。
#define PI 3.1415926
#define NUMBER 114514
#define SQUARE(x) (x)*(x)                           // 声明一个带参数的宏, 这些宏在调用时会被直接展开，而不会像普通函数那样产生函数调用的开销。
#define MAX(a, b) ((a) > (b) ? (a) : (b))           // 还支持更多更复杂的运算逻辑.
#define PRINT(a) cout << #a << " = " << a << endl;  // 在变量前面加 # , 则代表以字符串的方式输出.


// ## 为记号粘贴运算符, 当宏展开时，它会移除 ## 运算符，并将 ## 左边和右边的标记直接连接起来，形成一个新的标记。
#define MEMBER(type, a) type member_##a             // MEMBER(int, 1)                ->     展开为: int member_1;        
#define CALL_FUNCTION(name, suffix) name##suffix()  // CALL_FUNCTION(print, message) ->     展开为: printMessage();



// 条件编译, 如果定义了_WIN32, 则编译程序段1, Linux则编译程序段2....
// 主要使用的语句: #ifdef , #ifndef, #elif, #else, #endif.

#ifdef _WIN32               // 这部分代码只有在 _WIN32 被定义时才会被编译
    #include <windows.h>
#elif __linux__             // 这部分代码只有在 __linux__ 被定义时才会被编译
    #include <unistd.h>
#elif __APPLE__
    #include <TargetConditionals.h>
#else 
    #include <accctrl.h>
#endif  // 必须, 用于结束 #ifdef 块.



#ifdef WW                  // 这部分代码只有在 WW 没有被定义时才会被编译
    #include <accctrl.h>
#endif  // 必须, 用于结束 #ifdef 块.



// 一些默认的系统提供的宏
// _DATE_       ->   编译日期
// _TIME_       ->   编译时间
// _FILE_       ->   源文件路径
// _LINE_       ->   行号


int main() {
    int a(10);
    cout << SQUARE(a) << endl;  // 直接展开为 10 * 10
    PRINT(a);                   // 会输出之前预定义的语句.

    int x = 10, y = 20;
    int max_value = MAX(x, y);
    cout << "x 和 y 中的较大值是：" << max_value << endl;


    return 0;
}