int __thiscall sub_429EB0(_DWORD *this)
{
  int result; // eax

  result = FuelMultiplierValue(this);
  if ( result < 1 )
  {
    result = this[4436];
    if ( !result && dword_7C56A8 == 5 )
      return ForcePitExit(this);
  }
  return result;
}
