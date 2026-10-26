int __thiscall sub_5F2D80(
        int this,
        HINSTANCE hInstance,
        int a3,
        LONG nWidth,
        LONG Y,
        int a6,
        HWND *a7,
        HWND *a8,
        int a9)
{
  int v11; // eax
  LONG top; // ecx
  int v13; // edx
  int v14; // eax
  int v15; // ebp
  HWND Window; // eax
  HWND v17; // eax
  HWND hWnd; // [esp+10h] [ebp-14h]
  struct tagRECT Rect; // [esp+14h] [ebp-10h] BYREF
  int Ya; // [esp+34h] [ebp+10h]

  hWnd = GetDesktopWindow();
  *(_DWORD *)(this + 60) = 48;
  *(_DWORD *)(this + 80) = hInstance;
  *(_DWORD *)(this + 100) = "CUBERealtime";
  *(_DWORD *)(this + 68) = a3;
  *(_DWORD *)(this + 64) = 64;
  *(_DWORD *)(this + 84) = 0;
  *(_DWORD *)(this + 104) = 0;
  *(_DWORD *)(this + 88) = 0;
  *(_DWORD *)(this + 96) = 0;
  *(_DWORD *)(this + 72) = 0;
  *(_DWORD *)(this + 76) = 0;
  *(_DWORD *)(this + 92) = GetStockObject(5);
  if ( !RegisterClassExA((const WNDCLASSEXA *)(this + 60)) )
    return -1;
  if ( a6 == 1 )
  {
    GetClientRect(hWnd, &Rect);
    v11 = ((Rect.right - Rect.left) >> 1) - (nWidth >> 1);
    top = Rect.top;
    Rect.left = 0;
    Rect.top = 0;
    Rect.right = nWidth;
    v13 = v11 < 0 ? 0 : v11;
    v14 = Rect.bottom - top;
    v15 = v13;
    Rect.bottom = Y;
    Ya = ((v14 >> 1) - (Y >> 1)) & (((v14 >> 1) - (Y >> 1) < 0) - 1);
    AdjustWindowRectEx(&Rect, 0x80CA0000, 0, 1u);
    Window = CreateWindowExA(
               1u,
               "CUBERealtime",
               WindowName,
               0x80CA0000,
               v15,
               Ya,
               Rect.right - Rect.left,
               Rect.bottom - Rect.top,
               0,
               0,
               hInstance,
               0);
    *a7 = Window;
    *a8 = Window;
    if ( a9 )
    {
      ShowWindow(*a7, 5);
      UpdateWindow(*a7);
    }
    ClipCursor(0);
    return 0;
  }
  else
  {
    v17 = CreateWindowExA(8u, "CUBERealtime", 0, 0x80000000, 0, 0, nWidth, Y, 0, 0, hInstance, 0);
    *a8 = v17;
    *a7 = v17;
    Rect.left = 0;
    Rect.right = nWidth;
    Rect.top = 0;
    Rect.bottom = Y;
    ClipCursor(&Rect);
    ShowWindow(*a7, 5);
    UpdateWindow(*a7);
    return 0;
  }
}
