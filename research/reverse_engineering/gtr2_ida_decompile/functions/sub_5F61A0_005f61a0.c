int __stdcall sub_5F61A0(char **a1, const char *ArgList)
{
  _DWORD *v2; // eax
  char *v3; // esi
  int result; // eax

  v2 = operator new(0xDCu);
  if ( v2 )
  {
    v3 = (char *)(v2 + 1);
    *v2 = 1;
    sub_630A11(v2 + 1, 216, 1, sub_5E2AC0, j_j_nullsub_7);
  }
  else
  {
    v3 = 0;
  }
  sub_5E2E70(v3, ArgList, 512, 512, 8, 1, 524364, 2);
  *((_DWORD *)v3 + 52) = 0;
  *((_DWORD *)v3 + 53) = 1;
  result = sub_5FDFB0(v3, 0);
  *a1 = v3;
  return result;
}
