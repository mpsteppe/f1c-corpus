int __thiscall sub_547420(_DWORD *this)
{
  _DWORD *v2; // esi
  int i; // eax
  void *v4; // edi
  int v5; // esi
  int j; // eax
  void *v7; // edi

  v2 = (_DWORD *)this[9];
  if ( v2 )
  {
    for ( i = v2[48]; i; i = v2[48] )
    {
      v2 = (_DWORD *)i;
      sub_546370(*(_DWORD **)(i + 188));
      v4 = (void *)v2[47];
      if ( v4 )
      {
        j_nullsub_3(v2[47]);
        sub_587BCF(v4);
      }
      v2[47] = 0;
    }
    sub_546370(v2);
    j_nullsub_3(v2);
    sub_587BCF(v2);
  }
  v5 = this[11];
  if ( v5 )
  {
    for ( j = *(_DWORD *)(v5 + 20); j; j = *(_DWORD *)(v5 + 20) )
    {
      v5 = j;
      v7 = *(void **)(j + 16);
      if ( v7 )
      {
        sub_53AB70(*(LPVOID **)(j + 16));
        sub_587BCF(v7);
      }
    }
    sub_53AB70((LPVOID *)v5);
    sub_587BCF((LPVOID)v5);
  }
  return 0;
}
