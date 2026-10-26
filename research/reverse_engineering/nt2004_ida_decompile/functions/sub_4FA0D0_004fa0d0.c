char sub_4FA0D0()
{
  char result; // al
  _DWORD *v1; // ecx
  int v2; // [esp+0h] [ebp-8h]

  result = sub_4BA430();
  if ( result )
  {
    if ( dword_79FC40 >= 1023 )
    {
      v1 = (_DWORD *)dword_7D3C44;
    }
    else
    {
      ++dword_79FC40;
      v1 = (_DWORD *)dword_7D3C44;
      dword_7D3C44 += 208;
    }
    *(float *)&v2 = dbl_7DA9D0;
    return sub_4D0D00(v1, 2, 9, 1, 63, v2, 0);
  }
  return result;
}
