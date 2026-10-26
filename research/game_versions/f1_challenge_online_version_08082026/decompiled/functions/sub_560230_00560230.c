int __thiscall sub_560230(_DWORD *this, const char *a2)
{
  int v3; // eax
  CHAR *v4; // edx
  CHAR v5; // cl
  int v6; // edi
  int v7; // edx
  const char *i; // ebp
  int v10; // esi
  int v12; // [esp+14h] [ebp-104h]
  CHAR SrcStr[256]; // [esp+18h] [ebp-100h] BYREF

  strcpy(SrcStr, a2);
  if ( sub_58B050(a2, 92) )
  {
    v3 = sub_58B050(a2, 92) + 1;
    v4 = &SrcStr[-v3];
    do
    {
      v5 = *(_BYTE *)v3;
      v4[v3] = *(_BYTE *)v3;
      ++v3;
    }
    while ( v5 );
  }
  sub_589901(SrcStr);
  v6 = 0;
  v12 = this[70];
  if ( v12 <= 0 )
    return -2;
  v7 = this[74];
  for ( i = (const char *)(v7 + 20); strcmp(SrcStr, i); i += 256 )
  {
    ++v6;
    v7 += 256;
    if ( v6 >= v12 )
      return -2;
  }
  v10 = this[71];
  this[73] = v6;
  sub_587F64(this[4], v10 + *(_DWORD *)(v7 + 4), 0);
  return 0;
}
