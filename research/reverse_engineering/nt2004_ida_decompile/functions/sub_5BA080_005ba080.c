int sub_5BA080()
{
  int result; // eax
  int v1; // esi

  result = TlsIndex;
  v1 = *((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + TlsIndex);
  if ( *(_DWORD *)(v1 + 32) )
  {
    result = sub_5BDFF0();
    if ( !result )
    {
      result = sub_5BDFB0(*(LPVOID *)(v1 + 32));
      *(_DWORD *)(v1 + 32) = 0;
    }
  }
  return result;
}
