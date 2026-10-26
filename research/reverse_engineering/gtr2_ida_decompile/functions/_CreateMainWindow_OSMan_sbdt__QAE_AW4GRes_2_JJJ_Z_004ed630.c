int __stdcall sbdt::OSMan::CreateMainWindow(int nWidth, int nHeight, int a3)
{
  HWND DesktopWindow; // ebp
  LONG top; // edi
  int v5; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // ebp
  int Y; // [esp+10h] [ebp-74h]
  tagRECT Rect; // [esp+14h] [ebp-70h] BYREF
  RECT v12; // [esp+24h] [ebp-60h] BYREF
  CHAR WindowName[80]; // [esp+34h] [ebp-50h] BYREF

  DesktopWindow = GetDesktopWindow();
  stru_B6F148.cbSize = 48;
  stru_B6F148.hInstance = hInstance;
  stru_B6F148.lpszClassName = "CUBERealtime";
  stru_B6F148.lpfnWndProc = (WNDPROC)sub_4ED2C0;
  stru_B6F148.style = 64;
  stru_B6F148.hIcon = LoadIconA(hInstance, (LPCSTR)0x65);
  stru_B6F148.hIconSm = 0;
  stru_B6F148.hCursor = 0;
  stru_B6F148.lpszMenuName = 0;
  stru_B6F148.cbClsExtra = 0;
  stru_B6F148.cbWndExtra = 0;
  stru_B6F148.hbrBackground = (HBRUSH)GetStockObject(5);
  sprintf(WindowName, "%s", "GTR2");
  if ( !byte_91CB5C )
  {
    stru_B6F148.hIcon = LoadIconA(0, (LPCSTR)0x7F00);
    if ( RegisterClassExA(&stru_B6F148) )
    {
      dword_B6F1B8 = CreateWindowExA(
                       8u,
                       "CUBERealtime",
                       WindowName,
                       0x80000000,
                       0,
                       0,
                       nWidth,
                       nHeight,
                       0,
                       0,
                       hInstance,
                       0);
      hWndParent = dword_B6F1B8;
      v12.left = 0;
      v12.right = nWidth;
      v12.top = 0;
      v12.bottom = nHeight;
      ClipCursor(&v12);
      goto LABEL_8;
    }
    return 1;
  }
  stru_B6F178.cbSize = 48;
  stru_B6F178.hInstance = hInstance;
  stru_B6F178.lpszClassName = "CUBEApp";
  stru_B6F178.lpfnWndProc = (WNDPROC)sub_4ED2C0;
  stru_B6F178.style = 0;
  stru_B6F178.hIcon = LoadIconA(hInstance, (LPCSTR)0x65);
  stru_B6F178.hIconSm = 0;
  stru_B6F178.hCursor = 0;
  stru_B6F178.lpszMenuName = 0;
  stru_B6F178.cbClsExtra = 0;
  stru_B6F178.cbWndExtra = 0;
  stru_B6F178.hbrBackground = (HBRUSH)GetStockObject(5);
  if ( !RegisterClassExA(&stru_B6F178) )
    return 1;
  GetClientRect(DesktopWindow, &Rect);
  top = Rect.top;
  v5 = ((Rect.right - Rect.left) >> 1) - (nWidth >> 1);
  Rect.left = 0;
  Rect.top = 0;
  Rect.right = nWidth;
  v6 = v5 < 0 ? 0 : v5;
  v7 = Rect.bottom - top;
  v8 = v6;
  Rect.bottom = nHeight;
  Y = ((v7 >> 1) - (nHeight >> 1)) & (((v7 >> 1) - (nHeight >> 1) < 0) - 1);
  AdjustWindowRectEx(&Rect, 0x80C20000, 0, 1u);
  hWndParent = CreateWindowExA(
                 1u,
                 "CUBEApp",
                 WindowName,
                 0x80CA0000,
                 v8,
                 Y,
                 Rect.right - Rect.left,
                 Rect.bottom - Rect.top,
                 0,
                 0,
                 hInstance,
                 0);
  stru_B6F148.hIcon = 0;
  if ( !RegisterClassExA(&stru_B6F148) )
    return 1;
  dword_B6F1B8 = CreateWindowExA(0, "CUBERealtime", 0, 0x52000000u, 0, 0, nWidth, nHeight, hWndParent, 0, hInstance, 0);
  ClipCursor(0);
LABEL_8:
  if ( sub_473630(&dword_B6CBA8) )
  {
    ShowWindow(hWndParent, 0);
  }
  else
  {
    ShowWindow(hWndParent, 5);
    byte_B6F1BC = 1;
    if ( dword_B6F1B8 )
      GetWindowRect(dword_B6F1B8, &::Rect);
  }
  sub_561600(dword_B6F1B8);
  return 0;
}
