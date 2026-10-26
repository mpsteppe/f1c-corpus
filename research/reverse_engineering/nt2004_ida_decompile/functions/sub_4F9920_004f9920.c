int __thiscall sub_4F9920(void *this, int a2, int a3)
{
  int v4; // esi
  char v5; // dl
  int v7; // [esp+0h] [ebp-10h]

  v4 = dword_7D3C44;
  if ( dword_79FC40 < 1023 )
  {
    ++dword_79FC40;
    dword_7D3C44 += 208;
  }
  *(float *)&v7 = dbl_7DA9D0;
  sub_4D0D00((_DWORD *)v4, 4, 22, 2, 63, v7, 3);
  *(_BYTE *)(v4 + 8) = a2;
  if ( a3 < 0 )
  {
    *(_BYTE *)(v4 + 9) = -1;
    return sub_4F99C0(this, a2, *(char *)(v4 + 9));
  }
  else
  {
    v5 = *(_BYTE *)(dword_75AAD0[a3] + 25248);
    *(_BYTE *)(v4 + 9) = v5;
    return sub_4F99C0(this, a2, v5);
  }
}
