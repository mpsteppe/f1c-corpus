BOOL sub_5901F0()
{
  char *v0; // eax
  BOOL result; // eax

  v0 = Strlen((_DWORD *)dword_8D3FA8);
  dword_8D3FA4 = v0 == (char *)3;
  if ( v0 == (char *)3 )
    dword_8D3FA0 = 2;
  else
    dword_8D3FA0 = CountAlphabeticalChars(dword_8D3FA8);
  result = EnumSystemLocalesA(sub_590246, 1u);
  if ( (dword_8D3FB0 & 4) == 0 )
    dword_8D3FB0 = 0;
  return result;
}

