int __stdcall sub_47F1B0(HWND hWnd, _DWORD *a2)
{
  CHAR String[256]; // [esp+8h] [ebp-100h] BYREF

  GetWindowTextA(hWnd, String, 255);
  if ( !strcmp(String, byte_B6CD60) )
    ++*a2;
  return 1;
}
