BOOL __stdcall EnumFunc(HWND hWnd, LPARAM a2)
{
  char *v2; // eax
  CHAR String[256]; // [esp+4h] [ebp-100h] BYREF

  GetWindowTextA(hWnd, String, 255);
  v2 = sub_41D840(&byte_91CC38, String);
  SetWindowTextA(hWnd, v2);
  return 1;
}
