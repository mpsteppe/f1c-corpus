// f1c  0x00463ef0  size=125
int __thiscall sub_463EF0(int *this)
{
  int result; // eax

  result = *this;
  if ( *(_DWORD *)(*this + 464) != 1 )
    *(_DWORD *)(result + 16324) = 0;
  if ( !byte_7CE260 )
  {
    if ( dword_7D0410 == 5 )
    {
      dword_7D0A44 = 0;
      if ( dword_7D0A4C <= 0 )
      {
        if ( dword_7D0A50 < 0 )
          dword_7D0A44 = dword_7D0A50;
      }
      else
      {
        dword_7D0A44 = dword_7D0A4C;
      }
      result = dword_7D0998;
      dword_7D0990 = 0;
      if ( dword_7D0998 <= 0 )
      {
        if ( dword_7D099C < 0 )
          dword_7D0990 = dword_7D099C;
      }
      else
      {
        dword_7D0990 = dword_7D0998;
      }
    }
    else
    {
      result = *this;
      *(_DWORD *)(*this + 16324) = 0;
    }
  }
  return result;
}
