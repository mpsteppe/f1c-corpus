char __thiscall sub_52B190(_DWORD *this, char a2)
{
  char result; // al
  bool v3; // zf

  result = a2;
  if ( a2 )
  {
    v3 = *(_BYTE *)this == 0;
    *(_BYTE *)this = a2;
    if ( v3 )
      this[1] = 0;
  }
  else
  {
    *(_BYTE *)this = 0;
  }
  return result;
}
