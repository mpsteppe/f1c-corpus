char __thiscall VTableCallWithFlagCheck(_BYTE *this)
{
  char result; // al
  int v2; // ecx

  result = this[8];
  if ( result )
  {
    v2 = *(_DWORD *)this;
    if ( v2 )
      return (*(int (__thiscall **)(int, int))(*(_DWORD *)v2 + 4))(v2, 1);
  }
  return result;
}

