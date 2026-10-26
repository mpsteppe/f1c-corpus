unsigned __int8 *__thiscall sub_616CA0(_DWORD *this, unsigned __int8 *a2, unsigned __int8 *a3, char *String2, int a5)
{
  unsigned __int8 *result; // eax
  _DWORD *v7; // esi
  _DWORD *v8; // eax
  int v9; // eax
  unsigned int v10; // [esp+10h] [ebp-208h]
  char Str[253]; // [esp+18h] [ebp-200h] BYREF
  __int16 v12; // [esp+115h] [ebp-103h]
  char v13; // [esp+117h] [ebp-101h]
  char v14[253]; // [esp+118h] [ebp-100h] BYREF
  __int16 v15; // [esp+215h] [ebp-3h]
  char v16; // [esp+217h] [ebp-1h]

  memset(Str, 0, sizeof(Str));
  v12 = 0;
  v13 = 0;
  memset(v14, 0, sizeof(v14));
  v15 = 0;
  v16 = 0;
  result = a2;
  v7 = 0;
  if ( !a2 )
    return result;
  sub_616680(a2, Str);
  sub_616680(a3, v14);
  v10 = sub_616750(Str);
  if ( v10 > 8 )
    return (unsigned __int8 *)v7;
  v8 = operator new(0x24u);
  if ( v8 )
    v7 = sub_616890(v8, a5);
  else
    v7 = 0;
  if ( !a5 )
    v7[7] = sub_616B50(this, String2);
  sub_615860((int)(v7 + 3), Str);
  if ( strlen(v14) )
    sub_615860((int)(v7 + 5), v14);
  if ( !a5 )
  {
    v9 = this[v10];
    if ( !v9 )
    {
      this[v10] = v7;
      return (unsigned __int8 *)v7;
    }
    for ( ; *(_DWORD *)(v9 + 4); v9 = *(_DWORD *)(v9 + 4) )
      ;
    goto LABEL_20;
  }
  v9 = *(_DWORD *)(a5 + 8);
  if ( !v9 )
  {
    *(_DWORD *)(a5 + 8) = v7;
    return (unsigned __int8 *)v7;
  }
  if ( !*(_DWORD *)(v9 + 4) )
  {
LABEL_20:
    *(_DWORD *)(v9 + 4) = v7;
    v7[8] = v9;
    return (unsigned __int8 *)v7;
  }
  do
    v9 = *(_DWORD *)(v9 + 4);
  while ( *(_DWORD *)(v9 + 4) );
  *(_DWORD *)(v9 + 4) = v7;
  v7[8] = v9;
  return (unsigned __int8 *)v7;
}
