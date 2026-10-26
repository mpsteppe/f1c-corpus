int __stdcall sub_647AC0(DWORD NumberOfBytesWritten)
{
  int result; // eax

  result = *(_DWORD *)(NumberOfBytesWritten + 24);
  if ( *(_DWORD *)(result + 4) != 4096 )
    return sub_6462BB(
             *(_DWORD *)(result + 20),
             *(char **)(result + 24),
             4096 - *(_DWORD *)(result + 4),
             &NumberOfBytesWritten);
  return result;
}
