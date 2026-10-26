BOOL sub_4ED060()
{
  HWND v0; // ecx

  sub_561710(&unk_FAE918);
  v0 = hWndParent;
  if ( dword_B6F1B8 == hWndParent )
  {
    v0 = 0;
    hWndParent = 0;
  }
  if ( dword_B6F1B8 )
  {
    DestroyWindow(dword_B6F1B8);
    UnregisterClassA("CUBERealtime", hInstance);
    v0 = hWndParent;
    dword_B6F1B8 = 0;
  }
  if ( v0 )
  {
    DestroyWindow(v0);
    UnregisterClassA("CUBEApp", hInstance);
    hWndParent = 0;
  }
  return ClipCursor(0);
}
