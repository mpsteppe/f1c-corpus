char __thiscall sub_463BC0(void *this)
{
  char result; // al

  result = 0;
  if ( *(_BYTE *)(*(_DWORD *)this + 197) )
  {
    dword_7D0410 = 5;
    if ( dword_7D0418 <= 5 )
    {
      if ( dword_7D041C < 5 )
        dword_7D0410 = dword_7D041C;
    }
    else
    {
      dword_7D0410 = dword_7D0418;
    }
    byte_7D0F94 = 1;
    SingleFunctionCallWrapper_a920(*(_DWORD *)(*(_DWORD *)this + 16312));
    if ( sub_463C60(this) )
      LookupDispatch(aSelectcircuitp, -1);
    else
      LookupDispatch(aMultiplayerCre, -1);
    return 1;
  }
  return result;
}
