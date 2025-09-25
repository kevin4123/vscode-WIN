#include <Windows.h>
#include <winuser.h>

// 窗口过程函数：处理消息
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_DESTROY:                 // 关闭
        PostQuitMessage(0);          // 结束消息循环
        return 0;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam); // 默认处理
}

/*
hInstance     - 当前应用程序实例的句柄
hPrevInstance - 前一个应用程序实例的句柄（Win32中始终为NULL）
lpCmdLine     - 指向指定应用程序命令行的以null结尾的字符串
nCmdShow      - 控制窗口的显示方式（见Winuser.h中的SW_*值）
*/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // 定义窗口类
    WNDCLASS wc = {0};
    wc.lpfnWndProc   = WndProc;          // 指定消息处理函数
    wc.hInstance     = hInstance;
    wc.lpszClassName = "MyWindowClass";  // 窗口类名
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1); // 背景色

    RegisterClass(&wc);  // 注册窗口类

    // 创建窗口
    HWND hwnd = CreateWindow(
        "MyWindowClass",       // 窗口类名
        "Hello Windows",       // 窗口标题
        WS_OVERLAPPEDWINDOW,   // 窗口风格
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        NULL, NULL, hInstance, NULL);

    ShowWindow(hwnd, nCmdShow);   // 显示窗口
    UpdateWindow(hwnd);           // 更新窗口

    // 消息循环
    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);  // 翻译消息
        DispatchMessage(&msg);   // 分发消息
    }
    return msg.wParam;
}


