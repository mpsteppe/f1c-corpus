int __thiscall sub_612C70(
        int this,
        HINSTANCE hInstance,
        int a3,
        int nWidth,
        int nHeight,
        int a6,
        HWND *a7,
        HWND *a8,
        int a9)
{
  HWND DesktopWindow; // ebp
  int v11; // eax
  int v12; // esi
  int v13; // eax
  int v14; // ebx
  HWND v15; // eax
  HWND Window; // eax
  struct tagRECT Rect; // [esp+10h] [ebp-10h] BYREF

  DesktopWindow = GetDesktopWindow();
  *(_DWORD *)(this + 64) = 64;
  *(_DWORD *)(this + 100) = "CUBERealtime";
  *(_DWORD *)(this + 76) = 0;
  *(_DWORD *)(this + 72) = 0;
  *(_DWORD *)(this + 96) = 0;
  *(_DWORD *)(this + 88) = 0;
  *(_DWORD *)(this + 104) = 0;
  *(_DWORD *)(this + 84) = 0;
  *(_DWORD *)(this + 68) = a3;
  *(_DWORD *)(this + 60) = 48;
  if ( a6 != 1 )
  {
    *(_DWORD *)(this + 80) = hInstance;
    *(_DWORD *)(this + 92) = GetStockObject(5);
    if ( RegisterClassExA((const WNDCLASSEXA *)(this + 60)) )
    {
      Window = CreateWindowExA(8u, "CUBERealtime", 0, 0x80000000, 0, 0, nWidth, nHeight, 0, 0, hInstance, 0);
      *a8 = Window;
      *a7 = Window;
      Rect.left = 0;
      Rect.right = nWidth;
      Rect.top = 0;
      Rect.bottom = nHeight;
      ClipCursor(&Rect);
      ShowWindow(*a7, 5);
      UpdateWindow(*a7);
      return 0;
    }
    return -1;
  }
  *(_DWORD *)(this + 80) = hInstance;
  *(_DWORD *)(this + 92) = GetStockObject(5);
  if ( !RegisterClassExA((const WNDCLASSEXA *)(this + 60)) )
    return -1;
  GetClientRect(DesktopWindow, &Rect);
  v11 = ((Rect.right - Rect.left) >> 1) - (nWidth >> 1);
  Rect.left = 0;
  Rect.right = nWidth;
  v12 = v11 < 0 ? 0 : v11;
  v13 = ((Rect.bottom - Rect.top) >> 1) - (nHeight >> 1);
  Rect.top = 0;
  Rect.bottom = nHeight;
  v14 = v13 < 0 ? 0 : v13;
  AdjustWindowRectEx(&Rect, 0x80CA0000, 0, 1u);
  v15 = CreateWindowExA(
          1u,
          "CUBERealtime",
          WindowName,
          0x80CA0000,
          v12,
          v14,
          Rect.right - Rect.left,
          Rect.bottom - Rect.top,
          0,
          0,
          hInstance,
          0);
  *a7 = v15;
  *a8 = v15;
  if ( a9 )
  {
    ShowWindow(*a7, 5);
    UpdateWindow(*a7);
  }
  ClipCursor(0);
  return 0;
}
