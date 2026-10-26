BOOL sub_4BB4C0()
{
  HWND v0; // ecx

  v0 = hWndParent;
  if ( dword_766218 == hWndParent )
  {
    v0 = 0;
    hWndParent = 0;
  }
  if ( dword_766218 )
  {
    DestroyWindow(dword_766218);
    UnregisterClassA(aCuberealtime, hinst);
    v0 = hWndParent;
    dword_766218 = 0;
  }
  if ( v0 )
  {
    DestroyWindow(v0);
    UnregisterClassA(ClassName, hinst);
    hWndParent = 0;
  }
  return ClipCursor(0);
}
