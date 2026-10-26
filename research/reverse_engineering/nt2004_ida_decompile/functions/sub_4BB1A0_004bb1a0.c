int __stdcall sub_4BB1A0(LONG nWidth, LONG nHeight, int a3)
{
  HWND DesktopWindow; // ebp
  int v5; // eax
  LONG top; // ecx
  int v7; // ebp
  int v8; // eax
  HWND Window; // eax
  RECT *v10; // [esp-4h] [ebp-88h]
  int Y; // [esp+10h] [ebp-74h]
  struct tagRECT Rect; // [esp+14h] [ebp-70h] BYREF
  RECT v13; // [esp+24h] [ebp-60h] BYREF
  CHAR WindowName[80]; // [esp+34h] [ebp-50h] BYREF

  DesktopWindow = GetDesktopWindow();
  stru_766198.cbSize = 48;
  stru_766198.hInstance = hinst;
  stru_766198.lpszClassName = aCuberealtime;
  stru_766198.lpfnWndProc = (WNDPROC)sub_4BB540;
  stru_766198.style = 64;
  stru_766198.hIcon = LoadIconA(hinst, (LPCSTR)0x65);
  stru_766198.hIconSm = 0;
  stru_766198.hCursor = 0;
  stru_766198.lpszMenuName = 0;
  stru_766198.cbClsExtra = 0;
  stru_766198.cbWndExtra = 0;
  stru_766198.hbrBackground = (HBRUSH)GetStockObject(5);
  sprintf(WindowName, "%s", aNascarThunderT);
  if ( byte_62A154 )
  {
    stru_7661D0.cbSize = 48;
    stru_7661D0.hInstance = hinst;
    stru_7661D0.lpszClassName = ClassName;
    stru_7661D0.lpfnWndProc = (WNDPROC)sub_4BB540;
    stru_7661D0.style = 0;
    stru_7661D0.hIcon = LoadIconA(hinst, (LPCSTR)0x65);
    stru_7661D0.hIconSm = LoadIconA(hinst, (LPCSTR)0x65);
    stru_7661D0.hCursor = 0;
    stru_7661D0.lpszMenuName = 0;
    stru_7661D0.cbClsExtra = 0;
    stru_7661D0.cbWndExtra = 0;
    stru_7661D0.hbrBackground = (HBRUSH)GetStockObject(5);
    if ( !RegisterClassExA(&stru_7661D0) )
      return 1;
    GetClientRect(DesktopWindow, &Rect);
    v5 = ((Rect.right - Rect.left) >> 1) - (nWidth >> 1);
    top = Rect.top;
    Rect.left = 0;
    Rect.top = 0;
    Rect.right = nWidth;
    v7 = v5 < 0 ? 0 : v5;
    v8 = (Rect.bottom - top) >> 1;
    Rect.bottom = nHeight;
    Y = (v8 - (nHeight >> 1)) & ((v8 - (nHeight >> 1) < 0) - 1);
    AdjustWindowRectEx(&Rect, 0x80C20000, 0, 1u);
    hWndParent = CreateWindowExA(
                   1u,
                   ClassName,
                   WindowName,
                   0x80CA0000,
                   v7,
                   Y,
                   Rect.right - Rect.left,
                   Rect.bottom - Rect.top,
                   0,
                   0,
                   hinst,
                   0);
    stru_766198.hIcon = 0;
    if ( !RegisterClassExA(&stru_766198) )
      return 1;
    Window = CreateWindowExA(0, aCuberealtime, 0, 0x52000000u, 0, 0, nWidth, nHeight, hWndParent, 0, hinst, 0);
    v10 = 0;
  }
  else
  {
    stru_766198.hIcon = LoadIconA(0, (LPCSTR)0x7F00);
    if ( !RegisterClassExA(&stru_766198) )
      return 1;
    Window = CreateWindowExA(8u, aCuberealtime, WindowName, 0x80000000, 0, 0, nWidth, nHeight, 0, 0, hinst, 0);
    hWndParent = Window;
    v13.left = 0;
    v13.right = nWidth;
    v13.top = 0;
    v13.bottom = nHeight;
    v10 = &v13;
  }
  dword_766218 = Window;
  ClipCursor(v10);
  if ( sub_4634F0(dword_764D70) )
  {
    ShowWindow(hWndParent, 0);
  }
  else
  {
    ShowWindow(hWndParent, 5);
    byte_76621C = 1;
    if ( dword_766218 )
    {
      GetWindowRect(dword_766218, &::Rect);
      return 0;
    }
  }
  return 0;
}
