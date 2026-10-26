int __thiscall sub_4A5660(_DWORD *this, char a2)
{
  if ( a2 )
  {
    if ( this[10] != 2 )
    {
      this[10] = 2;
      this[11] = 1;
      this[12] = 1;
      return sub_4A55E0(this);
    }
  }
  else
  {
    this[10] = 1;
    this[11] = 0;
    this[12] = 0;
  }
  return sub_4A55E0(this);
}
