int __thiscall sub_42A110(_DWORD *this)
{
  int result; // eax

  if ( dword_7C56A4 == 7 )
  {
    result = dword_8ACF8C - 1;
    if ( this[4111] != dword_8ACF8C - 1 )
    {
      result = TeammatePartValueLookup(this + 3251);
      if ( !result || result == 4 || this[4121] == 1 )
      {
        StateConditionalAction(this + 3251);
        return AIStateFlagSetter(1);
      }
    }
  }
  else
  {
    StateConditionalAction(this + 3251);
    return AIStateFlagSetter(1);
  }
  return result;
}
