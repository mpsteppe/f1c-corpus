int __thiscall sub_4C2860(_DWORD *this, int a2)
{
  int *v3; // eax
  int v4; // esi
  char *v5; // eax
  int v6; // eax
  int *v7; // eax

  v3 = (int *)this[4];
  this[6] = v3;
  if ( !v3 )
    return 0;
  v4 = *v3;
  if ( *v3 )
  {
    do
    {
      v5 = *(char **)(v4 + 8);
      if ( !v5 )
        v5 = byte_5EA438;
      if ( !sub_588410(v5, a2) )
        break;
      v6 = this[6];
      if ( v6 )
        this[6] = *(_DWORD *)(v6 + 4);
      v7 = (int *)this[6];
      if ( !v7 )
        return 0;
      v4 = *v7;
    }
    while ( *v7 );
  }
  return v4;
}

