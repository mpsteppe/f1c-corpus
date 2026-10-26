// f1c  0x0058af5c  size=115
_DWORD *__cdecl sub_58AF5C(unsigned int a1)
{
  int v1; // esi
  _DWORD *v2; // eax
  _DWORD *result; // eax

  v1 = 0;
  *(_DWORD *)sub_58AFD8() = a1;
  v2 = &unk_5E65C0;
  do
  {
    if ( a1 == *v2 )
    {
      result = (_DWORD *)sub_58AFCF();
      *result = dword_5E65C4[2 * v1];
      return result;
    }
    v2 += 2;
    ++v1;
  }
  while ( (int)v2 < (int)dword_5E6728 );
  if ( a1 < 0x13 || a1 > 0x24 )
  {
    if ( a1 < 0xBC || a1 > 0xCA )
    {
      result = (_DWORD *)sub_58AFCF();
      *result = 22;
    }
    else
    {
      result = (_DWORD *)sub_58AFCF();
      *result = 8;
    }
  }
  else
  {
    result = (_DWORD *)sub_58AFCF();
    *result = 13;
  }
  return result;
}
