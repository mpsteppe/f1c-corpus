int __thiscall sub_4EED90(int this)
{
  int result; // eax

  if ( *(_DWORD *)(this + 16584) == 2 )
  {
    if ( sub_463DC0(dword_764D70, *(_DWORD *)(this + 25248), 2.0) )
      return 0;
    else
      return *(_DWORD *)(this + 25272);
  }
  else if ( !sub_4EED40((_DWORD *)this) || (result = sub_4BAA00()) == 0 )
  {
    if ( (*(_DWORD *)(this + 25296) & 2) != 0 )
    {
      if ( *(float *)(this + 18820) * 9.5492964 > 0.0 )
        return *(_DWORD *)(this + 24244) != 0 ? 7 : 4;
      else
        return 6;
    }
    else
    {
      return 5;
    }
  }
  return result;
}
