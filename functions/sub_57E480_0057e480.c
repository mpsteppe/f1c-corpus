bool __thiscall sub_57E480(HINSTANCE *this)
{
  HINSTANCE v2; // eax
  WNDCLASSA WndClass; // [esp+8h] [ebp-28h] BYREF

  if ( dword_8D3E28 )
    return 1;
  memset(&WndClass, 0, sizeof(WndClass));
  v2 = this[477];
  WndClass.style = 3;
  WndClass.lpfnWndProc = WindowProcIgnore6666;
  WndClass.hInstance = v2;
  WndClass.lpszMenuName = 0;
  WndClass.lpszClassName = lpClassName;
  RegisterClassA(&WndClass);
  dword_8D3E28 = CreateWindowExA(
                   0,
                   lpClassName,
                   lpWindowName,
                   0x8000000u,
                   0x80000000,
                   0x80000000,
                   1,
                   1,
                   0,
                   0,
                   this[477],
                   0);
  return dword_8D3E28 != 0;
}
