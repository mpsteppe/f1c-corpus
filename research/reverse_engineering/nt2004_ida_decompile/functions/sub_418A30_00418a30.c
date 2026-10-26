CHAR *__thiscall sub_418A30(__int16 **this, int a2)
{
  int v2; // esi
  int v3; // eax
  __int16 *v4; // ecx
  int v5; // eax
  int v6; // edi
  __int16 *v7; // eax
  int v9; // eax
  __int16 *i; // edi

  v2 = (int)this[1];
  v3 = a2;
  if ( a2 >= 0 )
  {
    if ( a2 > v2 - 1 )
      v3 = v2 - 1;
  }
  else
  {
    v3 = 0;
  }
  v4 = *this;
  v5 = 24 * v3;
  v6 = v4[v5];
  v7 = &v4[v5];
  if ( v6 == a2 )
    return (CHAR *)(v7 + 1);
  v9 = 0;
  if ( v2 <= 0 )
    return &byte_629120;
  for ( i = v4; *i != a2; i += 24 )
  {
    if ( ++v9 >= v2 )
      return &byte_629120;
  }
  return (CHAR *)&v4[24 * v9 + 1];
}
