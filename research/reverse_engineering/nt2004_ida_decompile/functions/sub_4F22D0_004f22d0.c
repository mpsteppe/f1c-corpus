int __fastcall sub_4F22D0(const char *ArgList)
{
  if ( _strcmpi(ArgList, aZero) )
  {
    if ( !_strcmpi(ArgList, aOne) )
      return 2;
    if ( !_strcmpi(ArgList, aSrccolor) )
      return 3;
    if ( !_strcmpi(ArgList, aInvsrccolor) )
      return 4;
    if ( !_strcmpi(ArgList, aSrcalpha) )
      return 5;
    if ( !_strcmpi(ArgList, aInvsrcalpha) )
      return 6;
    if ( !_strcmpi(ArgList, aDstcolor) )
      return 9;
    if ( !_strcmpi(ArgList, aInvdstcolor) )
      return 10;
    if ( !_strcmpi(ArgList, aDstalpha) )
      return 7;
    if ( !_strcmpi(ArgList, aInvdstalpha) )
      return 8;
    if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_20, 172) )
      sub_500FE0((int)&unk_7D7920, aUnknownBlendMo, (char)ArgList);
  }
  return 1;
}
