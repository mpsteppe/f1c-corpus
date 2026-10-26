char __thiscall sub_40B410(_DWORD *this, int a2)
{
  char result; // al
  int v3; // esi
  int v4; // edx
  int i; // ecx

  result = 0;
  if ( a2 )
  {
    v3 = this[4];
    v4 = 0;
    if ( v3 > 0 )
    {
      for ( i = this[3]; i != a2; i += 160 )
      {
        if ( ++v4 >= v3 )
          return result;
      }
      return 1;
    }
  }
  return result;
}

