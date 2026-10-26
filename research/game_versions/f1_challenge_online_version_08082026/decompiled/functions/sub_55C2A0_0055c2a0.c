int __thiscall sub_55C2A0(_DWORD *this, int a2)
{
  int v2; // eax
  int result; // eax
  int v4; // ecx
  int i; // eax

  v2 = this[1350];
  if ( v2 )
  {
    v4 = this[1350];
    for ( i = *(_DWORD *)(v2 + 32); i; i = *(_DWORD *)(i + 32) )
      v4 = i;
    result = a2;
    *(_DWORD *)(a2 + 28) = v4;
    *(_DWORD *)(v4 + 32) = a2;
  }
  else
  {
    result = a2;
    this[1350] = a2;
  }
  return result;
}
