int __thiscall sub_4A5090(_BYTE **this)
{
  _BYTE *v1; // edx

  *this[69] = *this[69] == 0;
  v1 = *this;
  if ( *this[69] )
    this[67] = 0;
  else
    this[67] = (_BYTE *)1;
  (*((void (__stdcall **)(_BYTE *))v1 + 11))(this[67]);
  return 0;
}
