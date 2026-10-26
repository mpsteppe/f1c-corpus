int __stdcall sub_548A30(int a1, int a2)
{
  int v2; // ecx
  int v3; // eax
  int v4; // ecx
  int i; // esi
  int result; // eax
  int v7; // edx

  sub_5884E0(a1 % 42330);
  v3 = sub_5884ED(v2);
  v4 = (v3 << 17) | v3;
  for ( i = 0; i < 4; ++i )
  {
    result = (unsigned __int8)v4 / 78;
    v7 = (unsigned __int8)v4 % 78 + 48;
    if ( __OFSUB__(v7, 48) )
    {
      LOBYTE(v7) = 48;
    }
    else if ( v7 >= 126 )
    {
      LOBYTE(v7) = 126;
    }
    v4 >>= 8;
    *(_BYTE *)(i + a2) = v7;
  }
  *(_BYTE *)(a2 + 4) = 0;
  return result;
}
