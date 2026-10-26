int __thiscall sub_54C1B0(_DWORD *this, int a2, int a3, int a4)
{
  int result; // eax

  if ( this[17] && a3 )
    result = UIWidgetRecursiveStateUpdate(a2, a3, 1);
  if ( this[19] && (a3 & a4) != 0 )
    result = UIWidgetRecursiveStateUpdate(a2, a3, 1);
  if ( this[140] )
  {
    if ( a2 )
      return Bit1FlagSet();
    else
      return StateFlagBitClear();
  }
  return result;
}
