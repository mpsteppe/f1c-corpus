int sub_58FF65()
{
  char *v0; // eax
  int result; // eax

  dword_8D3FA4 = sub_58E1B0((_DWORD *)dword_8D3FA8) == (char *)3;
  v0 = sub_58E1B0((_DWORD *)dword_8D3FAC);
  Locale = 0;
  dword_8D3F9C = v0 == (char *)3;
  if ( dword_8D3FA4 )
    dword_8D3FA0 = 2;
  else
    dword_8D3FA0 = sub_590616(dword_8D3FA8);
  EnumSystemLocalesA(LocaleEnumProc, 1u);
  result = dword_8D3FB0;
  if ( (dword_8D3FB0 & 0x100) == 0 || (dword_8D3FB0 & 0x200) == 0 || (dword_8D3FB0 & 7) == 0 )
    dword_8D3FB0 = 0;
  return result;
}
