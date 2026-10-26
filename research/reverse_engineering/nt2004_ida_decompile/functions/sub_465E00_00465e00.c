int __thiscall sub_465E00(int *this)
{
  int result; // eax

  result = *this;
  if ( *(_DWORD *)(*this + 440) != 1 )
    *(_DWORD *)(result + 6720) = 0;
  if ( !byte_766188 )
  {
    if ( *(_DWORD *)dword_7689CC == 5 )
    {
      dword_769158 = 0;
      if ( dword_769160 <= 0 )
      {
        if ( dword_769164 < 0 )
          dword_769158 = dword_769164;
      }
      else
      {
        dword_769158 = dword_769160;
      }
      result = dword_7690AC;
      dword_7690A4 = 0;
      if ( dword_7690AC <= 0 )
      {
        if ( dword_7690B0 < 0 )
          dword_7690A4 = dword_7690B0;
      }
      else
      {
        dword_7690A4 = dword_7690AC;
      }
    }
    else
    {
      result = *this;
      *(_DWORD *)(*this + 6720) = 0;
    }
  }
  return result;
}
