_DWORD *__thiscall sub_57ACC0(_DWORD *this, int a2, int a3, char *String2, _DWORD *a5)
{
  _DWORD *v6; // ebx
  _DWORD *result; // eax
  _DWORD *v8; // eax
  int v9; // eax
  int v10; // ecx
  int j; // eax
  int v12; // eax
  int i; // ecx
  unsigned int v14; // [esp+Ch] [ebp-204h]
  char Str[253]; // [esp+10h] [ebp-200h] BYREF
  __int16 v16; // [esp+10Dh] [ebp-103h]
  char v17; // [esp+10Fh] [ebp-101h]
  char v18[253]; // [esp+110h] [ebp-100h] BYREF
  __int16 v19; // [esp+20Dh] [ebp-3h]
  char v20; // [esp+20Fh] [ebp-1h]

  Str[0] = byte_629120;
  v18[0] = byte_629120;
  memset(&Str[1], 0, 0xFCu);
  v16 = 0;
  v17 = 0;
  v6 = 0;
  memset(&v18[1], 0, 0xFCu);
  v19 = 0;
  v20 = 0;
  result = (_DWORD *)a2;
  if ( !a2 )
    return result;
  sub_57A800(a2, Str);
  sub_57A810(a3, v18);
  v14 = sub_57AA10(Str);
  if ( v14 > 8 )
    return v6;
  v8 = operator new(0x24u);
  if ( v8 )
    v6 = sub_57A650(v8, a5);
  else
    v6 = 0;
  if ( !a5 )
  {
    v9 = sub_57AE60(String2);
    sub_57A760(v6, v9);
  }
  sub_578600((int)(v6 + 3), Str);
  if ( strlen(v18) )
    sub_578600((int)(v6 + 5), v18);
  if ( !a5 )
  {
    v12 = this[v14];
    if ( !v12 )
    {
      this[v14] = v6;
      return v6;
    }
    for ( i = *(_DWORD *)(v12 + 4); i; i = *(_DWORD *)(i + 4) )
      v12 = i;
    *(_DWORD *)(v12 + 4) = v6;
    v6[8] = v12;
    return v6;
  }
  v10 = a5[2];
  if ( v10 )
  {
    for ( j = *(_DWORD *)(v10 + 4); j; j = *(_DWORD *)(j + 4) )
      v10 = j;
    *(_DWORD *)(v10 + 4) = v6;
    v6[8] = v10;
    return v6;
  }
  else
  {
    a5[2] = v6;
    return v6;
  }
}
