void __stdcall sub_5AF533(int a1)
{
  HMODULE LibraryA; // eax
  HMODULE v2; // eax

  if ( !DebugSetMute && !DebugSetMute_0 )
  {
    if ( GetModuleHandleA("d3d9.dll") )
    {
      LibraryA = LoadLibraryA("d3d9.dll");
      if ( LibraryA )
        DebugSetMute = (int (__cdecl *)(_DWORD))GetProcAddress(LibraryA, "DebugSetMute");
    }
    if ( GetModuleHandleA("d3d9d.dll") )
    {
      v2 = LoadLibraryA("d3d9d.dll");
      if ( v2 )
        DebugSetMute_0 = (int (__cdecl *)(_DWORD))GetProcAddress(v2, "DebugSetMute");
    }
  }
  if ( dword_905D58 != -1 )
  {
LABEL_14:
    if ( dword_905D58 )
      return;
    goto LABEL_15;
  }
  if ( !sub_5AE703((BYTE *)4, "D3DXDoNotMute", (BYTE *)&dword_905D58, 4u) )
    dword_905D58 = 0;
  if ( dword_905D58 )
  {
    dword_905D58 = 1;
    goto LABEL_14;
  }
LABEL_15:
  if ( DebugSetMute )
    DebugSetMute(a1);
  if ( DebugSetMute_0 )
    DebugSetMute_0(a1);
}
