BOOL sub_590303()
{
  BOOL result; // eax

  dword_8D3F9C = Strlen((_DWORD *)dword_8D3FAC) == (char *)3;
  result = EnumSystemLocalesA(sub_59033A, 1u);
  if ( (dword_8D3FB0 & 4) == 0 )
    dword_8D3FB0 = 0;
  return result;
}

