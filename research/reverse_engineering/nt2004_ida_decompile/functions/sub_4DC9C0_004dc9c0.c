int __thiscall sub_4DC9C0(int *this, char a2)
{
  int v3; // esi
  int v5; // [esp+0h] [ebp-10h]

  v3 = dword_7D3C44;
  if ( dword_79FC40 < 1023 )
  {
    ++dword_79FC40;
    dword_7D3C44 += 208;
  }
  *(float *)&v5 = dbl_7DA9D0;
  sub_4D0D00((_DWORD *)v3, 4, 24, 1, this[1], v5, 0);
  *(_BYTE *)(v3 + 8) = a2;
  return this[19];
}
