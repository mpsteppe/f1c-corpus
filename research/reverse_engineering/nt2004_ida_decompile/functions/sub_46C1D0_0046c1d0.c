void __thiscall sub_46C1D0(_DWORD *this, int a2)
{
  int v3; // edx
  HWND v4; // ebx
  HWND v5; // esi
  int v6; // edx
  tagRECT Rect; // [esp+8h] [ebp-10h] BYREF

  v3 = this[100];
  if ( a2 != v3 )
  {
    v4 = sub_46C170(v3);
    v5 = sub_46C170(a2);
    if ( v6 && a2 != 2 && a2 )
    {
      GetWindowRect(v4, &Rect);
      SetWindowPos(v5, 0, Rect.left, Rect.top, 0, 0, 1u);
    }
    if ( v5 )
      ShowWindow(v5, 5);
    if ( v4 )
      ShowWindow(v4, 0);
    this[100] = a2;
  }
}
