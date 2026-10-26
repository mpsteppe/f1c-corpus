int __thiscall sub_4D1AD0(_DWORD *this, int a2)
{
  int v3; // esi
  int v4; // edi
  int result; // eax
  int *i; // edx
  int v7; // ecx

  v3 = ShortComputation_7bf0(a2);
  v4 = ArrayAccessAt0xcIndex4(a2);
  result = 0;
  if ( v3 <= v4 )
  {
    for ( i = (int *)(this[68] + 8 * v3); ; i += 2 )
    {
      v7 = *i;
      if ( v7 == 3 )
        break;
      if ( result != 8 )
      {
        if ( v7 == 8 )
        {
          result = 8;
        }
        else if ( result != 2 && v7 == 2 )
        {
          result = 2;
        }
      }
      if ( ++v3 > v4 )
        return result;
    }
    return 3;
  }
  return result;
}

