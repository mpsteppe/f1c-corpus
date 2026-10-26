int __fastcall sub_564AB0(int a1, int a2, int a3, int a4, int (__cdecl *a5)(int, int))
{
  int v5; // esi
  int v6; // edi

  v5 = 0;
  if ( a3 <= 0 )
    return 0;
  v6 = a2;
  while ( a5(a1, v6) )
  {
    ++v5;
    v6 += a4;
    if ( v5 >= a3 )
      return 0;
  }
  return a2 + a4 * v5;
}
