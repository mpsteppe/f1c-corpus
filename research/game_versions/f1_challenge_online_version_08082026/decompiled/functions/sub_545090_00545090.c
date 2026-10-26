int __thiscall sub_545090(_DWORD *this, int a2)
{
  int result; // eax
  int v3; // edx
  int v4; // edx

  result = a2;
  v3 = *(_DWORD *)(a2 + 436);
  if ( v3 )
    *(_DWORD *)(v3 + 440) = *(_DWORD *)(a2 + 440);
  v4 = *(_DWORD *)(a2 + 440);
  if ( v4 )
    *(_DWORD *)(v4 + 436) = *(_DWORD *)(a2 + 436);
  if ( this[62] == a2 )
  {
    result = *(_DWORD *)(a2 + 440);
    this[62] = result;
  }
  return result;
}
