int __cdecl sub_597234(const CHAR *lpText, const CHAR *lpCaption, UINT uType)
{
  HWND ActiveWindow; // ebx
  HMODULE LibraryA; // eax
  HMODULE v5; // edi

  ActiveWindow = 0;
  if ( !MessageBoxA_0 )
  {
    LibraryA = LoadLibraryA("user32.dll");
    v5 = LibraryA;
    if ( !LibraryA )
      return 0;
    MessageBoxA_0 = (int (__stdcall *)(HWND, LPCSTR, LPCSTR, UINT))GetProcAddress(LibraryA, "MessageBoxA");
    if ( !MessageBoxA_0 )
      return 0;
    GetActiveWindow = (HWND (__stdcall *)())GetProcAddress(v5, "GetActiveWindow");
    GetLastActivePopup = (HWND (__stdcall *)(HWND))GetProcAddress(v5, "GetLastActivePopup");
  }
  if ( GetActiveWindow )
  {
    ActiveWindow = GetActiveWindow();
    if ( ActiveWindow )
    {
      if ( GetLastActivePopup )
        ActiveWindow = GetLastActivePopup(ActiveWindow);
    }
  }
  return MessageBoxA_0(ActiveWindow, lpText, lpCaption, uType);
}
