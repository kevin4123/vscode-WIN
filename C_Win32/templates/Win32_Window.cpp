/**
 * @file main.cpp
 * @brief GUI�������
 *
 */

#include <windows.h>

/**
 * @brief ���ڹ���
 * 
 * 
 * @param hwnd 				���ھ��
 * @param msg 				��Ϣ����
 * @param wParam 			���Ӳ���
 * @param lParam 			���Ӳ���
 * @return 
 */
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	HDC 		hdc;																							// �豸������
	PAINTSTRUCT ps;	
	RECT        rect;																					// �ı������ṹ


    switch (msg) {
	/* --- ���ڴ��� --- */
	case WM_CREATE: 
		hdc = GetDC(hwnd);
		
		ReleaseDC(hwnd, hdc);
		return 0;
	/* --- ���� --- */
    case WM_PAINT: 
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		DrawText(hdc,						// ���ھ��
				TEXT("Hello, Windows 98!"), //�ı���Ϣ
				-1, 						//��ʾ���ı��ַ�����0��β
				&rect,
			DT_SINGLELINE | DT_CENTER | DT_VCENTER);//��ʾ��ʽ�����У����У�ˮƽ

		EndPaint(hwnd, &ps);
        return 0;
	/* --- �رմ��� --- */
	case WM_CLOSE: // 
		if(MessageBox(hwnd, TEXT("ȷ���رմ�����"), TEXT("��ʾ"), MB_YESNO) == IDYES){
		DestroyWindow(hwnd);  							// ����WM_DESTROY��Ϣ
		}
		return 0;
	/* --- �˳����� --- */
    case WM_DESTROY: 
        PostQuitMessage(0);  						// ����WM_QUIT��Ϣ
        return 0;
    }

	/* --- Ĭ�ϴ��� --- */
    return DefWindowProc(hwnd, msg, wParam, lParam); 
}


/**
 * @brief WinMain����:�������
 * 
 * 
 * @param hInstance 		����ʵ�����	
 * @param hPrevInstance 	ǰһ������ʵ�����
 * @param lpCmdLine 		�����в���
 * @param iCmdShow 			��ʾ��ʽ
 * @return 
 */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int iCmdShow) {

	static TCHAR 	szAppName[] = TEXT("HelloWin");								// ��������
	HWND 			hwnd; 														// ���ھ��
	MSG 			msg;  														// ��Ϣ�ṹ
	WNDCLASS		wndclass;													// ������ṹ

    /* --- 1. ���崰���� --- */
	wndclass.style = CS_HREDRAW | CS_VREDRAW;   // ��������ʽ
	wndclass.lpfnWndProc = WndProc;             // ���ڹ���
	wndclass.cbClsExtra = 0;                    // ���ӵĴ������ڴ�
	wndclass.cbWndExtra = 0;                    // ���ӵĴ����ڴ�
	wndclass.hInstance = hInstance;             // ʵ�����                      
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);   		  // ͼ����
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);  		  // �����
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);        		 // ����ɫ
	wndclass.lpszMenuName = NULL;                // �˵�����		
	wndclass.lpszClassName = szAppName;          // ��������

    /* --- 2. ע�ᴰ���� --- */
	if (!RegisterClass(&wndclass))
	{
			MessageBox(NULL, TEXT("���������Ҫ�� Windows NT ����ִ�У�"), szAppName, MB_ICONERROR);
			return 0;
	}
    /* --- 3. �������� --- */
	hwnd = CreateWindow(szAppName,    // ������
			TEXT("����"),            // ���ڱ���
			WS_OVERLAPPEDWINDOW,          // ������ʽ
			CW_USEDEFAULT,                      // ��ʼλ��
			CW_USEDEFAULT,                      // ��ʼλ��
			CW_USEDEFAULT,                 // ���
			CW_USEDEFAULT,                // �߶�
			NULL,                      // �����ھ��
			NULL,                           // �˵����
			hInstance,                             // ʵ�����
			NULL);                        // ��������

	
    /* --- 4. ��ʾ���� --- */
    ShowWindow(hwnd, iCmdShow);  	 // ��ʾ����    WM_SHOWWINDOW
    UpdateWindow(hwnd);           			// ���´���	   WM_PAINT

    /* --- ��Ϣѭ�� --- */
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
