int __thiscall sub_6955DE(_DWORD *this, int a2, unsigned int a3, _DWORD *a4)
{
  int v4; // esi
  unsigned int v7; // ecx
  unsigned int v8; // eax
  int v10; // ecx
  int v11; // ecx
  int v12; // ecx

  v4 = a2;
  if ( !a2 )
    return -2147467259;
  while ( 1 )
  {
    switch ( *(_DWORD *)(v4 + 4) )
    {
      case 1:
        v8 = sub_6951CB(this, *(_DWORD **)(v4 + 8));
        if ( a3 >= v8 )
        {
          v4 = *(_DWORD *)(v4 + 12);
          a3 -= v8;
        }
        else
        {
          v4 = *(_DWORD *)(v4 + 8);
        }
        goto LABEL_14;
      case 6:
        v4 = *(_DWORD *)(v4 + 24);
        goto LABEL_14;
      case 8:
        v4 = *(_DWORD *)(v4 + 16);
        v7 = sub_6951CB(this, (_DWORD *)v4);
        if ( !v7 )
          return -2147467259;
        a3 %= v7;
        goto LABEL_14;
    }
    if ( *(_DWORD *)(v4 + 4) == 9 )
      break;
    if ( *(_DWORD *)(v4 + 4) != 11 )
    {
      sub_694C3A(this, 0, 0, "internal error: unknown node");
      return 0;
    }
    v4 = *(_DWORD *)(v4 + 32);
LABEL_14:
    if ( !v4 )
      return -2147467259;
  }
  v10 = *(_DWORD *)(v4 + 16);
  if ( v10 && (v11 = v10 - 1) != 0 && (v12 = v11 - 1) != 0 )
  {
    if ( v12 == 1 )
      a4[4] = 3;
  }
  else
  {
    a4[4] = 0;
  }
  a4[5] = *(_DWORD *)(v4 + 20);
  a4[6] = 1;
  a4[7] = 1;
  a4[8] = *(_DWORD *)(v4 + 32) & 0x200;
  return 0;
}
