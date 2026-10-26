HMODULE __cdecl sub_500EAC(int a1)
{
  HMODULE LibraryA; // eax
  HMODULE result; // eax

  if ( DebugSetMute )
    goto LABEL_10;
  if ( !dword_8B0090 )
  {
    if ( GetModuleHandleA("d3d8.dll") )
    {
      LibraryA = LoadLibraryA("d3d8.dll");
      if ( LibraryA )
        DebugSetMute = (int (__cdecl *)(_DWORD))GetProcAddress(LibraryA, "DebugSetMute");
    }
    result = GetModuleHandleA("d3d8d.dll");
    if ( result )
    {
      result = LoadLibraryA("d3d8d.dll");
      if ( result )
      {
        result = (HMODULE)GetProcAddress(result, "DebugSetMute");
        dword_8B0090 = (int (*)(void))result;
      }
    }
    if ( !DebugSetMute )
    {
LABEL_11:
      if ( !dword_8B0090 )
        return result;
      return (HMODULE)dword_8B0090();
    }
LABEL_10:
    result = (HMODULE)DebugSetMute(a1);
    goto LABEL_11;
  }
  return (HMODULE)dword_8B0090();
}
