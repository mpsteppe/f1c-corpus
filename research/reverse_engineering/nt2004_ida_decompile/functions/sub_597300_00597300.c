int __thiscall sub_597300(_DWORD *this, int a2)
{
  int result; // eax
  int v3; // edx
  int v4; // edx

  result = a2;
  v3 = *(_DWORD *)(a2 + 628);
  if ( v3 )
    *(_DWORD *)(v3 + 632) = *(_DWORD *)(a2 + 632);
  v4 = *(_DWORD *)(a2 + 632);
  if ( v4 )
    *(_DWORD *)(v4 + 628) = *(_DWORD *)(a2 + 628);
  if ( this[63] == a2 )
  {
    result = *(_DWORD *)(a2 + 632);
    this[63] = result;
  }
  return result;
}
