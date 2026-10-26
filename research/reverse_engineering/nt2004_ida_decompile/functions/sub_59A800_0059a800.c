int __stdcall sub_59A800(int a1, int a2)
{
  int v2; // eax
  int v3; // ecx
  int i; // esi
  int result; // eax
  int v6; // edx

  srand(a1 % 42330);
  v2 = rand();
  v3 = (v2 << 17) | v2;
  for ( i = 0; i < 4; ++i )
  {
    result = (unsigned __int8)v3 / 78;
    v6 = (unsigned __int8)v3 % 78 + 48;
    if ( __OFSUB__(v6, 48) )
    {
      LOBYTE(v6) = 48;
    }
    else if ( v6 >= 126 )
    {
      LOBYTE(v6) = 126;
    }
    v3 >>= 8;
    *(_BYTE *)(i + a2) = v6;
  }
  *(_BYTE *)(a2 + 4) = 0;
  return result;
}
