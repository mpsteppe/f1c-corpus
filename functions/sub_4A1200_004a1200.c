int __stdcall sub_4A1200(LONG nWidth, LONG nHeight, int a3)
{
  HWND DesktopWindow; // ebp
  LONG top; // edi
  BOOL v6; // ecx
  int v7; // eax
  int v8; // ebp
  HWND Window; // eax
  int v10; // ebp
  int v11; // [esp-10h] [ebp-9Ch]
  int v12; // [esp-Ch] [ebp-98h]
  DWORD v13; // [esp-4h] [ebp-90h]
  int Y; // [esp+18h] [ebp-74h]
  tagRECT Rect; // [esp+1Ch] [ebp-70h] BYREF
  RECT v16; // [esp+2Ch] [ebp-60h] BYREF
  CHAR WindowName[80]; // [esp+3Ch] [ebp-50h] BYREF

  DesktopWindow = GetDesktopWindow();
  stru_7CE270.cbSize = 48;
  stru_7CE270.hInstance = hinst;
  stru_7CE270.lpszClassName = aCuberealtime;
  stru_7CE270.lpfnWndProc = (WNDPROC)((char *)&loc_4A155F + 1);
  stru_7CE270.style = 64;
  stru_7CE270.hIcon = LoadIconA(hinst, (LPCSTR)0x65);
  stru_7CE270.hIconSm = 0;
  stru_7CE270.hCursor = 0;
  stru_7CE270.lpszMenuName = 0;
  stru_7CE270.cbClsExtra = 0;
  stru_7CE270.cbWndExtra = 0;
  stru_7CE270.hbrBackground = (HBRUSH)GetStockObject(5);
  StringFormatWithBufferOverflowCheck(WindowName, "%s v%0.3f", aF1Challenge990, *(float *)&dword_7C56B0);
  if ( byte_5EC4A4 )
  {
    stru_7CE2A8.cbSize = 48;
    stru_7CE2A8.hInstance = hinst;
    stru_7CE2A8.lpszClassName = ClassName;
    stru_7CE2A8.lpfnWndProc = (WNDPROC)((char *)&loc_4A155F + 1);
    stru_7CE2A8.style = 0;
    stru_7CE2A8.hIcon = LoadIconA(hinst, (LPCSTR)0x65);
    stru_7CE2A8.hIconSm = 0;
    stru_7CE2A8.hCursor = 0;
    stru_7CE2A8.lpszMenuName = 0;
    stru_7CE2A8.cbClsExtra = 0;
    stru_7CE2A8.cbWndExtra = 0;
    stru_7CE2A8.hbrBackground = (HBRUSH)GetStockObject(5);
    if ( !RegisterClassExA(&stru_7CE2A8) )
      return 1;
    GetClientRect(DesktopWindow, &Rect);
    top = Rect.top;
    v6 = ((Rect.right - Rect.left) >> 1) - (nWidth >> 1) < 0;
    v10 = ((Rect.right - Rect.left) >> 1) - (nWidth >> 1);
    if ( byte_5EC4A4 >= 2 )
      v13 = 0x80000000;
    else
      v13 = -2134769664;
    Rect.left = 0;
    Rect.top = 0;
    Rect.right = nWidth;
    v7 = Rect.bottom - top;
    v8 = v6 ? 0 : v10;
    Rect.bottom = nHeight;
    Y = ((v7 >> 1) - (nHeight >> 1)) & (((v7 >> 1) - (nHeight >> 1) < 0) - 1);
    AdjustWindowRectEx(&Rect, v13, 0, 1u);
    v12 = Rect.bottom - Rect.top;
    v11 = Rect.right - Rect.left;
    if ( byte_5EC4A4 >= 2 )
      Window = CreateWindowExA(1u, ClassName, WindowName, 0x80000000, v8, Y, v11, v12, 0, 0, hinst, 0);
    else
      Window = CreateWindowExA(1u, ClassName, WindowName, 0x80CA0000, v8, Y, v11, v12, 0, 0, hinst, 0);
    hWnd = Window;
    stru_7CE270.hIcon = 0;
    if ( !RegisterClassExA(&stru_7CE270) )
      return 1;
    dword_7CE2E0 = CreateWindowExA(0, aCuberealtime, 0, 0x52000000u, 0, 0, nWidth, nHeight, hWnd, 0, hinst, 0);
    ClipCursor(0);
  }
  else
  {
    stru_7CE270.hIcon = LoadIconA(0, (LPCSTR)0x7F00);
    if ( !RegisterClassExA(&stru_7CE270) )
      return 1;
    dword_7CE2E0 = CreateWindowExA(8u, aCuberealtime, WindowName, 0x80000000, 0, 0, nWidth, nHeight, 0, 0, hinst, 0);
    hWnd = dword_7CE2E0;
    v16.left = 0;
    v16.right = nWidth;
    v16.top = 0;
    v16.bottom = nHeight;
    ClipCursor(&v16);
  }
  ShowWindow(hWnd, 1);
  byte_7CE2E4 = 1;
  return 0;
}
