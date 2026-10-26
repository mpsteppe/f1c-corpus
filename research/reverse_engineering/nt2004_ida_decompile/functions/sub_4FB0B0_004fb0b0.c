void sub_4FB0B0()
{
  int v0; // esi
  double v1; // st7
  int v2; // [esp+0h] [ebp-10h]
  float v3; // [esp+Ch] [ebp-4h]

  if ( sub_463490(dword_764D70) )
  {
    if ( dbl_7DA9D0 < 31.0 )
      return;
    v3 = 1.5;
  }
  else
  {
    v3 = 3.0;
  }
  v0 = dword_7D3C44;
  if ( dword_79FC40 < 1023 )
  {
    ++dword_79FC40;
    dword_7D3C44 += 208;
  }
  *(float *)&v2 = dbl_7DA9D0;
  sub_4D0D00((_DWORD *)v0, 4, 20, 8, 63, v2, 3);
  *(float *)(v0 + 8) = dbl_7DA9D0 + v3;
  v1 = flt_7D3C54[(unsigned __int8)dword_7D3C50++];
  *(float *)(v0 + 12) = dbl_7DA9D0 + v3 + v1 + v1 + 1.0;
}
