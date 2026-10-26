int __fastcall sub_505C90(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int v9; // esi
  double v10; // st7
  int v11; // esi
  float v13; // [esp+0h] [ebp-20h]
  float v14; // [esp+4h] [ebp-1Ch]

  v9 = dword_6152E8;
  if ( a9 )
    v9 = *(_DWORD *)(a9 + 28);
  v10 = (double)v9;
  v11 = dword_6152EC;
  if ( a9 )
    v11 = *(_DWORD *)(a9 + 32);
  v14 = (double)a4 / (double)v11;
  v13 = (double)a3 / v10;
  return sub_505D00(a1, a2, LODWORD(v13), LODWORD(v14), a5, a6, a7, a8, a9);
}
