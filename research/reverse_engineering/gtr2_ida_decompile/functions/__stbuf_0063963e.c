int __cdecl _stbuf(int a1)
{
  int v1; // eax
  int *v2; // edi
  void *v3; // eax
  int v4; // edi

  if ( !_isatty(*(_DWORD *)(a1 + 16)) )
    return 0;
  if ( (_UNKNOWN *)a1 == &unk_912DF0 )
  {
    v1 = 0;
  }
  else
  {
    if ( (_UNKNOWN *)a1 != &unk_912E10 )
      return 0;
    v1 = 1;
  }
  ++dword_FB8350;
  if ( (*(_WORD *)(a1 + 12) & 0x10C) != 0 )
    return 0;
  v2 = (int *)(4 * v1 + 16483156);
  if ( *(_DWORD *)&algn_FB8354[4 * v1] || (v3 = malloc(0x1000u), (*v2 = (int)v3) != 0) )
  {
    v4 = *v2;
    *(_DWORD *)(a1 + 8) = v4;
    *(_DWORD *)a1 = v4;
    *(_DWORD *)(a1 + 24) = 4096;
    *(_DWORD *)(a1 + 4) = 4096;
  }
  else
  {
    *(_DWORD *)(a1 + 8) = a1 + 20;
    *(_DWORD *)a1 = a1 + 20;
    *(_DWORD *)(a1 + 24) = 2;
    *(_DWORD *)(a1 + 4) = 2;
  }
  *(_WORD *)(a1 + 12) |= 0x1102u;
  return 1;
}
