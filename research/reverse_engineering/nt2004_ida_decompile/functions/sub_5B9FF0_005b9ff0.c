int sub_5B9FF0()
{
  int v0; // esi

  v0 = *((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + TlsIndex);
  if ( !*(_DWORD *)(v0 + 32) )
    *(_DWORD *)(v0 + 32) = sub_5BDF40(4, sub_5BA040, sub_5BA050, sub_5BA070);
  return *(_DWORD *)(v0 + 32);
}
