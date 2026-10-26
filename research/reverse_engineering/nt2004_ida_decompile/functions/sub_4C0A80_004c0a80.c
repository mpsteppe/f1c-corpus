void __thiscall sub_4C0A80(_DWORD *this, int a2)
{
  if ( (unsigned __int8)sub_4EED40(*this) )
  {
    sub_4BEB60(dword_766238, a2, 0);
    if ( a2 != this[2] )
      sub_4BECA0(dword_766238, 3);
    this[2] = a2;
  }
  else
  {
    this[2] = a2;
  }
}
