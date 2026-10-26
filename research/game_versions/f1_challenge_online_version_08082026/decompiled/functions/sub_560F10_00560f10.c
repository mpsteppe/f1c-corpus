int __thiscall sub_560F10(_DWORD *this, int a2)
{
  int result; // eax
  int v3; // edx
  int v4; // edx

  result = a2;
  v3 = *(_DWORD *)(a2 + 48);
  if ( v3 )
    *(_DWORD *)(v3 + 52) = *(_DWORD *)(a2 + 52);
  v4 = *(_DWORD *)(a2 + 52);
  if ( v4 )
    *(_DWORD *)(v4 + 48) = *(_DWORD *)(a2 + 48);
  if ( this[11] == a2 )
  {
    result = *(_DWORD *)(a2 + 52);
    this[11] = result;
  }
  return result;
}
