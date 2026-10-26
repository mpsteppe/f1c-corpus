int __cdecl __crtMessageBoxA(const CHAR *a1, const CHAR *a2, UINT a3)
{
  HWND ActiveWindow; // ebx
  HMODULE LibraryA; // eax
  HMODULE v5; // edi
  HWINSTA ProcessWindowStation; // eax
  _BYTE v8[12]; // [esp+Ch] [ebp-10h] BYREF
  DWORD v9; // [esp+18h] [ebp-4h] BYREF

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
    if ( dword_FB8194 == 2 )
    {
      GetUserObjectInformationA = (BOOL (__stdcall *)(HANDLE, int, PVOID, DWORD, LPDWORD))GetProcAddress(
                                                                                            v5,
                                                                                            "GetUserObjectInformationA");
      if ( GetUserObjectInformationA )
        GetProcessWindowStation = (HWINSTA (__stdcall *)())GetProcAddress(v5, "GetProcessWindowStation");
    }
  }
  if ( !GetProcessWindowStation
    || (ProcessWindowStation = GetProcessWindowStation()) != 0
    && GetUserObjectInformationA(ProcessWindowStation, 1, v8, 12, &v9)
    && (v8[8] & 1) != 0 )
  {
    if ( GetActiveWindow )
    {
      ActiveWindow = GetActiveWindow();
      if ( ActiveWindow )
      {
        if ( GetLastActivePopup )
          ActiveWindow = GetLastActivePopup(ActiveWindow);
      }
    }
  }
  else if ( (unsigned int)dword_FB81A0 < 4 )
  {
    BYTE2(a3) |= 4u;
  }
  else
  {
    BYTE2(a3) |= 0x20u;
  }
  return MessageBoxA_0(ActiveWindow, a1, a2, a3);
}
