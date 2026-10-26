int __thiscall sub_4A57A0(_DWORD *this, int a2)
{
  int result; // eax
  int v4; // ecx
  int v5; // ecx

  if ( a2 == 2 )
    FindZeroResultIndex(this);
  result = (int)&this[16 * a2];
  v4 = *(_DWORD *)(result + 44) - 1;
  *(_DWORD *)(result + 44) = v4;
  if ( v4 < 0 )
  {
    if ( *(_BYTE *)(result + 53) )
      v5 = *(_DWORD *)(result + 40) - 1;
    else
      v5 = 0;
    *(_DWORD *)(result + 44) = v5;
  }
  if ( !a2 )
    return ConditionalDispatch_55e0(this);
  return result;
}
