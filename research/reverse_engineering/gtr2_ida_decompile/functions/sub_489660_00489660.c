char __thiscall sub_489660(DWORD *this)
{
  int v2; // edx
  HWND v3; // eax
  HWND v4; // edi
  HWND v5; // ebx
  int v6; // edx
  struct tagRECT Rect; // [esp+4h] [ebp-10h] BYREF

  sub_482F50(this);
  sub_4887A0(this);
  v2 = this[212];
  if ( v2 != 3 )
  {
    v3 = sub_47F5F0(v2);
    v4 = dword_B6CE6C;
    v5 = v3;
    if ( v6 )
    {
      GetWindowRect(v3, &Rect);
      SetWindowPos(v4, 0, Rect.left, Rect.top, 0, 0, 1u);
    }
    if ( v4 )
      ShowWindow(v4, 5);
    if ( v5 )
      ShowWindow(v5, 0);
    this[212] = 3;
  }
  if ( dwInitParam )
  {
    DestroyWindow((HWND)dwInitParam);
    dwInitParam = 0;
  }
  return 1;
}
