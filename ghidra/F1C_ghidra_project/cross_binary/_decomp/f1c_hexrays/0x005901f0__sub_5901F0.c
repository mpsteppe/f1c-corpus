// f1c  0x005901f0  size=86
BOOL sub_5901F0()
{
  char *v0; // eax
  BOOL result; // eax

  v0 = sub_58E1B0((_DWORD *)dword_8D3FA8);
  dword_8D3FA4 = v0 == (char *)3;
  if ( v0 == (char *)3 )
    dword_8D3FA0 = 2;
  else
    dword_8D3FA0 = sub_590616(dword_8D3FA8);
  result = EnumSystemLocalesA(sub_590246, 1u);
  if ( (dword_8D3FB0 & 4) == 0 )
    dword_8D3FB0 = 0;
  return result;
}
