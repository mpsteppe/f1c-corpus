BOOL __fastcall sub_5BD100(_BYTE *a1, int a2)
{
  bool v2; // zf
  int v3; // eax
  int v4; // edx
  int v5; // ecx
  int v6; // eax
  int v7; // edx
  int v8; // ecx

  v2 = a2 == 0;
  if ( a2 > 0 )
  {
    do
    {
      if ( !*a1 )
        break;
      v3 = sub_5BC130((int)a1, a2);
      if ( v3 < 0 )
        return 0;
      v6 = sub_5BC130(v3 + v5, v4 - v3);
      if ( v6 < 0 )
        return 0;
      a2 = v7 - v6;
      a1 = (_BYTE *)(v6 + v8);
    }
    while ( a2 > 0 );
    v2 = a2 == 0;
  }
  return !v2 && *a1 == 0;
}
