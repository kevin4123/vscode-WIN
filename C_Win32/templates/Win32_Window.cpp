/**
 * @file main.cpp
 * @brief GUI程序入口
 *
 */

#include <windows.h>

/**
 * @brief 窗口过程
 * 
 * 
 * @param hwnd 				窗口句柄
 * @param msg 				消息类型
 * @param wParam 			附加参数
 * @param lParam 			附加参数
 * @return 
 */
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	HDC 		hdc;																							// 设备描述表
	PAINTSTRUCT ps;	
	RECT        rect;																					// 文本测量结构


    switch (msg) {
	/* --- 窗口创建 --- */
	case WM_CREATE: 
		hdc = GetDC(hwnd);
		
		ReleaseDC(hwnd, hdc);
		return 0;
	/* --- 绘制 --- */
    case WM_PAINT: 
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		DrawText(hdc,						// 窗口句柄
				TEXT("Hello, Windows 98!"), //文本信息
				-1, 						//表示该文本字符串以0结尾
				&rect,
			DT_SINGLELINE | DT_CENTER | DT_VCENTER);//显示样式：单行，居中，水平

		EndPaint(hwnd, &ps);
        return 0;
	/* --- 关闭窗口 --- */
	case WM_CLOSE: // 
		if(MessageBox(hwnd, TEXT("确定关闭窗口吗？"), TEXT("提示"), MB_YESNO) == IDYES){
		DestroyWindow(hwnd);  							// 发送WM_DESTROY消息
		}
		return 0;
	/* --- 退出程序 --- */
    case WM_DESTROY: 
        PostQuitMessage(0);  						// 发送WM_QUIT消息
        return 0;
    }

	/* --- 默认处理 --- */
    return DefWindowProc(hwnd, msg, wParam, lParam); 
}


/**
 * @brief WinMain函数:程序入口
 * 
 * 
 * @param hInstance 		程序实例句柄	
 * @param hPrevInstance 	前一个程序实例句柄
 * @param lpCmdLine 		命令行参数
 * @param iCmdShow 			显示方式
 * @return 
 */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int iCmdShow) {

	static TCHAR 	szAppName[] = TEXT("HelloWin");								// 窗口类名
	HWND 			hwnd; 														// 窗口句柄
	MSG 			msg;  														// 消息结构
	WNDCLASS		wndclass;													// 窗口类结构

    /* --- 1. 定义窗口类 --- */
	wndclass.style = CS_HREDRAW | CS_VREDRAW;   // 窗口类样式
	wndclass.lpfnWndProc = WndProc;             // 窗口过程
	wndclass.cbClsExtra = 0;                    // 附加的窗口类内存
	wndclass.cbWndExtra = 0;                    // 附加的窗口内存
	wndclass.hInstance = hInstance;             // 实例句柄                      
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);   		  // 图标句柄
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);  		  // 光标句柄
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);        		 // 背景色
	wndclass.lpszMenuName = NULL;                // 菜单名称		
	wndclass.lpszClassName = szAppName;          // 窗口类名

    /* --- 2. 注册窗口类 --- */
	if (!RegisterClass(&wndclass))
	{
			MessageBox(NULL, TEXT("这个程序需要在 Windows NT 才能执行！"), szAppName, MB_ICONERROR);
			return 0;
	}
    /* --- 3. 创建窗口 --- */
	hwnd = CreateWindow(szAppName,    // 窗口类
			TEXT("标题"),            // 窗口标题
			WS_OVERLAPPEDWINDOW,          // 窗口样式
			CW_USEDEFAULT,                      // 初始位置
			CW_USEDEFAULT,                      // 初始位置
			CW_USEDEFAULT,                 // 宽度
			CW_USEDEFAULT,                // 高度
			NULL,                      // 父窗口句柄
			NULL,                           // 菜单句柄
			hInstance,                             // 实例句柄
			NULL);                        // 创建参数

	
    /* --- 4. 显示窗口 --- */
    ShowWindow(hwnd, iCmdShow);  	 // 显示窗口    WM_SHOWWINDOW
    UpdateWindow(hwnd);           			// 更新窗口	   WM_PAINT

    /* --- 消息循环 --- */
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
