int __cdecl flsall(int a1)
{
  int v1; // ebx
  int v2; // edi
  int i; // esi
  int v4; // eax
  int v5; // eax
  int v6; // ecx
  int result; // eax

  v1 = 0;
  v2 = 0;
  _lock(2);
  for ( i = 0; i < dword_801500; ++i )
  {
    v4 = *(_DWORD *)(dword_8004E4 + 4 * i);
    if ( v4 && (*(_BYTE *)(v4 + 12) & 0x83) != 0 )
    {
      _lock_file2(i, *(_DWORD *)(dword_8004E4 + 4 * i));
      v5 = *(_DWORD *)(dword_8004E4 + 4 * i);
      v6 = *(_DWORD *)(v5 + 12);
      if ( (v6 & 0x83) != 0 )
      {
        if ( a1 == 1 )
        {
          if ( _fflush_lk(v5) != -1 )
            ++v1;
        }
        else if ( !a1 && (v6 & 2) != 0 && _fflush_lk(*(_DWORD *)(dword_8004E4 + 4 * i)) == -1 )
        {
          v2 = -1;
        }
      }
      _unlock_file2(i, *(_DWORD *)(dword_8004E4 + 4 * i));
    }
  }
  _unlock(2);
  result = v1;
  if ( a1 != 1 )
    return v2;
  return result;
}
