int __thiscall sub_5A32F0(_DWORD *this)
{
  if ( (this[25] & 0x20000) != 0 )
  {
    sub_5A7FD0(this[4]);
    if ( this[4] )
      sub_5BE8AE();
    this[4] = 0;
  }
  return 0;
}
