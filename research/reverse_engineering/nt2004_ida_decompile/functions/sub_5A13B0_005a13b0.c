void __thiscall sub_5A13B0(_DWORD *this)
{
  if ( (*this & 1) != 0 || (*this & 2) != 0 )
  {
    if ( this[6] )
      sub_5BE8AE();
    this[6] = 0;
  }
  if ( this[5] )
  {
    sub_5A7FD0(this[5]);
    if ( this[5] )
      sub_5BE8AE();
    this[5] = 0;
  }
  nullsub_6(this);
}
