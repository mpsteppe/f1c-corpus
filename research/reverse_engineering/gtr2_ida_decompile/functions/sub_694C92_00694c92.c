int __thiscall sub_694C92(_DWORD *this, int a2)
{
  if ( !a2 )
  {
    if ( !this[16] )
      sub_694C3A(this, 0, 0, "internal error: production failed!");
    this[16] = 1;
    this[17] = 1;
  }
  return a2;
}
