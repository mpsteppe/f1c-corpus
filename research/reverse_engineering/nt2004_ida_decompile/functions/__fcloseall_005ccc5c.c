int __cdecl _fcloseall()
{
  int v0; // ebx
  int i; // edi
  int v2; // esi
  int v3; // eax

  v0 = 0;
  _lock(2);
  for ( i = 3; i < dword_801500; ++i )
  {
    v2 = 4 * i;
    v3 = *(_DWORD *)(4 * i + dword_8004E4);
    if ( v3 )
    {
      if ( (*(_BYTE *)(v3 + 12) & 0x83) != 0 && fclose(*(FILE **)(4 * i + dword_8004E4)) != -1 )
        ++v0;
      if ( i >= 20 )
      {
        DeleteCriticalSection((LPCRITICAL_SECTION)(*(_DWORD *)(v2 + dword_8004E4) + 32));
        sub_5C1B88(*(LPVOID *)(v2 + dword_8004E4));
        *(_DWORD *)(v2 + dword_8004E4) = 0;
      }
    }
  }
  _unlock(2);
  return v0;
}
