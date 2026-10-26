// f1c  0x004bc240  size=35
int __thiscall sub_4BC240(_DWORD *this)
{
  int result; // eax

  if ( dword_7C56A4 != 7 )
  {
    result = *this;
    if ( *(_BYTE *)(*this + 13388) )
    {
      if ( this[24] == 2 )
        this[24] = 1;
    }
  }
  return result;
}
