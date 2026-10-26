int __thiscall sub_429EE0(_DWORD *this)
{
  int result; // eax

  if ( dword_7C56A8 == 3 )
  {
    SessionCleanupFlagClear(this);
    this[4433] = 0;
    WrapPlayerCallback(this);
  }
  if ( dword_7C56A4 != 7 && PairArrayLinearSearch(this, 0) )
  {
    this[4433] = 0;
    ParameterValueSetter(18);
    this[4420] = 5;
    AISpeedDeltaSetter(1);
  }
  if ( PairArrayLinearSearch(this, 5) )
  {
    ParameterValueSetter(99999);
    this[4433] = 1;
  }
  if ( PairArrayLinearSearch(this, 4) )
  {
    this[4367] = 1;
    ParameterValueSetter(18);
  }
  result = PairArrayLinearSearch(this, 14);
  if ( result )
  {
    this[4433] = 0;
    this[4367] = 1;
  }
  if ( dword_7C56A8 == 4 )
  {
    AISpeedDeltaSetter(0);
    result = ParameterValueSetter(99999);
    this[4433] = 1;
  }
  return result;
}
