char __thiscall sub_497C40(_DWORD *this, int a2)
{
  int v3; // esi
  char result; // al
  int v5; // edi
  char *v6; // eax
  void *v7; // edi

  v3 = this[65];
  result = 0;
  v5 = 0;
  if ( v3 )
  {
    while ( 1 )
    {
      v6 = *(char **)(v3 + 4);
      if ( !v6 )
        v6 = byte_5EA438;
      if ( !sub_588410(v6, a2) )
        break;
      v5 = v3;
      v3 = *(_DWORD *)(v3 + 16);
      if ( !v3 )
        return 0;
    }
    if ( v5 )
      *(_DWORD *)(v5 + 16) = *(_DWORD *)(v3 + 16);
    else
      this[65] = *(_DWORD *)(v3 + 16);
    sub_494FD0(*(_DWORD *)(v3 + 12));
    *(_DWORD *)(v3 + 12) = 0;
    if ( *(_DWORD *)(v3 + 12) )
    {
      sub_542E50();
      v7 = *(void **)(v3 + 12);
      if ( v7 )
      {
        j_nullsub_3(*(_DWORD *)(v3 + 12));
        sub_587BCF(v7);
      }
    }
    if ( *(_DWORD *)(v3 + 4) )
      sub_587BCF(*(LPVOID *)(v3 + 4));
    sub_587BCF((LPVOID)v3);
    return 1;
  }
  return result;
}
