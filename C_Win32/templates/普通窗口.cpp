#include <Windows.h>
#include <winuser.h>

// ���ڹ��̺�����������Ϣ
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_DESTROY:                 // �ر�
        PostQuitMessage(0);          // ������Ϣѭ��
        return 0;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam); // Ĭ�ϴ���
}

/*
hInstance     - ��ǰӦ�ó���ʵ���ľ��
hPrevInstance - ǰһ��Ӧ�ó���ʵ���ľ����Win32��ʼ��ΪNULL��
lpCmdLine     - ָ��ָ��Ӧ�ó��������е���null��β���ַ���
nCmdShow      - ���ƴ��ڵ���ʾ��ʽ����Winuser.h�е�SW_*ֵ��
*/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // ���崰����
    WNDCLASS wc = {0};
    wc.lpfnWndProc   = WndProc;          // ָ����Ϣ������
    wc.hInstance     = hInstance;
    wc.lpszClassName = "MyWindowClass";  // ��������
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1); // ����ɫ

    RegisterClass(&wc);  // ע�ᴰ����

    // ��������
    HWND hwnd = CreateWindow(
        "MyWindowClass",       // ��������
        "Hello Windows",       // ���ڱ���
        WS_OVERLAPPEDWINDOW,   // ���ڷ��
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        NULL, NULL, hInstance, NULL);

    ShowWindow(hwnd, nCmdShow);   // ��ʾ����
    UpdateWindow(hwnd);           // ���´���

    // ��Ϣѭ��
    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);  // ������Ϣ
        DispatchMessage(&msg);   // �ַ���Ϣ
    }
    return msg.wParam;
}


