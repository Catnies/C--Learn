#include <windows.h>

void OpenCalculator()
{
    // 使用 ShellExecute 打开系统计算器
    HINSTANCE result = ShellExecute(
        NULL,           // 无父窗口
        "open",        // 操作类型
        "calc.exe",    // 要打开的程序
        NULL,           // 无参数
        NULL,           // 使用默认工作目录
        SW_SHOW         // 显示窗口
    );

    // 错误处理（可选）
    if ((INT_PTR)result <= 32) {
        // 可以在此处添加错误处理代码
        // 例如：MessageBox(NULL, "无法打开计算器", "错误", MB_OK);
    }
};

// 使用示例
int main()
{
    OpenCalculator();
    return 0;
}