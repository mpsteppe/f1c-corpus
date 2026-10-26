void __cdecl sub_4F7C60()
{
  int v0; // esi
  bool v1; // zf

  v0 = dword_7D7514;
  while ( v0 )
  {
    v1 = *(_BYTE *)(v0 + 8) == 0;
    v0 = *(_DWORD *)(v0 + 4);
    if ( !v1 )
      sub_5BE8AE();
    sub_5BE8AE();
  }
  dword_7D7514 = 0;
  dword_7D7518 = 0;
  dword_7D751C = 0;
  dword_7D7520 = 0;
  if ( dword_7D743C[24] )
    sub_5BE8AE();
  sub_57A7A0(&dword_7D743C[9]);
  sub_437430(dword_7D743C);
}
