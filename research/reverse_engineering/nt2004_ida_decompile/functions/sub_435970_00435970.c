int __stdcall sub_435970(_DWORD *ArgList)
{
  int result; // eax
  char v2; // [esp-10h] [ebp-18h]
  char v3; // [esp-Ch] [ebp-14h]

  result = 1;
  if ( ArgList )
  {
    if ( *ArgList )
    {
      sub_57A400((int)ArgList, aS_5, (char)off_5FE060);
      sub_57A400((int)ArgList, asc_5FC03C, v3);
      sub_57A400((int)ArgList, aSS_1, (char)off_5FE064);
      sub_57A400((int)ArgList, aSS_1, (char)off_5FE068);
      sub_57A400((int)ArgList, aSD, (char)off_5FE06C);
      sub_57A400((int)ArgList, aSS_1, (char)off_5FE070);
      sub_57A400((int)ArgList, asc_5FE16C, v2);
      return 0;
    }
  }
  return result;
}
