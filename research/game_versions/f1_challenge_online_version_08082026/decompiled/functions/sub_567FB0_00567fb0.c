_DWORD *__thiscall sub_567FB0(_DWORD *this, int a2, int a3, int a4, _DWORD *a5)
{
  _DWORD *v6; // ebx
  _DWORD *result; // eax
  _DWORD *v8; // eax
  int v9; // eax
  _DWORD *v10; // eax
  _DWORD *i; // ecx
  int v12; // ecx
  int j; // eax
  int v14; // eax
  int m; // ecx
  int v16; // eax
  int k; // ecx
  unsigned int v18; // [esp+Ch] [ebp-204h]
  char v19[253]; // [esp+10h] [ebp-200h] BYREF
  __int16 v20; // [esp+10Dh] [ebp-103h]
  char v21; // [esp+10Fh] [ebp-101h]
  char v22[253]; // [esp+110h] [ebp-100h] BYREF
  __int16 v23; // [esp+20Dh] [ebp-3h]
  char v24; // [esp+20Fh] [ebp-1h]

  v19[0] = byte_5EA438[0];
  v22[0] = byte_5EA438[0];
  memset(&v19[1], 0, 0xFCu);
  v20 = 0;
  v21 = 0;
  v6 = 0;
  memset(&v22[1], 0, 0xFCu);
  v23 = 0;
  v24 = 0;
  result = (_DWORD *)a2;
  if ( !a2 )
    return result;
  sub_567AF0(a2, (int)v19);
  sub_567B00(a3, (int)v22);
  v18 = sub_567D00(v19);
  if ( v18 > 8 )
    return v6;
  v8 = (_DWORD *)sub_587C03(44);
  if ( v8 )
    v6 = sub_567900(v8, a5);
  else
    v6 = 0;
  if ( !a5 )
  {
    v9 = sub_568220(a4);
    sub_4979C0(v6, v9);
  }
  sub_566650((int)(v6 + 4), v19);
  if ( strlen(v22) )
    sub_566650((int)(v6 + 6), v22);
  if ( a5 )
  {
    v10 = sub_5679C0(a5, (int)v19);
    if ( v10 )
    {
      if ( v10[3] )
      {
        for ( i = (_DWORD *)v10[3]; i; i = (_DWORD *)i[3] )
          v10 = i;
        v10[3] = v6;
        v6[10] = v10;
        return v6;
      }
      else
      {
        v10[3] = v6;
        v6[10] = v10;
        return v6;
      }
    }
    else
    {
      v12 = a5[2];
      if ( v12 )
      {
        for ( j = *(_DWORD *)(v12 + 4); j; j = *(_DWORD *)(j + 4) )
          v12 = j;
        *(_DWORD *)(v12 + 4) = v6;
        v6[9] = v12;
        return v6;
      }
      else
      {
        a5[2] = v6;
        return v6;
      }
    }
  }
  v14 = sub_568210(v19);
  if ( !v14 )
  {
    v16 = this[v18];
    if ( !v16 )
    {
      this[v18] = v6;
      return v6;
    }
    for ( k = *(_DWORD *)(v16 + 4); k; k = *(_DWORD *)(k + 4) )
      v16 = k;
    *(_DWORD *)(v16 + 4) = v6;
    v6[9] = v16;
    return v6;
  }
  if ( *(_DWORD *)(v14 + 12) )
  {
    for ( m = *(_DWORD *)(v14 + 12); m; m = *(_DWORD *)(m + 12) )
      v14 = m;
    *(_DWORD *)(v14 + 12) = v6;
    v6[10] = v14;
    return v6;
  }
  else
  {
    *(_DWORD *)(v14 + 12) = v6;
    v6[10] = v14;
    return v6;
  }
}
