int __stdcall sub_65ED28(int a1, int a2, __int16 a3, int a4, const char *ArgList, _DWORD **a6)
{
  switch ( a3 )
  {
    case 1:
      goto LABEL_6;
    case 2:
LABEL_5:
      sub_65DD1F(*a6, (int)a6[12], a4 + 5000, "%s", ArgList);
      a6[19] = (_DWORD *)1;
      return 0;
    case 5:
LABEL_6:
      sub_65DDE6(*a6, (int)a6[12], (const char *)(a4 + 5000), "%s", ArgList);
      return 0;
    case 6:
      goto LABEL_5;
  }
  return 0;
}
