char __thiscall sub_48AF00(int this)
{
  char result; // al

  byte_7654A8 = 0;
  sub_48AB00((_DWORD *)this);
  result = dword_769848;
  if ( !dword_769848 )
  {
    result = byte_769980;
    if ( byte_769980 )
    {
      result = *(_BYTE *)(this + 424);
      if ( !result )
      {
        result = sub_463560(dword_764D70);
        *(_BYTE *)(this + 424) = 1;
      }
    }
  }
  return result;
}
