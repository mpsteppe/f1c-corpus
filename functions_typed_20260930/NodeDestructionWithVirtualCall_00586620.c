char __thiscall sub_586620(_BYTE *this)
{
  char result; // al
  int (__thiscall ***v2)(_DWORD, int); // ecx

  result = this[8];
  if ( result )
  {
    v2 = *(int (__thiscall ****)(_DWORD, int))this;
    if ( v2 )
      return (**v2)(v2, 1);
  }
  return result;
}

