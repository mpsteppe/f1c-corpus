int __cdecl sub_588640(_BYTE *a1, _BYTE *a2, int a3)
{
  int v3; // ecx
  _BYTE *v4; // edi
  bool v5; // zf
  int v6; // ecx
  _BYTE *v7; // edi
  unsigned __int8 v9; // al

  v3 = a3;
  if ( a3 )
  {
    v4 = a1;
    do
    {
      if ( !v3 )
        break;
      v5 = *v4++ == 0;
      --v3;
    }
    while ( !v5 );
    v6 = a3 - v3;
    v7 = a1;
    do
    {
      if ( !v6 )
        break;
      v5 = *a2++ == *v7++;
      --v6;
    }
    while ( v5 );
    v9 = *(a2 - 1);
    v3 = 0;
    if ( v9 > *(v7 - 1) )
      return ~v3;
    if ( v9 != *(v7 - 1) )
    {
      v3 = -2;
      return ~v3;
    }
  }
  return v3;
}
