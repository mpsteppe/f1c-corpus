int __thiscall sub_6850B2(_DWORD *this, int a2, _DWORD *a3, unsigned int a4)
{
  int v6; // ecx
  int v7; // edx
  int v8; // esi
  unsigned int v9; // eax
  _DWORD *v10; // edx
  unsigned int i; // esi
  int v12; // edx
  int v13; // edi
  int v15; // [esp+1Ch] [ebp+Ch]
  int v16; // [esp+1Ch] [ebp+Ch]

  v6 = 1;
  if ( a4 <= 1 )
  {
LABEL_4:
    v15 = 0;
    while ( 1 )
    {
      v7 = ((_BYTE)v15 - 1) & 3;
      v8 = *(_DWORD *)(a2 + 4 * v7);
      if ( v8 != -1
        && *(double *)(*(_DWORD *)(this[5] + 4 * *a3) + 32) == *(double *)(*(_DWORD *)(this[5] + 4 * v8) + 32) )
      {
        break;
      }
      if ( (unsigned int)++v15 >= 4 )
        return 0;
    }
    v9 = 0;
    if ( a4 )
    {
      v10 = (_DWORD *)(a2 + 4 * v7);
      do
        a3[v9++] = *v10;
      while ( v9 < a4 );
    }
  }
  else
  {
    while ( *(double *)(*(_DWORD *)(this[5] + 4 * a3[v6]) + 32) == *(double *)(*(_DWORD *)(this[5] + 4 * *a3) + 32) )
    {
      if ( ++v6 >= a4 )
        goto LABEL_4;
    }
    for ( i = 0; i < a4; ++i )
    {
      v16 = 0;
      while ( 1 )
      {
        v12 = ((_BYTE)v16 + (_BYTE)i) & 3;
        v13 = *(_DWORD *)(a2 + 4 * v12);
        if ( v13 != -1
          && *(double *)(*(_DWORD *)(this[5] + 4 * a3[i]) + 32) == *(double *)(*(_DWORD *)(this[5] + 4 * v13) + 32) )
        {
          break;
        }
        if ( (unsigned int)++v16 >= 4 )
          goto LABEL_20;
      }
      a3[i] = *(_DWORD *)(a2 + 4 * v12);
LABEL_20:
      ;
    }
  }
  return 0;
}
