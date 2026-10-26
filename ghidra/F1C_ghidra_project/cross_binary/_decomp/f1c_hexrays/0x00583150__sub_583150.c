// f1c  0x00583150  size=84
_DWORD *__thiscall sub_583150(_DWORD *this, char a2)
{
  if ( (a2 & 2) != 0 )
  {
    sub_58A5F7(this, 40, *(this - 1), sub_57AEF0);
    if ( (a2 & 1) != 0 )
      sub_587BCF(this - 1);
    return this - 1;
  }
  else
  {
    sub_57AEF0(this);
    if ( (a2 & 1) != 0 )
      sub_587BCF(this);
    return this;
  }
}
