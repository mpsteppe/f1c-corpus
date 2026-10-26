int __thiscall sub_599800(_DWORD *this)
{
  int v2; // esi
  int i; // eax
  int v4; // esi
  int j; // eax
  int v6; // esi
  int v7; // esi

  v2 = this[9];
  if ( v2 )
  {
    for ( i = *(_DWORD *)(v2 + 168); i; i = *(_DWORD *)(v2 + 168) )
    {
      v2 = i;
      sub_598580(*(_DWORD **)(i + 164));
      if ( *(_DWORD *)(v2 + 164) )
      {
        j_nullsub_6(*(void **)(v2 + 164));
        sub_5BE8AE();
      }
      *(_DWORD *)(v2 + 164) = 0;
    }
    sub_598580((_DWORD *)v2);
    j_nullsub_6((void *)v2);
    sub_5BE8AE();
  }
  v4 = this[11];
  if ( v4 )
  {
    for ( j = *(_DWORD *)(v4 + 20); j; j = *(_DWORD *)(v6 + 20) )
    {
      v6 = j;
      if ( *(_DWORD *)(j + 16) )
      {
        sub_590040();
        sub_5BE8AE();
      }
    }
    sub_590040();
    sub_5BE8AE();
  }
  v7 = this[12];
  while ( v7 )
  {
    v7 = *(_DWORD *)(v7 + 4);
    sub_5BE8AE();
  }
  return 0;
}
