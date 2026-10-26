int __thiscall sub_4602E0(_DWORD *this, _DWORD *a2, int a3)
{
  int result; // eax

  if ( *a2 )
  {
    result = *a2 - 1;
    if ( *a2 == 1 )
    {
      result = sub_45F910();
      if ( result )
        return sub_45F4D0();
    }
  }
  else
  {
    result = a2[1];
    *this = 0;
    byte_B698EC[this[1]] = 0;
    this[1] = result;
    this[2] = a3;
    byte_B698EC[result] = a3;
    this[8] = 0;
    this[7] = 0;
  }
  return result;
}
