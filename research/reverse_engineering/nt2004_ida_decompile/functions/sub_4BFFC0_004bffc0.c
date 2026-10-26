int __thiscall sub_4BFFC0(char *String1)
{
  if ( !_strcmpi(String1, aHardCompound) )
    return 2;
  if ( !_strcmpi(String1, aSoftCompound) )
    return 3;
  if ( !_strcmpi(String1, aIntermediateCo) )
    return 4;
  if ( !_strcmpi(String1, aWetCompound) || !_strcmpi(String1, off_60A230) )
    return 5;
  if ( !_strcmpi(String1, aMonsoonCompoun) )
    return 6;
  if ( _strcmpi(String1, aDryCompound) && _strcmpi(String1, off_60A208) )
    return 1;
  return 7;
}
