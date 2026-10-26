int __stdcall sub_4FAF30(int a1, int a2)
{
  _DWORD *v2; // esi
  int result; // eax
  int v4; // [esp+0h] [ebp-Ch]

  v2 = (_DWORD *)dword_7D3C44;
  if ( dword_79FC40 < 1023 )
  {
    ++dword_79FC40;
    dword_7D3C44 += 208;
  }
  *(float *)&v4 = dbl_7DA9D0;
  sub_4D0D00(v2, 4, 21, 8, 63, v4, 3);
  result = a1;
  v2[2] = a1;
  v2[3] = a2;
  return result;
}
