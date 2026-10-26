int __thiscall sub_500D60(int *this, int ArgList)
{
  if ( ArgList >= 0 && ArgList < *this )
    return this[1] + 36 * ArgList;
  if ( dword_75CBA8 != 5 )
  {
    if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_22, 1174) )
      sub_500FE0((int)&unk_7D7920, aNonExistentTir, ArgList);
  }
  return 0;
}
