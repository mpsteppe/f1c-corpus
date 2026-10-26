char __thiscall sub_40A890(_DWORD *this, int a2)
{
  char result; // al
  int v3; // edi
  int v4; // edx
  int i; // ecx

  result = 0;
  if ( !a2
    || a2 != this[4]
    && a2 != this[5]
    && a2 != this[6]
    && a2 != this[7]
    && a2 != this[9]
    && a2 != this[10]
    && a2 != this[11]
    && a2 != this[12] )
  {
    v3 = this[14];
    v4 = 0;
    if ( v3 <= 0 )
      return result;
    for ( i = this[8]; i != a2; i += 200 )
    {
      if ( ++v4 >= v3 )
        return result;
    }
  }
  return 1;
}

