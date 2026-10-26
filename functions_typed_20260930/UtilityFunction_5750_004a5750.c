int __thiscall sub_4A5750(_DWORD *this, int a2)
{
  int result; // eax
  int v4; // edx
  int v5; // ecx
  int v6; // ecx

  if ( a2 == 2 )
    FindZeroResultIndex(this);
  result = (int)&this[16 * a2];
  v4 = *(_DWORD *)(result + 44) + 1;
  *(_DWORD *)(result + 44) = v4;
  v5 = *(_DWORD *)(result + 40);
  if ( v4 >= v5 )
  {
    if ( *(_BYTE *)(result + 53) )
      v6 = 0;
    else
      v6 = v5 - 1;
    *(_DWORD *)(result + 44) = v6;
  }
  if ( !a2 )
    return ConditionalDispatch_55e0(this);
  return result;
}

