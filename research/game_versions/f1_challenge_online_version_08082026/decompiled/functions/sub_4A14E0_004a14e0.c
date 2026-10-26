BOOL sub_4A14E0()
{
  HWND v0; // ecx

  v0 = hWnd;
  if ( dword_7CE2E0 == hWnd )
  {
    v0 = 0;
    hWnd = 0;
  }
  if ( dword_7CE2E0 )
  {
    DestroyWindow(dword_7CE2E0);
    UnregisterClassA(aCuberealtime, hinst);
    v0 = hWnd;
    dword_7CE2E0 = 0;
  }
  if ( v0 )
  {
    DestroyWindow(v0);
    UnregisterClassA(ClassName, hinst);
    hWnd = 0;
  }
  return ClipCursor(0);
}
