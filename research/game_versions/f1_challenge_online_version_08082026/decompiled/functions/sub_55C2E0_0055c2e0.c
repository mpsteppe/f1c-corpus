int __thiscall sub_55C2E0(_DWORD *this, int a2)
{
  int result; // eax
  int v3; // edx
  int v4; // edx

  result = this[1350];
  if ( result )
  {
    while ( result != a2 )
    {
      result = *(_DWORD *)(result + 32);
      if ( !result )
        return result;
    }
    v3 = *(_DWORD *)(result + 28);
    if ( v3 )
      *(_DWORD *)(v3 + 32) = *(_DWORD *)(result + 32);
    v4 = *(_DWORD *)(result + 32);
    if ( v4 )
      *(_DWORD *)(v4 + 28) = *(_DWORD *)(result + 28);
    if ( this[1350] == result )
    {
      result = *(_DWORD *)(result + 32);
      this[1350] = result;
    }
  }
  return result;
}
